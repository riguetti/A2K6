#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include "CPU_6507.h"
#include "estruturas.h"
#include "configuracoes.h"
#include "funcoes.h"

using namespace std;




int main() {

// variaveis auxiliares
	uint8_t c;
	int i;
	



//estrutura da memoria principal
	memoriaPrincipal memoria;
	
	
	//classe CPU	
	CPU_6507 s(&memoria);

//função para carregar a rom na memoria principal
	carregaRom(&memoria);	




// testes
	for (i=0;i<19;i++){
		
		c = s.buscaInstrucao();
		
		s.decodificaInstrucao(c);
		
	}


	return 0;
}



