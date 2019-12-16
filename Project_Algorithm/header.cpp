#include "header.h"


//faut utiliser acquiert pour stocker les nom et int dans les bonnes variables
//utiliser getData pour imprimer le nom de la proteine et de la base de donnée ainsi que les int

Header::Header(string adr) : Binaire(adr),nom(""),base(""),quantieme(0),taxid(0){
	//Binaire(str);
	//nom = "";
	//base = "";
	//quantieme = 0;
	//taxid = 0;
}

string Header::read_string(){
	string res = "";
	
	int size = 0;
	f.read((char*)&size, 1);
	
	if(int(size) >= 128){
		
		int size2 = (size-128);
		//cout<<"long string, size2 : "<<size2<<endl;
		char* buffer = new char[size2];
		f.read(buffer,size2);
		
		stringstream ss;
		for(int i =0; i<size2; i++){
			ss<<setfill('0')<<setw(2)<<hex<<(0xff & (int)buffer[i]);
		}
		string mystr = ss.str();
		//cout<<"size size : "<<mystr<<endl;
		
		size = Hex_Int(mystr, size2);
        delete[] buffer;
		
	}
	
	char* text = new char[size]();
	f.read(text, size);
	
	res = string(text, (size));
	
    delete[] text;
	
	return res;
}

int Header::read_int(){
	int res = 0;
	
	char size = '0';
	f.read(&size,1);
	
	char* buffer = new char[(int)size];
	f.read(buffer,(int)size);
	
	std::stringstream ss;
	for(int i = 0;i<(int)size;i++){
		ss<<std::setfill('0')<<std::setw(2)<<hex<<(0xff & (int)buffer[i]);
	}
	string mystr = ss.str();
	res = Hex_Int(mystr, (int)size);
	
    delete[] buffer;
	
	return res;
}

void Header::acquiert(int offset){
	//open_fichier();
	f.seekg(offset);
	//int pos = f.tellg();
	int var = 0;
	char octet;
	while(var < 4){
		f.read(&octet, 1);
		if(int(octet) == 26){
			string str = read_string();
			if(var == 0){
				nom = str;
			}
			else if(var == 1){
				base = str;
			}
			var++;
		}
		if(int(octet) == 2){
			int nbr = read_int();
			if(var == 2){
				quantieme = nbr;
			}
			else if(var == 3){
				taxid = nbr;
			}
			var++;
		}
		
	}
}

void Header::getData(ofstream* res){
    //cout << left << base<<"|"<<quantieme<< setw(2) << nom << endl;
    //*res << left << "Sequence with significant alignements" << setw(20) << "Score(bits)" << endl;
    /*
	cout<<"nom proteine : "<<nom<<endl;
	cout<<"nom base de donnée : "<<base<<endl;
	cout<<"numero : "<<quantieme<<endl;
	cout<<"taxid : "<<taxid<<endl;
     */
    *res << left << base<<" | "<<quantieme<<" | "<<nom<<" | "<<taxid << setw(20) << " | score :";
    
}

int Header::Hex_Int(string hex, int size){
	size = 2*size;
	int res =0;
	for (int i = 0; i<size;i++){
		switch(hex[i]){
			case '0' : 
				res += 0;
				break;
			case '1' :
				res += 1*pow(16,size-1-i);
				break;
			case '2' :
				res += 2*pow(16,size-1-i);
				break;
			case '3' :
				res += 3*pow(16,size-1-i);
				break;
			case '4' :
				res += 4*pow(16,size-1-i);
				break;
			case '5' :
				res += 5*pow(16,size-1-i);
				break;
			case '6' :
				res += 6*pow(16,size-1-i);
				break;
			case '7' :
				res += 7*pow(16,size-1-i);
				break;
			case '8' :
				res += 8*pow(16,size-1-i);
				break;
			case '9' :
				res += 9*pow(16,size-1-i);
				break;
			case 'a' :
				res += 10*pow(16,size-1-i);
				break;
			case 'b' :
				res += 11*pow(16,size-1-i);
				break;
			case 'c' :
				res += 12*pow(16,size-1-i);
				break;
			case 'd' :
				res += 13*pow(16,size-1-i);
				break;
			case 'e' :
				res += 14*pow(16,size-1-i);
				break;
			case 'f' :
				res += 15*pow(16,size-1-i);
				break;
		}
	}
	return res;
}
