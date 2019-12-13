all: main clean

main: main.o Fasta_To_Bits.o Score.o ouverture.o comparaison.o binaire.o Sequence.o Offsets.o blosum.o SwipeAlgo.o header.o
	g++ -Ofast main.o Fasta_To_Bits.o Score.o ouverture.o comparaison.o binaire.o Sequence.o Offsets.o blosum.o SwipeAlgo.o header.o -o main 

Fasta_To_Bits.o: Fasta_To_Bits.cpp Fasta_To_Bits.hpp
	g++ -c -O3 -Ofast Fasta_To_Bits.cpp 

Score.o: Score.cpp Score.hpp
	g++ -c -O3 -Ofast Score.cpp

ouverture.o: ouverture.cpp ouverture.hpp
	g++ -c -O3 -Ofast ouverture.cpp

comparaison.o: comparaison.cpp comparaison.hpp
	g++ -c -O3 -Ofast comparaison.cpp

binaire.o: binaire.cpp binaire.h
	g++ -c -O3 -Ofast binaire.cpp

Sequence.o: Sequence.cpp Sequence.hpp
	g++ -c -O3 -Ofast Sequence.cpp
	
Offsets.o: Offsets.cpp Offsets.hpp
	g++ -c -O3 -Ofast Offsets.cpp
	
blosum.o: blosum.cpp blosum.hpp
	g++ -c -O3 -Ofast blosum.cpp
	
SwipeAlgo.o: SwipeAlgo.cpp SwipeAlgo.hpp
	g++ -c -O3 -Ofast SwipeAlgo.cpp
	
header.o: header.cpp header.h
	g++ -c -O3 -Ofast header.cpp

clean:
	rm -f *.o
