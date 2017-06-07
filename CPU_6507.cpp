/*
 * CPU.cpp
 *
 *  Created on: 5 de jun de 2017
 *      Author: eberr
 */

#include "CPU_6507.h"
#include "estruturas.h"
#include <stdio.h>

using namespace std;



unsigned char CPU_6507::buscaInstrucao(cartRom *rom){

 	unsigned char c;
 	
 	c = rom->mem[rom->actPos];
 	rom->actPos++;
 	return c;

}


void CPU_6507::decodificaInstrucao(cartRom *rom, unsigned char c){
	
	
		printf("%02X  ",c);
	
if (c == 0x4C){
	
	printf("JMP Absolute\n");
	rom->actPos++;
	rom->actPos++;
}


if (c == 0xA2){
	
	printf("LDX imediate\n");
	rom->actPos++;
}

if (c == 0x85){
	
	printf("STA zero page\n");
	rom->actPos++;
}

if (c == 0xA4){
	
	printf("LDY zero page\n");
	rom->actPos++;
}

if (c == 0xB1){
	
	printf("LDA Indirect, Y\n");
	rom->actPos++;
}

if (c == 0xA0){
	
	printf("LDY Immediate, Y\n");
	rom->actPos++;
}

if (c == 0xA5){
	
	printf("LDA zero page\n");
	rom->actPos++;
}

if (c == 0xC9){
	
	printf("CMP immediate\n");
	rom->actPos++;
}

if (c == 0xD0){
	
	printf("BNE Branch on Not Equal\n");
	rom->actPos++;
}

if (c == 0x01){
	
	printf("ORA (bitwise OR with Accumalator Indirect,Y)\n");
	rom->actPos++;
}

if (c == 0x88){
	
	printf("DEY decrement Y (register instructions)\n");
	//rom->actPos++;
}

if (c == 0xFD){
	
	printf("SBC Absolute, X (subtract with carry)\n");
	rom->actPos++;
	rom->actPos++;
}

if (c == 0x0E){
	
	printf("ASL Absolute (subtract with carry)\n");
	rom->actPos++;
	rom->actPos++;
}

if (c == 0xCA){
	
	printf("DEX Decrement X (register instructions)\n");
//	rom->actPos++;

}


}

void CPU_6507::executa(){


}


