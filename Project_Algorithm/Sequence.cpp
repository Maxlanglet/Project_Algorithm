//
//  Sequence.cpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 06/12/2019.
//  Copyright © 2019 Langlet Maxime. All rights reserved.
//

#include "Sequence.hpp"

Sequence::Sequence(string adr) : Binaire(adr){
    //vector<char> sequence;
    char* sequence;
    adresse = adr;
}
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
        cout << " erreur ouverture fichier" << endl;
        //break;
    }
    else{
        begin_byte = f.tellg();
        f.seekg (0, ios::end);
        end_byte = f.tellg();
        long total_bytes = end_byte - begin_byte;
        f.seekg(0, ios::beg);
        sequence = new char[total_bytes+1];
        int index=0;
        cout << "lecture psq" << endl;
         //char buf;
        while (f) {
             //f.read(reinterpret_cast<char*>(&buf), sizeof(char));//embiguité soit buf doit etre un int ou un char je sais pas
             sequence[index++]=f.get();
        }
         cout << "finis psq" <<  endl;
         f.close();
    }
}


void Sequence::del(){
    delete [] sequence;
}

void Sequence::get_sequence(int k, int l){
    for (int j = k; j <l-1; j++) {
        cout << score_Inverse(sequence[j]);
    }
    cout << endl;
}

 
char* Sequence::get_sequence2(){
    return sequence;
}
 
/*
vector<char> Sequence::get_sequence2(){
    return sequence;
}
 */

string Sequence::get_adresse(){
    return adresse;
}
