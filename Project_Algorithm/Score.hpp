//
//  Score.hpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 08/11/2019.
//  Copyright © 2019 Langlet Maxime. All rights reserved.
//

#ifndef Score_hpp
#define Score_hpp


#include <iomanip>
#include <cmath>
#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <string.h>
#include <arpa/inet.h>
#include <vector>
#include <chrono>
#include <ctime>
#include <map>

using namespace std;

string Score(string sequence);
char score_Inverse(int valeur);
int comparaison_De_Sequence(ifstream &file, string sequence);

#endif /* Score_hpp */
