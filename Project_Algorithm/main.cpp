
#include "Fasta_To_Bits.hpp"
#include "Score.hpp"
#include "ouverture.hpp"
#include "comparaison.hpp"
#include "SwipeAlgo.hpp"
#include "binaire.h"
#include "Sequence.hpp"
#include "Offsets.hpp"
#include "header.h"
#include <map>
#include <iterator>
#include <thread>
#include <future>


int main(int argc, const char * argv[]) {
    if(argc<3){
        cout << "Argument demandé :" << argv[0]<<" [fichier unisprot] [fichier fasta] optionnel: [fichier matrice blosum] [Gap open penality] [Gap penality extension]  "<<endl;
        cout << "Attention, si vous voulez definir un gap ou extension penality, les deux DOIVENT etre definit. "<<endl;
        return 1;
    }

    string chemin_unisprot1 = argv[1];
    chemin_unisprot1.append(".psq");
    cout << chemin_unisprot1 << endl;
    string chemin_unisprot3 = argv[1];
    chemin_unisprot3.append(".phr");
    cout << chemin_unisprot3 << endl;
    string chemin_unisprot2 = argv[1];
    chemin_unisprot2.append(".pin");
    cout << chemin_unisprot2 << endl;
    
    Sequence sequence(chemin_unisprot1);
    Offsets offsets(chemin_unisprot2);
    Header head(chemin_unisprot3);
    
    string chemin_fasta = argv[2];
    ifstream input(chemin_fasta);
    
    Swipe swipe;
    
    string fasta = Fasta_To_String(input);
    sequence.read_psq();
    offsets.offset();
    
    string matrice;
    if (argc>=4) {
        swipe.initialise_blosum(argv[3]);
        matrice = argv[3];
    }
    else{
        swipe.initialise_blosum();
        matrice = "blossum62";
    }
    
    int gap_penality = 0;
    int extension_penality = 0;
    
    if (argc>=6) {
        gap_penality = atoi(argv[4]);
        extension_penality = atoi(argv[5]);
    }
    else{
        gap_penality = 11;
        extension_penality = 1;
    }
    
    
    map<double, int> score_max;//TODO: j ai quand meme envie de changer map en vector
    int score = 0;
    const char* seq = sequence.get_sequence2();
    
    
    
    cout << endl;
    cout << "[+] Lancement swipe" << endl;
    double tempsmoyen = 0.0;
    chrono::time_point<chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    int init= 116000;
    int fin = 124000;
    //int med = init+(fin-init)/2;
    //int score2=0;
    //int size = offsets.get_size();
    for (int g = init; g<fin; g++) {//offsets.get_size()//119500
        int h = offsets.get_seq_offset(g-1);
        int u = offsets.get_seq_offset(g);
        chrono::time_point<chrono::system_clock> start2, end2;
        start2 = std::chrono::system_clock::now();
        
        //int f = offsets.get_seq_offset(3500+g);
        //int d = offsets.get_seq_offset(3500+g-1);
        //future<int> fut = async(launch::async, &Swipe::Algo, &swipe, fasta, seq, h, u);
        //future<int> fut = async(launch::async, [&]{ return swipe.Algo(fasta, seq, h, u);});
        //future<int> fut2 = async(launch::async, [&]{ return swipe.Algo(fasta, seq, f, d);});
        /*
        std::promise<int> p;
        auto f = p.get_future();
         */
        /*
        thread t1(&Swipe::Algo, swipe, fasta, seq, h, u, &score2);
        thread t2(&Swipe::Algo, swipe, fasta, seq, f, d, &score2);
        t1.join();
        t2.join();
         */
        //thread t1([&] {score = swipe.Algo(fasta, seq, h, u);});
        //thread t2([&] {score2 = swipe.Algo(fasta, seq, f, d);});
        score = swipe.Algo(fasta, seq, h, u, gap_penality, extension_penality);
        //score = fut.get();
        //score2 = fut2.get();
        
        
        if(score_max.size() < 20){
            score_max.insert(pair<double, int>(score,g));
            //score_max.insert(pair<double, int>(score2,3500+g));
        }
        else if(score_max.size() == 20 && score_max.begin()->first < score){
            score_max.erase(score_max.begin());
            score_max.insert(pair<double, int>(score,g));
        }
        
        end2 = std::chrono::system_clock::now();
        double elapsed_seconds2 = chrono::duration_cast<chrono::milliseconds>(end2-start2).count();
        //cout << "elapsed time: " << elapsed_seconds2 << "ms\n";
        tempsmoyen += elapsed_seconds2;
        if(g%1000 == 0 ){
            cout<<g-1<<endl;
        }
    }
    end = std::chrono::system_clock::now();
    double elapsed_seconds = chrono::duration_cast<chrono::seconds>(end-start).count();
    cout << "Elapsed time: " << elapsed_seconds << "s\n";
    cout << "Average time per sequence: " << tempsmoyen/(fin-init) << "ms" << endl;
    
    
    map<double,int>::iterator itr;
    int off=0;
    head.open_fichier();
    
    auto timenow =chrono::system_clock::to_time_t(chrono::system_clock::now());
    ofstream result("resultat.txt", ios::app);
    result<<"Matrix used : "<<matrice<<endl;
    result<<"Gap penalty : "<<gap_penality<<" \nExtension penalty : "<<extension_penality<<"\n"<<endl;
    result << "Smith-Waterman Algorithm " << ctime(&timenow) << endl;
    result << endl;

    result << "Elapsed time: " << elapsed_seconds << "s" << endl;
    result << "Average time per sequence: " << tempsmoyen/(fin-init) << "s" << endl; //TODO: a changer ici
    result << endl;
    
    result << "Sequence producing significant alignements, classed with increasing score :" << endl;
    result <<endl;
    
    for(itr = score_max.begin(); itr != score_max.end(); ++itr){
        off = offsets.get_head_offset((int)((itr)->second - 1));
        head.acquiert(off);
        head.getData(&result);
        result<<itr->first<<"\n"<<endl;
        
    }
    swipe.free_blosum();
    sequence.del();
    head.close_fichier();
    result.close();
    cout << endl;
    cout << "[+] Fichier resultat.txt créé dans le dossier dans lequel vous etes" << endl; //TODO: changer 
    return 0;
}
