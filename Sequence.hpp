//
//  Sequence.hpp
//  Project_Algorithm
//
//  Created on 06/12/2019.
//

#ifndef Sequence_hpp
#define Sequence_hpp

#include "binaire.h"

class Sequence : public Binaire{
public:
    void read_psq();
    Sequence(string adr);
    //void get_sequence(int k = 0, int l = 100);
    string get_adresse();
    //vector<char> get_sequence2();
    char* get_sequence2();
    void del();
private:
    //ifstream f;
    string adresse;
    //vector<char> sequence;
    char* sequence;
};

#endif /* Sequence_hpp */
