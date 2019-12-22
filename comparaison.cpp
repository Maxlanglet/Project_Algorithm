//
//  comparaison.cpp
//  Project_Algorithm
//


// Utilisé pour la remise intermédiaire mais plus dans le code actuel
//

#include "comparaison.hpp"

bool Sequence_comp(string fichier_fasta, vector<char> fichier_psq, vector<int> sequence_offset, vector<int> header_offset, ifstream &file){
    int h=0;
    for (int i=0; i<sequence_offset.size(); i++) {
        int k=0;
        int offset = sequence_offset[i];
        for (int j =0; j<fichier_fasta.size(); j++) {
            //dès qu'on trouve 2 résidus différent on arrête cette itération de la boucle
            if (fichier_fasta[j]!=score_Inverse(fichier_psq[j+offset])) {
                k++;
                break;
            }
        }
        if (k==0) {
            acquiert(header_offset[i], file);
            //cout << "Sequence dans fasta :" << endl;
            //cout << fichier_fasta << endl;
            //cout << "Sequence dans psq :" << endl;
            for (int l = 0; l<fichier_fasta.size(); l++) {
                cout << score_Inverse(fichier_psq[l+offset]);
            }
            cout<<endl;
            cout << "Offset de la sequence :" << offset << endl;
            h++;
            break;
        }
    }
    if (h==0) {
        cout << "Aucune séquence trouvée" << endl;
    }
    return true;
}
