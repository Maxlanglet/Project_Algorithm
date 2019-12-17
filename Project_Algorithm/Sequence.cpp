//
//  Sequence.cpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 06/12/2019.
//
//

#include "Sequence.hpp"

Sequence::Sequence(string adr) : Binaire(adr){
    //vector<char> sequence;
    char* sequence;
    adresse = adr;
}
//On stock toute la base de données dans une liste de pointeurs
void Sequence::read_psq(){
    long begin_byte, end_byte;//vont nous servir pour la taille de la sequence
    ifstream f(adresse);
    if (!f.is_open()){
        cout << "[-] Erreur ouverture fichier psq" << endl;
    }
    
    else{
        begin_byte = f.tellg();
        f.seekg (0, ios::end);
        end_byte = f.tellg();
        long total_bytes = end_byte - begin_byte; //determine la taille du tableau
        f.seekg(0, ios::beg);
        sequence = new char[total_bytes+1];
        int index=0;
        cout << "[+] Lecture psq" << endl;
        while (f) {
             sequence[index++]=f.get();
        }
         cout << "[+] Finis psq" <<  endl;
         f.close();
    }
}


void Sequence::del(){
    delete [] sequence;
}

char* Sequence::get_sequence2(){
    return sequence;
}

string Sequence::get_adresse(){
    return adresse;
}
