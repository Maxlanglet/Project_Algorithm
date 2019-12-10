//
//  main.cpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 01/11/2019.
//  Copyright © 2019 Langlet Maxime. All rights reserved.
//

#include "Fasta_To_Bits.hpp"
#include "Score.hpp"
#include "ouverture.hpp"
#include "comparaison.hpp"
#include "SwipeAlgo.hpp"
#include "binaire.h"
#include "Sequence.hpp"
#include "Offsets.hpp"
#include "blosum.hpp"
#include "header.h"


int main(int argc, const char * argv[]) {
    /*
    if(argc<=1){
        cout << "Argument demandé :" << argv[0]<<" [fichier] "<<endl;
        return 1;
    }
    

    
    //ifstream input(argv[1]);
    string bits;
    ifstream input("/Users/langletmaxime/Desktop/P4/C++/swipe/P00533.fasta");
    ifstream input2("/Users/langletmaxime/Desktop/P4/C++/swipe/uniprot_sprot.fasta.pin");
    ifstream file("/Users/langletmaxime/Desktop/P4/C++/swipe/uniprot_sprot.fasta.psq");
    ifstream file2("/Users/langletmaxime/Desktop/P4/C++/swipe/uniprot_sprot.fasta.phr");
    //ifstream input(argv[1]);
    //ifstream input2(argv[2]);
    //ifstream file(argv[3]);
    //ifstream file2(argv[4]);
    //chrono::time_point<chrono::system_clock> start, end;
    //start = std::chrono::system_clock::now();
    vector<char> buffer = read_psq(file);
    vector<char> buffer2;
    vector<int> header_offsets;
    vector<int> sequence_offsets;
    
    
    header_offsets = header_offset(input2);
    sequence_offsets = sequence_offset(input2);
    bits = Fasta_To_String(input);
    
    
    int l = sequence_offsets[0];
    int m = sequence_offsets[1];
    //buffer2 = buffer[l:m]; trouver un moyen de faire plus ou moins comme ca
    for (int k =l; k<m-l; k++) {
        buffer2.push_back(buffer[k]);
    }
    for (int k = 0; k<buffer2.size(); k++) {
        cout << score_Inverse(buffer2[k]);
    }
    cout<<endl;
    //Sequence_comp(bits, buffer, sequence_offsets, header_offsets, file2);
    //end = std::chrono::system_clock::now();
    //int elapsed_seconds = chrono::duration_cast<chrono::milliseconds>(end-start).count();
    //cout << "elapsed time: " << elapsed_seconds << "s\n";
    input.close();
    input2.close();
    file.close();
     */
    //"/Users/langletmaxime/Desktop/P4/C++/swipe/uniprot_sprot.fasta.psq"
    //"/Users/langletmaxime/Desktop/P4/C++/swipe/uniprot_sprot.fasta.pin"
    Sequence sequence("uniprot_sprot.fasta.psq");
    Offsets offsets("uniprot_sprot.fasta.pin");
    Swipe swipe;
    ifstream input("P00533.fasta");
    string fasta = Fasta_To_String(input);
    //sequence.open_fichier();
    sequence.read_psq();
    //offsets.open_fichier();
    //offsets.header_offset();
    offsets.offset();
    const char* seq = sequence.get_sequence2();
    cout << "lancement swipe" << endl;
    double tempsmoyen = 0.0;
    chrono::time_point<chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    for (int g = 1; g<10000; g++) {//1878 pbm //offsets.get_size()
        long h = offsets.get_seq_offset(g-1);
        long u = offsets.get_seq_offset(g);
        chrono::time_point<chrono::system_clock> start2, end2;
        start2 = std::chrono::system_clock::now();
        swipe.Algo(fasta, seq, h, u);
        end2 = std::chrono::system_clock::now();
        double elapsed_seconds2 = chrono::duration_cast<chrono::milliseconds>(end2-start2).count();
        cout << "elapsed time: " << elapsed_seconds2 << "ms\n";
        tempsmoyen += elapsed_seconds2;
        cout << g << endl;
    }
    //sequence.del();
    end = std::chrono::system_clock::now();
    double elapsed_seconds = chrono::duration_cast<chrono::seconds>(end-start).count();
    cout << "elapsed time: " << elapsed_seconds << "s\n";
    cout << "temps moyen par sequence: " << tempsmoyen/10000 << endl;
    //sequence.close_fichier();
    //offsets.close_fichier();
    return 0;
}
