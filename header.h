#ifndef header_h
#define header_h

#include "Offsets.hpp"

class Header : public Binaire
{
private:
	string nom;
	string base;
	int quantieme;
	int taxid;
	string read_string();
	int read_int();
	int Hex_Int(string hex, int size);
	
public :
	Header(string adr);
	void acquiert(int offset);
	void getData(ofstream* res);
	
	
	
};
#endif
