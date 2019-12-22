all: main clean

main: main.o Fasta_To_Bits.o Score.o ouverture.o comparaison.o binaire.o Sequence.o Offsets.o SwipeAlgo.o header.o
	g++ -O3 -std=c++11 main.o Fasta_To_Bits.o Score.o ouverture.o comparaison.o binaire.o Sequence.o Offsets.o SwipeAlgo.o header.o -lpthread -o main

Fasta_To_Bits.o: Fasta_To_Bits.cpp Fasta_To_Bits.hpp
	g++ -O3 -std=c++11 -c Fasta_To_Bits.cpp

Score.o: Score.cpp Score.hpp
	g++ -O3 -std=c++11 -c Score.cpp

ouverture.o: ouverture.cpp ouverture.hpp
	g++ -O3 -std=c++11 -c ouverture.cpp

comparaison.o: comparaison.cpp comparaison.hpp
	g++ -O3 -std=c++11 -c comparaison.cpp

binaire.o: binaire.cpp binaire.h
	g++ -O3 -std=c++11 -c binaire.cpp

Sequence.o: Sequence.cpp Sequence.hpp
	g++ -O3 -std=c++11 -c Sequence.cpp
	
Offsets.o: Offsets.cpp Offsets.hpp
	g++ -O3 -std=c++11 -c Offsets.cpp
	
SwipeAlgo.o: SwipeAlgo.cpp SwipeAlgo.hpp
	g++ -O3 -std=c++11 -c SwipeAlgo.cpp
	
header.o: header.cpp header.h
	g++ -O3 -std=c++11 -c header.cpp

clean:
	rm -f *.o
