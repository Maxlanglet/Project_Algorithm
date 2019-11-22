//
//  comparaison.cpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 22/11/2019.
//  Copyright © 2019 Langlet Maxime. All rights reserved.
//

#include "comparaison.hpp"

bool Sequence_comp(string fichier_fasta, vector<char> fichier_psq, vector<int> sequence_offset, vector<int> header_offset){
    for (int i=0; i<sequence_offset.size(); i++) {
        int k=0;
        int offset = sequence_offset[i];
        for (int j =0; j<fichier_fasta.size(); j++) {
            if (fichier_fasta[j]!=score_Inverse(fichier_psq[j+offset])) {
                k++;
                break;
            }
        }
        if (k==0) {
            cout << "Sequence trouvée :" << endl;
            cout << fichier_fasta << endl;
            cout << "Sequence dans psq :" << endl;
            for (int l = 0; l<fichier_fasta.size(); l++) {
                cout << score_Inverse(fichier_psq[l+offset]);
            }
            cout<<endl;
            cout << "Offset de la sequence :" << offset << endl;
            break;
        }
    }
    return true;
}
