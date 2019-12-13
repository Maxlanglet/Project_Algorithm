//
//  Sequence.hpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 06/12/2019.
//  Copyright © 2019 Langlet Maxime. All rights reserved.
//

#ifndef Sequence_hpp
#define Sequence_hpp

#include "binaire.h"

class Sequence : public Binaire{
public:
    void read_psq();
    Sequence(string adr);
    void get_sequence(int k = 0, int l = 100);
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
