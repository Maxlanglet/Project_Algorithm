//
//  Fasta_To_Bits.cpp
//  Project_Algorithm
//
//  Created by Langlet Maxime on 08/11/2019.
//  Copyright © 2019 Langlet Maxime. All rights reserved.
//

#include "Fasta_To_Bits.hpp"


string Fasta_To_String(ifstream &input){
    /*
    Style de format FASTA :
     >Rosetta_Example_1
     THERECANBENOSPACE
     >Rosetta_Example_2
     THERECANBESEVERAL
     LINESBUTTHEYALLMUST
     BECONCATENATED
    Qui donnera au final :
     Rosetta_Example_1 : THERECANBENOSPACE
     Rosetta_Example_2 : THERECANBESEVERALLINESBUTTHEYALLMUSTBECONCATENATED
     
     En gros ce que fait le code ci-dessous, c'est qu'il regarde prend le nom et ajoute les lignes de manières consécutives plutot que 80 caracteres par 80 caracteres, ce qui est mieux je crois. Ensuite il print le nom et le contenu.
     
     Source : http://rosettacode.org/wiki/FASTA_format
    */
    string ligne, nom, contenu;
    if(input){
        while(getline(input, ligne)){
            if(ligne.empty() || ligne[0]=='>'){
                if(!nom.empty()){
                    //cout << nom << ":" << contenu << endl;
                    nom.clear();
                }
                if(!ligne.empty()){
                    nom=ligne.substr(1); //On enleve le ">" et on retient le nom
                }
                contenu.clear();
            }
            else if(!nom.empty()){
                if(ligne.find(' ') != string::npos){ //si le find est different de "not found" alors on arrete
                    contenu.clear();
                    nom.clear();
                }
                else{
                    contenu += ligne;
                }
            }
        }
        
    }
    else{
        string pasouvert("Pas ouvert");
        cout << "Erreur dans l'ouverture du fichier"<<endl;
        return pasouvert;
    }
    return contenu;
}
