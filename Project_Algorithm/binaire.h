#ifndef binaire_h
#define binaire_h
#include "comparaison.hpp"

class Binaire
{
private :
	string adresse;
	
	
public : 
	Binaire(string adr);
	//void setAdresse(string adresse);
	string getAdresse();
	void open_fichier();
	void test_fichier();
	void close_fichier();
	ifstream f;
};

#endif
