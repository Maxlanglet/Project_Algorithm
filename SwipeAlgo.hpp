//
//  SwipeAlgo.hpp
//  Project_Algorithm
//
//  Created on 03/12/2019.
//
//

#ifndef SwipeAlgo_hpp
#define SwipeAlgo_hpp

#include "header.h"

class Swipe{
public:
    int get_pos(char prot);
    int blosum(int i, int j);
    Swipe();
    int Algo(const string &fasta,const char* &psq, int offset1, int offset2, int gap_penality = 11, int extension_penality = 1);
    //static void Algo(const string &fasta, const char* &psq, int offset1, int offset2);
    int findMax(int array[], int longueur);
    void initialise_blosum(string adresse="blosum62");
    void free_blosum();
private:
    int** blosum1;
};


#endif /* SwipeAlgo_hpp */
