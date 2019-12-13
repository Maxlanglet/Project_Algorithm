//
//  Offsets.cpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 06/12/2019.
//  Copyright © 2019 Langlet Maxime. All rights reserved.
//

#include "Offsets.hpp"

Offsets::Offsets(string adr) : Binaire(adr){
    vector<int> seq_offsets;
    vector<int> head_offsets;
    adresse = adr;
}

void Offsets::offset(){
    ifstream f(adresse);
    //header offset
    cout << "lecture pin head" << endl;
    head_offsets.clear();
    //vector<int> v2;
    //f.seekg(1,ios::beg); probleme ici mais du coup je sais pas comment faire pour lire au debut
    int j = 0;
    int myint2;
    int offset = 0;
    while (!f.eof()) {
       f.read(reinterpret_cast<char*>(&myint2), sizeof(int));//reinterpret_cast<char*>(&myint)
       head_offsets.push_back((int)(bswap_32(myint2)));
       j++;
       if (head_offsets[j-1]==0) {
           //buffer.clear();
           //buffer.push_back(1);// ajoute le 1
           offset=j-1;
       }
       if (bswap_32(myint2)==1 && j>=12) {//on regarde apres les 12 premiers éléments du fichier pin car sont les autres elements
           head_offsets.pop_back();//enleve le 1
           break;
       }
      }
    //buffer.insert(buffer.begin(), 0);//ajoute le 0
    head_offsets = vector<int>(head_offsets.begin() + offset, head_offsets.end()); //probleme dans les vecteurs de taille diff 1
    //head_offsets = v2;
    cout << "finis header" << endl;
       //return v2;
    
    
    //sequence offset
    cout << "lecture pin" << endl;
    seq_offsets.clear();
    int i = 0;
    int myint;
    while (!f.eof()) {
        f.read(reinterpret_cast<char*>(&myint), sizeof(int));
        seq_offsets.push_back((int)(bswap_32(myint)));
        i++;
        if (seq_offsets[i-1]==1) {
            seq_offsets.clear();
            //buffer.push_back(1);// ajoute le 1
        }
       }
    seq_offsets.insert(seq_offsets.begin(), 1);//ajoute le 1
    seq_offsets.pop_back(); //apparement lit 2 fois le dernier je sais pas pq du coup voir assistant
    cout << "finis seq" << endl;
    f.close();
}


void Offsets::header_offset(){
   
}




int Offsets::get_seq_offset(int pos){
    return seq_offsets[pos];
}

int Offsets::get_head_offset(int pos){
    return head_offsets[pos];
}

unsigned long Offsets::get_size(){
    return seq_offsets.size();
}
