#include "configuracoes.h"

using namespace std;

void carregaRom(memoriaPrincipal *memoria){
	
	FILE *arq;
	arq = fopen(romName,"rb");
	int i;
	unsigned char c;
	
	for(i=0xF000;i<0xFFFF+1;i++){
		fread(&c,(char)sizeof(char),1,arq);
		
		memoria->bytes[i] = c;
	}
	
	
}
