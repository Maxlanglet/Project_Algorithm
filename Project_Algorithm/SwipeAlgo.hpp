//
//  SwipeAlgo.hpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 03/12/2019.
//  Copyright © 2019 Langlet Maxime. All rights reserved.
//

#ifndef SwipeAlgo_hpp
#define SwipeAlgo_hpp

#include "header.h"

class Swipe{
public:
    int get_pos(char prot);
    int get_blosum(int i, int j);
    Swipe();
    double Algo(const string &fasta, const char* &psq, long offset1, long offset2);
    int findMax(int array[], int longueur);
private:
    //peut etre mettre matrice et resize a chaque fois dans l'algo
    //vector<vector<int>> mat;
};


//int get_pos(char prot);
//void swipe(string fasta, vector<char> psq, int offset1, int offset2);


#endif /* SwipeAlgo_hpp */
