
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
    if(argc<3 || argc>6){
        cout << "Argument demandé :" << argv[0]<<" [fichier unisprot] [fichier fasta] optionnel: [fichier matrice blosum] [Gap open penality] [Gap penality extension]  "<<endl;
        cout << "Attention, si vous voulez definir un gap ou extension penality, les deux DOIVENT etre definit. "<<endl;
        return 1;
    }
    
    
    string chemin_unisprot1 = argv[1];
    chemin_unisprot1.append(".psq");
    string chemin_unisprot3 = argv[1];
    chemin_unisprot3.append(".phr");
    string chemin_unisprot2 = argv[1];
    chemin_unisprot2.append(".pin");
    //On construit les objets qui correspondent à chacun des fichiers
    //en utilisant les adresses
    Sequence sequence(chemin_unisprot1);
    Offsets offsets(chemin_unisprot2);
    Header head(chemin_unisprot3);
    
    string chemin_fasta = argv[2];
    ifstream input(chemin_fasta);
    //on crée l'objet de l'algorithme
    Swipe swipe;
    
    string fasta = Fasta_To_String(input);
    //on crée la liste qui contient les séquences de la base de donnée
    sequence.read_psq();
    //on répertorie les offset dans le header et dans le fichier de séquences dans 2 listes
    offsets.offset();
    
    string matrice;
    int gap_penality = 0;
    int extension_penality = 0;
    //on gère les arguments optionnels
    if (argc==4) {
        swipe.initialise_blosum(argv[3]);
        matrice = argv[3];
        gap_penality = 11;
        extension_penality = 1;
    }
    else if(argc == 5){
        swipe.initialise_blosum();
        matrice = "blosum62";
        gap_penality = atoi(argv[3]);
        extension_penality = atoi(argv[4]);
    }
    else if (argc==6) {
        swipe.initialise_blosum(argv[3]);
        matrice = argv[3];
        gap_penality = atoi(argv[4]);
        extension_penality = atoi(argv[5]);
    }
    else if(argc == 3){
        swipe.initialise_blosum();
        matrice = "blosum62";
        gap_penality = 11;
        extension_penality = 1;
    }
    
    //permet de stocker les meilleurs scores
    map<double, int> score_max;
    int score = 0;
    const char* seq = sequence.get_sequence2();
    
    
    
    cout << endl;
    cout << "[+] Lancement swipe" << endl;
    double tempsmoyen = 0.0;
    chrono::time_point<chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    
    long size = offsets.get_size();
    for (int g = 1; g<size; g++) {
        int h = offsets.get_seq_offset(g-1);
        int u = offsets.get_seq_offset(g);
        chrono::time_point<chrono::system_clock> start2, end2;
        start2 = std::chrono::system_clock::now();
        
        score = swipe.Algo(fasta, seq, h, u, gap_penality, extension_penality);
    //test de parallélisme, nous avons laissé cette partie non terminée en commentaire de manière intentionnelle pour indiquer que nous avons essayer d'utiliser le multithreading mais etant donné que nous n'avons pas sut le faire fonctionner, nous voulions savoir ou etait nos erreurs
    
        
        /*
    thread t1(
              [&offsets, &extension_penality, &gap_penality, &fasta, &seq, &tempsmoyen](Swipe &swipe) {
        int init= 116000;
        int fin = 124000;
        map<double, int> score_max;
        int score = 0;
        for (int g = init; g<fin; g++) {
            int h = offsets.get_seq_offset(g-1);
            int u = offsets.get_seq_offset(g);
            chrono::time_point<chrono::system_clock> start2, end2;
            start2 = std::chrono::system_clock::now();
            
            score = swipe.Algo(fasta, seq, h, u, gap_penality, extension_penality);
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
            tempsmoyen += elapsed_seconds2;
        }
    });
     */
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
        //score = fut.get();
        //score2 = fut2.get();
        
        //si le score est plus grand que le plus petit score enregistré
        // on retire le plus petit et on ajoute le nouveau score dans le tableau

        if(score_max.size() < 21){
            score_max.insert(pair<double, int>(score,g));
        }
        else if(score_max.size() == 21 && score_max.begin()->first < score){
            score_max.erase(score_max.begin());
            score_max.insert(pair<double, int>(score,g));
        }
        
        end2 = std::chrono::system_clock::now();
        double elapsed_seconds2 = chrono::duration_cast<chrono::milliseconds>(end2-start2).count();
        tempsmoyen += elapsed_seconds2;
    }
    end = std::chrono::system_clock::now();
    double elapsed_seconds = chrono::duration_cast<chrono::seconds>(end-start).count();
    cout << "Elapsed time: " << elapsed_seconds << "s\n";
    cout << "Average time per sequence: " << tempsmoyen/size << "ms" << endl;
    
    
    map<double,int>::iterator itr;
    int off=0;
    head.open_fichier();
    
    ofstream result("resultat.txt", ios::app);
    result<<endl;
    result<<"Matrix used : "<<matrice<<endl;
    result<<"Gap penalty : "<<gap_penality<<" \nExtension penalty : "<<extension_penality<<"\n"<<endl;
    result<<"Query file path: "<<chemin_fasta<<endl;
    result << endl;

    result << "Elapsed time: " << elapsed_seconds << "s" << endl;
    result << "Average time per sequence: " << tempsmoyen/size << "ms" << endl;
    result << endl;
    
    result << "Sequence producing significant alignements, classed with decreasing score :" << endl;
    result <<endl;
    //parcourt la liste des meilleurs score et affiche les informations sur la protéine contenues dans le header
    for(itr = --score_max.end(); itr != score_max.begin(); itr--){
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
    cout << "[+] Fichier resultat.txt créé dans le dossier dans lequel vous etes" << endl;
    return 0;
}
