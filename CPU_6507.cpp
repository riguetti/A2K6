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

 CPU_6507::CPU_6507(){
//	this->memPointer = 0xF000;
}

unsigned char CPU_6507::buscaInstrucao(struct memoriaPrincipal memoria){

 	unsigned char c;
 	c = memoria.bytes[this->memPointer];
 	this->memPointer++;
 	return c;

}


// apenas teses ainda
void CPU_6507::decodificaInstrucao(unsigned char c){
	
	
	printf("%02X  ",c);
	
if (c == 0x4C){
	
	printf("JMP Absolute\n");
	this->memPointer++;
	this->memPointer++;

}


if (c == 0xA2){
	
	printf("LDX imediate\n");
	this->memPointer++;

}

if (c == 0x85){
	
	printf("STA zero page\n");
	this->memPointer++;
}

if (c == 0xA4){
	
	printf("LDY zero page\n");
	this->memPointer++;
}

if (c == 0xB1){
	
	printf("LDA Indirect, Y\n");
	this->memPointer++;
}

if (c == 0xA0){
	
	printf("LDY Immediate, Y\n");
	this->memPointer++;
}

if (c == 0xA5){
	
	printf("LDA zero page\n");
	this->memPointer++;
}

if (c == 0xC9){
	
	printf("CMP immediate\n");
	this->memPointer++;
}

if (c == 0xD0){
	
	printf("BNE Branch on Not Equal\n");
	this->memPointer++;
}

if (c == 0x01){
	
	printf("ORA (bitwise OR with Accumalator Indirect,Y)\n");
	this->memPointer++;
}

if (c == 0x88){
	
	printf("DEY decrement Y (register instructions)\n");
	//rom->actPos++;
}

if (c == 0xFD){
	
	printf("SBC Absolute, X (subtract with carry)\n");
	this->memPointer++;
	this->memPointer++;
}

if (c == 0x0E){
	
	printf("ASL Absolute (subtract with carry)\n");
	this->memPointer++;
	this->memPointer++;
}

if (c == 0xCA){
	
	printf("DEX Decrement X (register instructions)\n");
//	rom->actPos++;

}


}

void CPU_6507::executa(){


}


