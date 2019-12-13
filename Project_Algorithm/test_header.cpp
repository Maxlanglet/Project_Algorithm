#include "header.cpp"

int main(int argc, char* argv[]){
    Header head("uniprot_sprot.fasta.phr");
    head.open_fichier();
    head.test_fichier();
    head.close_fichier();
}
