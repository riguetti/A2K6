#include "configuracoes.h"

using namespace std;
void readCart(cartRom *rom){
	
	rom->actPos =0;
	
	FILE *arq;
	arq = fopen(romName,"rb");
	int i;
	unsigned char c;
	
	for (i=0;i<cartTam -1;i++){
		
		fread(&c,(char)sizeof(char),1,arq);
		
		rom->mem[i] = c;
				
		
	}


	fclose(arq);

}
