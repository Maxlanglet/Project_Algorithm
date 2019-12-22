//
//  ouverture.hpp
//  Project_Algorithm
//
//  Created by on 17/11/2019.
//  utilisé au mis parcourt
//

#ifndef ouverture_hpp
#define ouverture_hpp

#include "Fasta_To_Bits.hpp"

vector<char> read_psq( ifstream &file);
vector<int> header_offset(ifstream &file);
vector<int> sequence_offset(ifstream &file);
string read_string(ifstream* f);
int read_int(ifstream* f);
void acquiert(int offset, ifstream &f);
int Hex_Int(string hex, int size);
#endif /* ouverture_hpp */
