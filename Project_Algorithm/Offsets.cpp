//
//  Offsets.cpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 06/12/2019.
//
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
    }
    else{
        head_offsets.clear();
        cout << "[+] Lecture pin head" << endl;
        int j = 0;
        int myint2;
        int offset = 0;
        
        //La boucle suivante lit et stock les offset du header dans un vecteur
        while (!f.eof()) {
           f.read(reinterpret_cast<char*>(&myint2), sizeof(int));
           head_offsets.push_back((int)(bswap_32(myint2)));
           j++;
           if (head_offsets[j-1]==0) {
               offset=j-1;
           }
            //On lit jusqu'a ce qu'on a un "1", a ce moment la on passe au offset des sequences
           if (bswap_32(myint2)==1 && j>=12) {//on regarde apres les 12 premiers éléments du fichier pin car sont des elements pas necessaire pour les offsets
               head_offsets.pop_back();//enleve le 1
               break;
           }
          }
        
        info.clear();//on stock les informations avant les offsets
        info = vector<int>(head_offsets.begin(),head_offsets.begin()+offset);
        head_offsets = vector<int>(head_offsets.begin() + offset, head_offsets.end()); //coupe les quelques premiers elements pas necessaire pour les offsets
        
        cout << "[+] Finis header" << endl;
        
        int pos = f.tellg();
        print_info(&f);
        f.seekg(pos);
        pos = f.tellg();

        //sequence offset
        seq_offsets.clear();
        if (!f.is_open()){
            cout << " erreur ouverture fichier" << endl;
        }
        
        cout << "[+] Lecture pin off" << endl;
        int i = 0;
        int myint;
        //Boucle qui stock les offset des sequences
        while (!f.eof()) {
            f.read(reinterpret_cast<char*>(&myint), sizeof(int));
            seq_offsets.push_back((int)(bswap_32(myint)));
            i++;
            if (seq_offsets[i-1]==1) {
                seq_offsets.clear();
            }
           }
        seq_offsets.insert(seq_offsets.begin(), 1);//ajoute le 1
        seq_offsets.pop_back(); //apparement lit 2 fois le dernier je sais pas pourquoi
    }
    cout << "[+] Finis off seq" << endl;
    f.close();
}


void Offsets::header_offset(){
   
}

void Offsets::print_info(ifstream* f){
    //on recupère les données stonckées sur les 3 premiers int32
    int version = info[0];
    int type_residu = info[1];
    int size_title = info[2];
    
    ofstream result("resultat.txt");
    result<<"Information about the database :"<<endl;
    result<<"Version : "<<version<<endl;
    //pour lire le titre de la base de donnée et sa date on accède au fichier
    //et on utilise le même principe que pour lire dans le header
    f->seekg(12); //debut de la séquence qui contient le titre
    //int pos = f->tellg();
    
    char* titre = new char[size_title];
    f->read(titre,size_title);
    string title = string(titre, size_title);
    //cout<<title<<endl;
    result<<"Name : "<<title<<endl;;
    //les 4 octets suivant contiennent la taille de la date
    int size_date = 0;
    f->read((char*)&size_date, sizeof(int));
    size_date = (int)(bswap_32(size_date));
    //on lit la date
    char* date = new char[size_date];
    f->read(date, size_date);
    string date_str = string(date, size_date);
    
    result<<"Date : "<<date_str<<endl;
    
    delete[] titre;
    delete[] date;
    
    pos = f->tellg();
    while(pos%4 != 0){
        pos++;
    }
    f->seekg(pos);
    //ensuite il y a un int32 pour le nombre de séquence, un int64 pour le nombre de résidus, un int32 pour la longueur de la plus longue séquence
    int sequence = 0;
    f->read((char*)&sequence, sizeof(int));
    sequence = (int)(bswap_32(sequence));
    
    long long residus = 0;
    f->read((char*)&residus, 8);
    
    int longest_sequence = 0;
    f->read((char*)&longest_sequence, sizeof(int));
    longest_sequence = (int)(bswap_32(longest_sequence));
    
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
