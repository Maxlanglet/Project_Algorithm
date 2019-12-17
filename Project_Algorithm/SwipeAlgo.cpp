//
//  SwipeAlgo.cpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 03/12/2019.
<<<<<<< HEAD
//  Copyright © 2019 Langlet Maxime. All rights reserved.
=======
//
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
//

#include "SwipeAlgo.hpp"

<<<<<<< HEAD
Swipe::Swipe(){// :  mat()
    //score;
    //blosum1;
=======
Swipe::Swipe(){
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
}
//https://www.researchgate.net/publication/281431935_Comparative_Study_of_the_Parallelization_of_the_Smith-Waterman_Algorithm_on_OpenMP_and_Cuda_C
//openMP

int Swipe::get_pos(char prot){
    int pos=0;
    switch (prot) {
        case 'A':
            pos=0;
            break;
        case 'R':
            pos=1;
            break;
        case 'N':
            pos=2;
            break;
        case 'D':
            pos=3;
            break;
        case 'C':
            pos=4;
            break;
        case 'Q':
            pos=5;
            break;
        case 'E':
            pos=6;
            break;
        case 'G':
            pos=7;
            break;
        case 'H':
            pos=8;
            break;
        case 'I':
            pos=9;
            break;
        case 'L':
            pos=10;
            break;
        case 'K':
            pos=11;
            break;
        case 'M':
            pos=12;
            break;
        case 'F':
            pos=13;
            break;
        case 'P':
            pos=14;
            break;
        case 'S':
            pos=15;
            break;
        case 'T':
            pos=16;
            break;
        case 'W':
            pos=17;
            break;
        case 'Y':
            pos=18;
            break;
        case 'V':
            pos=19;
            break;
        case 'B':
            pos=20;
            break;
        case 'J':
            pos=21;
            break;
        case 'Z':
            pos=22;
            break;
        case 'X':
            pos=23;
            break;
        case '*':
            pos=24;
            break;
        
        //default:
            //break;
    }
    return pos;
}

<<<<<<< HEAD
int Swipe::findMax(int array[], int longueur){
=======
int Swipe::findMax(int array[], int longueur){//fonction qui retourne le max d'une liste
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
    int max = array[0];
    for(int i=1; i<longueur; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

<<<<<<< HEAD
void Swipe::initialise_blosum(string adresse){
=======
void Swipe::initialise_blosum(string adresse){//Initialise la matrice blosum venant d'un fichier
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
    ifstream file(adresse);
    if(!file.is_open()) {
        cout << "[-] Pas bon chemin pour matrice blosum" << endl;
    }
<<<<<<< HEAD
    
=======
    //On sait que la matrice blosum est une matrice 25x25 avec un ordre sur les proteines
    //Etant donné que nous avons définis la fonction get_pos en fonction de cette ordre, la matrice donnée
    //ne devra que etre lue dans l'ordre et stocker chaque entier dans l'ordre
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
    blosum1=(int **) malloc((25) * sizeof(int*));
    for(int row = 0; row<25; row++) {
        blosum1[row] = (int *) malloc((25) * sizeof(int));
    }
    int k=0;
    int l=0;
    string word, t, q, filename;
    static const std::regex intRegex{ "[-+]?([0-9]*\.[0-9]+|[0-9]+)"};
    while (file >> word){
<<<<<<< HEAD
        if (regex_match(word, intRegex)){
=======
        if (regex_match(word, intRegex)){//Regex verifie si la string est un entier ou pas
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
            istringstream inputStream(word);
            int i;
            inputStream >> i;
            blosum1[k][l]=i;
            l++;
            if (l==25) {
                l=0;
                k++;
            }
        }
<<<<<<< HEAD
        else if(regex_match(word.substr(0, word.size()-3), intRegex)){
=======
        else if(regex_match(word.substr(0, word.size()-3), intRegex)){// ces else sont la pour les nombres en fin de ligne, la ou se trouve les "\n\"
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
            word = word.substr(0, word.size()-3);
            istringstream inputStream(word);
            int i;
            inputStream >> i;
            blosum1[k][l]=i;
            l++;
            if (l==25) {
                l=0;
                k++;
            }
        }
        else if(regex_match(word.substr(0, word.size()-2), intRegex)){
            word = word.substr(0, word.size()-2);
            istringstream inputStream(word);
            int i;
            inputStream >> i;
            blosum1[k][l]=i;
            l++;
            if (l==25) {
                l=0;
                k++;
            }
        }
    
    }
    file.close();
}

<<<<<<< HEAD
int Swipe::blosum(int i, int j){
=======
int Swipe::blosum(int i, int j){//fonction qui retourne la valeur de l'equivalence entre 2 acide-aminé
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
    return blosum1[i][j];
}


void Swipe::free_blosum(){
    for(int row = 0; row<25; row++){
        free(blosum1[row]);
    }
    free(blosum1);
}

<<<<<<< HEAD
//TODO: Presque finis
=======

>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
int Swipe::Algo(const string &fasta, const char* &psq, int offset1, int offset2, int gap_penality, int extension_penality){
    int posi=0;
    int posj=0;
    int max=0;
    unsigned long ligne = fasta.size();
    int colonne = offset2-offset1;
    
    //variable pour la fct poids Wk = u*k+v
    int u = extension_penality;
    int v = gap_penality;
    
<<<<<<< HEAD
    //vector<vector<int> > mat(ligne+1, vector<int>(colonne+1,0));
=======
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
    
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
    
<<<<<<< HEAD
    //vector<int> p(colonne+1);
    int *p=new int[colonne+1];//new un tout petit peu plus rapide ca a l'air
=======
    int *p=new int[colonne+1];//new un tout petit peu plus rapide sur ma machine
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
    //int *p=(int*)malloc((colonne+1)*sizeof(int));
    for (int j =0; j<colonne+1; j++) {
       p[j]=0;
    }
<<<<<<< HEAD
    p[0] = -9999;
    p[1] = -u-v;//-v
    int memo[4];
=======
    p[0] = -9999;// elements dans p que nous n'utiliserons pas, on le met pour pouvoir utiliser les memes indices
    p[1] = -u-v;
    int memo[4];//On stock les 4 éléments a comparer dans une liste et on compare avec find_max
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
    int maxlocal=0;
    for (int i =1; i<=ligne; i++) {
        posi=get_pos(fasta[i-1]);
        int q = -u-v;//-v
        
        for (int j =1; j<=colonne; j++) {
            posj=get_pos(score_Inverse(psq[j+offset1]));
<<<<<<< HEAD
            /*je sais pas pq mais ca fonctionne pas ca
            if (mat[i-1][j-1]+blosum(posi, posj)>maxlocal) {
                maxlocal=mat[i-1][j-1]+blosum(posi, posj);
            }
            else if (maxlocal<p[j]) {
                maxlocal=p[j];
            }
            else if (maxlocal<q) {
                maxlocal=q;
            }
             */
=======
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
            int pj = p[j];
            memo[0]=mat[i-1][j-1]+blosum(posi,posj);
            memo[1] = pj;
            memo[2]=q;
            memo[3]=0;
            mat[i][j] = findMax(memo, 4);
<<<<<<< HEAD
            maxlocal = mat[i][j];
            if (maxlocal>max) {//mat[i][j]
                max = maxlocal;
            }
            //a ameliorer en faisant ca peut etre
            /*
            if (j<colonne && maxlocal-u > q-u) {
                q = maxlocal-u-v;
            }
            else if(j<colonne){
                q = q-u;
            }
            if (i!=colonne && maxlocal>p[j]-u) {
                p[j] = maxlocal-u;
            }
            else if (i!=ligne){
                p[j]=p[j]-u;
            }
             */
            int comp[2];
            comp[0]=maxlocal-u-v;//-v//TODO: il manque -11 dans les scores peut etre erreur ici
=======
            
            maxlocal = mat[i][j];
            if (maxlocal>max) {
                max = maxlocal;
            }
            //On memoise les prochains max pour les gap extension et penality
            int comp[2];
            comp[0]=maxlocal-u-v;//TODO: il manque -11 dans les scores peut etre erreur ici
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
            comp[1]=q-u;
            if(j < colonne){
                q=findMax(comp,2);
            }
            comp[1]=pj-u;
            if(i != ligne){
                p[j] = findMax(comp, 2);
            }
        }
    }
    double lambda = 0.267;
    int Sbit = (max*lambda-3.34)/log(2);
<<<<<<< HEAD
    //score = (max*lambda-3.34)/log(2);
=======
>>>>>>> 16fb9d09a4afc4ee8957e3e23b9fe45f7ee87c68
    
    for(int row = 0; row<ligne+1; row++){
        free(mat[row]);
    }
    free(mat);
    //free(p);
    delete [] p;
    
    return Sbit;
}
