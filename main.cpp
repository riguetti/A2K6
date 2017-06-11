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





	for (i=0;i<6;i++){

		c = s.buscaInstrucao();
		s.decodificaInstrucao(c);

		printf("flags: %s",byte_to_binary(s.flags));
		printf("  ");
		printf("A: %02X",s.A);

        printf("  ");
		printf("X: %02X",s.X);

        printf("  ");
		printf("Y: %02X\n",s.Y);
		printf("\n");

	}


	for (i=0;i<20;i++){
        printf("%04X:  ",i);
        printf("%02X\n",s.memoria->bytes[i]);
	}

	return 0;
}



