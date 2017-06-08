#include <stdio.h>
#include <iostream>
#include "CPU_6507.h"
#include "estruturas.h"
#include "configuracoes.h"
#include "funcoes.h"

using namespace std;




int main() {

// variaveis auxiliares
	unsigned char c;
	int i;
	

//classe CPU	
	CPU_6507 s;

//estrutura da memoria principal
	memoriaPrincipal memoria;

//função para carregar a rom na memoria principal
	carregaRom(&memoria);	




// testes
	for (i=0;i<19;i++){
		
		c = s.buscaInstrucao(memoria);
		
		s.decodificaInstrucao(c);
		
	}


	return 0;
}



