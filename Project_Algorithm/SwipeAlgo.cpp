//
//  SwipeAlgo.cpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 03/12/2019.
//  Copyright © 2019 Langlet Maxime. All rights reserved.
//

#include "SwipeAlgo.hpp"

Swipe::Swipe(){// :  mat()
}


int Swipe::get_blosum(int i, int j){
    return blosum(i,j);
}

int Swipe::get_pos(char prot){
    int pos=0;
    if (prot=='A') {
        pos=0;
    }
    if (prot=='R') {
        pos=1;
    }
    if (prot=='N') {
        pos=2;
    }
    if (prot=='D') {
        pos=3;
    }
    if (prot=='C') {
        pos=4;
    }
    if (prot=='Q') {
        pos=5;
    }
    if (prot=='E') {
        pos=6;
    }
    if (prot=='G') {
        pos=7;
    }
    if (prot=='H') {
        pos=8;
    }
    if (prot=='I') {
        pos=9;
    }
    if (prot=='L') {
        pos=10;
    }
    if (prot=='K') {
        pos=11;
    }
    if (prot=='M') {
        pos=12;
    }
    if (prot=='F') {
        pos=13;
    }
    if (prot=='P') {
        pos=14;
    }
    if (prot=='S') {
        pos=15;
    }
    if (prot=='T') {
        pos=16;
    }
    if (prot=='W') {
        pos=17;
    }
    if (prot=='Y') {
        pos=18;
    }
    if (prot=='V') {
        pos=19;
    }
    if (prot=='B') {
        pos=20;
    }
    if (prot=='J') {
        pos=21;
    }
    if (prot=='Z') {
        pos=22;
    }
    if (prot=='X') {
        pos=23;
    }
    if (prot=='*') {
        pos=24;
    }
    return pos;
}

int Swipe::findMax(int array[], int longueur){
    int max = array[0];
    int ind = 0;
    for(int i=1; i<longueur; i++){
        if(array[i] > max){
            max = array[i];
            ind=i;
        }
    }
    return max;
}


//TODO: Pas finis mais deja un debut
double Swipe::Algo(const string &fasta, const char* &psq, long offset1, long offset2){
    //cout<<"lancement algo ok"<<endl;
    int posi=0;
    int posj=0;
    int max=0;
    unsigned long ligne = fasta.size();
    int colonne = offset2-offset1;
    
    //variable pour la fct poids Wk = u*k+v
    int u = 1;
    int v = 10;
    
    //vector<vector<int> > mat(ligne+1, vector<int>(colonne+1,0));
    
    int **mat;
    mat = (int **) malloc((ligne+1) * sizeof(int*));
    for(int row = 0; row<ligne+1; row++) {
        mat[row] = (int *) malloc((colonne+1) * sizeof(int));
    }
    for (int i = 0; i<ligne+1; i++) {
        mat[i][0]=0;
    }
    for (int j =0; j<colonne+1; j++) {
        mat[0][j]=0;
    }
    
    //matrice pour mémoiser les éléments Pij
    /*vector<vector<int> > p(ligne+1, vector<int>(colonne+1));
    try{
        for(int i = 0;i<=ligne;i++){
            p[i][0] = -9999;
        }
        for(int j= 0; j <= colonne; j++){
            p[0][j] = -9999;
            p[1][j] = -u-v;
        }
    }
    catch(const std::out_of_range& oor){
        cout<<"out of range pour creation p"<<endl;
    }*/
    
    vector<int> p(colonne+1);
    p[0] = -9999;
    p[1] = -u-v;
    
    //for(int i=0;i<=ligne;i++){
    //mat[i][0]=0;
    //}
    //for(int j=0;j<=colonne;j++){
    //mat[0][j]=0;
    //}
    //mat.clear();
    //mat.resize(fasta.size(), vector<int>(offset2-offset1));
    //vector<vector<int> > mat(fasta.size(), vector<int>(offset2-offset1, 0));//TODO: meilleur choix avec matrice et memoisation de je sais pas quoi, comme pas possible de faire int [truc variable] il faut passer par des pointeurs je pense
    /*
     int **mat;
     mat = (int **) malloc(fasta.size() * sizeof(int*));
     for(int row = 0; row<fasta.size(); row++) {
     mat[row] = (int *) malloc((offset2-offset1) * sizeof(int));
     }
     for (int i = 0; i<fasta.size(); i++) {
     for (int j =0; j<offset2-offset1; j++) {
     mat[i][j]=0;
     }
     }
     */
    
    //vector<int> q;
    
    int memo[4];
    //cout << "pas pbm memo" << endl;
    for (int i =1; i<=fasta.size(); i++) {
        posi=get_pos(fasta[i-1]);
        //cout << "pas pbm fasta" << endl;
        //cout << posi << endl;
        
         //vector<int> q(colonne+1, 0);
        //q[0]=-9999;
        int q = -u-v;
        
        for (int j =1; j<=offset2-offset1; j++) {
            //ligne.clear();
            posj=get_pos(score_Inverse(psq[j+offset1]));
            //cout << "pas pbm psq" << endl;
            //cout << posj << endl;
            memo[0]=mat[i-1][j-1]+blosum(posi, posj);
            //cout << "pas pbm memo0 ou blosum" << endl;
            // memo[1]=mat[i-1][j]-11;
            //memo[1]=p[i][j];
            memo[1] = p[j];
            //cout << "pas pbm memo1" << endl;
            try{
                
                // memo[2]=mat[i][j-1]-11;
                //memo[2]=q[j];
                memo[2]=q;
                //cout << "pas pbm memo2" << endl;
            }
            catch(const std::out_of_range& oor){
                cout<<"out of range pour memo pour j = "<<j<<endl;
            }
            memo[3]=0;
            //cout << "pas pbm memo3" << endl;
            mat[i][j] = findMax(memo, 4);
            //cout << "pas pbm findmax" << endl;
            if (mat[i][j]>max) {
                max = mat[i][j];
                //cout << "pas pbm max" << endl;
            }
            try{
                int comp[2];
                comp[0]=mat[i][j]-u-v;
                //comp[1]=q[j];
                comp[1]=q-u;
                if(j < offset2-offset1){
                    //q[j+1]=findMax(comp,2);
                    q=findMax(comp,2);
                }
                //comp[1]=p[i][j]-u;
                comp[1]=p[j]-u;
                if(i != fasta.size()){
                    //p[i+1][j] = findMax(comp, 2);
                    p[j] = findMax(comp, 2);
                }
            }
            catch(const std::out_of_range& oor){
                cout<<"out of range pour i+1 et j+1"<<endl;
            }
            
            
        }
    }
    double lambda = 0.267;
    double Sbit = (max*lambda-3.34)/log(2);
    //cout << "score :"<< Sbit << endl;
    
    for(int row = 0; row<ligne+1; row++){
        free(mat[row]);
    }
    free(mat);
    
    return Sbit;
    /*
     for(int row = 0; row<fasta.size(); row++) {
     free(mat[row]);
     }
     free(mat);
     */
}
//void swipe::lireBlosum(const char blosum)//si on a le choix pour les matrices BLOSUM alors on fait direct une map
