//
//  Score.cpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 08/11/2019.
//
//

#include "Score.hpp"
//établit la correspondance entre la valeur du résidu et la lettre qui le représente
char score_Inverse(int valeur){
    char lettre = '\0';
    switch (valeur) {
        case 0:
            lettre = '-';
        break;
        case 1:
            lettre = 'A';
            break;
        case 2:
            lettre = 'B';
            break;
        case 3:
            lettre = 'C';
            break;
        case 4:
            lettre = 'D';
            break;
        case 5:
            lettre = 'E';
            break;
        case 6:
            lettre = 'F';
            break;
        case 7:
            lettre = 'G';
            break;
        case 8:
            lettre = 'H';
            break;
        case 9:
            lettre = 'I';
            break;
        case 10:
            lettre = 'K';
            break;
        case 11:
            lettre = 'L';
            break;
        case 12:
            lettre = 'M';
            break;
        case 13:
            lettre = 'N';
            break;
        case 14:
            lettre = 'P';
            break;
        case 15:
            lettre = 'Q';
            break;
        case 16:
            lettre = 'R';
            break;
        case 17:
            lettre = 'S';
            break;
        case 18:
            lettre = 'T';
            break;
        case 19:
            lettre = 'V';
            break;
        case 20:
            lettre = 'W';
            break;
        case 21:
            lettre = 'X';
            break;
        case 22:
            lettre = 'Y';
            break;
        case 23:
            lettre = 'Z';
            break;
        case 24:
            lettre = 'U';
            break;
        case 25:
            lettre = '*';
            break;
        case 26:
            lettre = '0';
        break;
        case 27:
            lettre = 'J';
        break;
        //default:
            //break;
    }
    return lettre;
}
