//
//  Sequence.cpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 06/12/2019.
<<<<<<< HEAD
//  Copyright © 2019 Langlet Maxime. All rights reserved.
=======
//
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
//

#include "Sequence.hpp"

Sequence::Sequence(string adr) : Binaire(adr){
    //vector<char> sequence;
    char* sequence;
    adresse = adr;
}
<<<<<<< HEAD
/*
void Sequence::read_psq(){
    ifstream f(adresse);
    if (!f.is_open()){
        cout << " erreur ouverture fichier" << endl;
        //break;
    }
    else{
        cout << "lecture psq" << endl;
         char buf;
         while (f) {
             //f.read(reinterpret_cast<char*>(&buf), sizeof(char));//embiguité soit buf doit etre un int ou un char je sais pas
             f.read(&buf, sizeof(char));
             sequence.push_back(buf);
        }
         cout << "finis psq" <<  endl;
         f.close();
    }
}
 */
 /*
 long begin_byte, end_byte;
 ifstream in("example.txt");
 begin_byte = in.tellg();
 in.seekg (0, ios::end);
 end_byte = in.tellg();
 int total_bytes = end_byte - begin_byte;
 in.seekg(0, ios::begin);
 char *message = new char[total_bytes + 1];
 int index = 0;
 while (in) {
   message[index++] = in.get();
 }
 in.close();
 cout << "message is: " << message << endl;
*/


void Sequence::read_psq(){
    long begin_byte, end_byte;
    ifstream f(adresse);
    if (!f.is_open()){
        cout << "[-] Erreur ouverture fichier psq" << endl;
        //break;
    }
=======
//On stock toute la base de données dans une liste de pointeurs
void Sequence::read_psq(){
    long begin_byte, end_byte;//vont nous servir pour la taille de la sequence
    ifstream f(adresse);
    if (!f.is_open()){
        cout << "[-] Erreur ouverture fichier psq" << endl;
    }
    
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
    else{
        begin_byte = f.tellg();
        f.seekg (0, ios::end);
        end_byte = f.tellg();
<<<<<<< HEAD
        long total_bytes = end_byte - begin_byte;
=======
        long total_bytes = end_byte - begin_byte; //determine la taille du tableau
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
        f.seekg(0, ios::beg);
        sequence = new char[total_bytes+1];
        int index=0;
        cout << "[+] Lecture psq" << endl;
<<<<<<< HEAD
         //char buf;
        while (f) {
             //f.read(reinterpret_cast<char*>(&buf), sizeof(char));//embiguité soit buf doit etre un int ou un char je sais pas
=======
        while (f) {
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
             sequence[index++]=f.get();
        }
         cout << "[+] Finis psq" <<  endl;
         f.close();
    }
}


void Sequence::del(){
    delete [] sequence;
}
<<<<<<< HEAD
/*
void Sequence::get_sequence(int k, int l){
    for (int j = k; j <l-1; j++) {
        cout << score_Inverse(sequence[j]);
    }
    cout << endl;
}
*/
 
char* Sequence::get_sequence2(){
    return sequence;
}
 
/*
vector<char> Sequence::get_sequence2(){
    return sequence;
}
 */
=======

char* Sequence::get_sequence2(){
    return sequence;
}
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68

string Sequence::get_adresse(){
    return adresse;
}
