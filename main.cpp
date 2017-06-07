#include <stdio.h>
#include <iostream>
#include "CPU_6507.h"
#include "estruturas.h"
#include "configuracoes.h"
#include "funcoes.h"

using namespace std;




int main() {

	char c;
	CPU_6507 s;
	
	cartRom rom;
	
	readCart(&rom);

//	c = s.buscaInstrucao(&rom);

	int i;
	for (i=0;i<19;i++){
		
		s.decodificaInstrucao(&rom, s.buscaInstrucao(&rom));
		
	}

//	s.decodificaInstrucao(&rom, c);

//	printf("%02x",s.buscaInstrucao(&rom));


	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	while (cin.get() != '\n');
	return 0;
}



