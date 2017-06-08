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
	
	switch (c){
		
		
	/**************************
	 * ADC (ADd with Carry)
	 * Affects Flags: S V Z C
	 *************************/

	//mode imediate Len 2 Tim 2
	case 0x69:
		printf("ADC (ADd with Carry) mode imediate Len 2 Tim 2\n");
		this->memPointer++;
		break;
	
	//mode Zero Page Len 2 Tim 3
	case 0x65:
		printf("ADC (ADd with Carry) mode Zero Page Len 2 Tim 3\n");
		this->memPointer++;
		break;

	//mode Zero Page,X Len 2 Tim 4
	case 0x75:
		printf("ADC (ADd with Carry) mode Zero Page,X Len 2 Tim 4\n");
		this->memPointer++;
		break;
		
	//mode Absolute Len 3 Tim 4
	case 0x6D:
		printf("ADC (ADd with Carry) mode Absolute Len 3 Tim 4\n");
		this->memPointer++;
		break;
		
	//mode Absolute,X Len 3 Tim 4+
	case 0x7D:
		printf("ADC (ADd with Carry) mode Absolute,X Len 3 Tim 4+\n");
		this->memPointer++;
		break;
		
	//mode Absolute,Y Len 3 Tim 4
	case 0x79:
		printf("ADC (ADd with Carry) mode Absolute,Y Len 3 Tim 4+\n");
		this->memPointer++;
		break;
		
	//mode Indirect,X Len 2 Tim 6
	case 0x61:
		printf("ADC (ADd with Carry) mode Indirect,X Len 2 Tim 6\n");
		this->memPointer++;
		break;
		
	//mode Indirect,Y Len 2 Tim 5+
	case 0x71:
		printf("ADC (ADd with Carry) mode Indirect,Y Len 2 Tim 5+\n");
		this->memPointer++;
		break;
		
		
		
		
		
		
		
		
		case 0x4C:
			printf("JMP Absolute\n");
			this->memPointer++;
			this->memPointer++;
		break;
		
		
		case 0xA2:	
			printf("LDX imediate\n");
			this->memPointer++;
		break;
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


