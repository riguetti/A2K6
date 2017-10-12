#include "configuracoes.h"
//teste ---
using namespace std;

void carregaRom(memoriaPrincipal *memoria){

	FILE *arq;
	arq = fopen(romName,"rb");
	int i;
	uint8_t c;

	for(i=0xF000;i<0xFFFF+1;i++){
		fread(&c,(char)sizeof(char),1,arq);

		memoria->bytes[i] = c;
	}


}


//função apenas para debugar!!!!!!!!!!!!!
//imprime um byte na tela
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */

const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

   return b;
}
