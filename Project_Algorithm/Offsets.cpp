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
    
    if (!f.is_open()){
        cout << "[-] Erreur ouverture fichier pin" << endl;
        //break;
    }
    else{
        head_offsets.clear();
        cout << "[+] Lecture pin head" << endl;
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
        info.clear();
        info = vector<int>(head_offsets.begin(),head_offsets.begin()+offset);
        head_offsets = vector<int>(head_offsets.begin() + offset, head_offsets.end()); //probleme dans les vecteurs de taille diff 1
        //head_offsets = v2;
        cout << "[+] Finis header" << endl;
           //return v2;
        
        int pos = f.tellg();
        //cout<<"pos: "<<pos<<endl;
        print_info(&f);
        f.seekg(pos);
        pos = f.tellg();
        //cout<<"pos: "<<pos<<endl;

        //sequence offset
        seq_offsets.clear();
        if (!f.is_open()){
            cout << " erreur ouverture fichier" << endl;
            //break;
        }
        cout << "[+] Lecture pin off" << endl;
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
    }
    cout << "[+] Finis off seq" << endl;
    f.close();
}


void Offsets::header_offset(){
   
}

void Offsets::print_info(ifstream* f){
    int version = info[0];
    int type_residu = info[1];
    int size_title = info[2];
    
    ofstream result("resultat.txt");
    result<<"Information about the database :"<<endl;
    result<<"Version : "<<version<<endl;
    
    f->seekg(12); //debut de la séquence qui contient le titre
    int pos = f->tellg();
    //cout<<"pos: "<<pos<<endl;
    
    char* titre = new char[size_title];
    f->read(titre,size_title);
    string title = string(titre, size_title);
    //cout<<title<<endl;
    result<<"Name : "<<title<<endl;;
    
    int size_date = 0;
    f->read((char*)&size_date, sizeof(int));
    size_date = (int)(bswap_32(size_date));
    
    char* date = new char[size_date];
    f->read(date, size_date);
    string date_str = string(date, size_date);
    //cout<<date_str<<endl;
    result<<"Date : "<<date_str<<endl;
    
    delete[] titre;
    delete[] date;
    
    pos = f->tellg();
    while(pos%4 != 0){
        pos++;
    }
    f->seekg(pos);
    
    int sequence = 0;
    f->read((char*)&sequence, sizeof(int));
    sequence = (int)(bswap_32(sequence));
    
    long long residus = 0;
    f->read((char*)&residus, 8);
    
    int longest_sequence = 0;
    f->read((char*)&longest_sequence, sizeof(int));
    longest_sequence = (int)(bswap_32(longest_sequence));
    
    //cout<<"nbre de seq : "<<sequence<<" nbre de résidu : "<<residus<<" taille max séq : "<<longest_sequence<<endl;
    result<<"The database contains "<<residus<<" residues in "<<sequence<<" sequences"<<endl;
    result<<"The longest sequence has "<<longest_sequence<<" residues \n"<<endl;
    result.close();
    
    
}

int Offsets::get_head_offset(int pos){
    return head_offsets[pos];
}

int Offsets::get_seq_offset(int pos){
    return seq_offsets[pos];
}

unsigned long Offsets::get_size(){
    return seq_offsets.size();
}
