/*
 * CPU.cpp
 *
 *  Created on: 5 de jun de 2017
 *      Author: eberr
 */

#include "CPU_6507.h"
#include "estruturas.h"
#include <stdio.h>
#include <stdint.h>

using namespace std;

 CPU_6507::CPU_6507(memoriaPrincipal *mem){

 	this->memoria = mem;
	this->memPointer = 0xF000;

}


//Seta as flags
void CPU_6507::setFlag(char flag){

switch (flag){

//Carry flag
case 'C':
this->flags = this->flags | 0x01;
    break;

//Zero flag
case 'Z':
this->flags = this->flags | 0x02;
    break;

//Interrupt flag
case 'I':
this->flags = this->flags | 0x04;
    break;

//Decimal Flag
case 'D':
this->flags = this->flags | 0x08;
    break;

    //Set when software interrupt (BRK instruction)
case 'B':
this->flags = this->flags | 0x10;
    break;

    //not used. Supposed to be logical 1 at all times
case '-':
this->flags = this->flags | 0x20;
    break;

    //Overflow flag
case 'V':
this->flags = this->flags | 0x40;
    break;

    //Sign flag: this is set if the result of an operation is negative, cleared if positive
case 'N':
this->flags = this->flags | 0x80;
    break;

}


}




//Seta as flags
void CPU_6507::clearFlag(char flag){

switch (flag){

//Carry flag
case 'C':
this->flags = this->flags & 0xFE;
    break;

//Zero flag
case 'Z':
this->flags = this->flags & 0xFD;
    break;

//Interrupt flag
case 'I':
this->flags = this->flags & 0xFB;
    break;

//Decimal Flag
case 'D':
this->flags = this->flags & 0xF7;
    break;

    //Set when software interrupt (BRK instruction)
case 'B':
this->flags = this->flags & 0xEF;
    break;

    //not used. Supposed to be logical 1 at all times
case '-':
this->flags = this->flags & 0xDF;
    break;

    //Overflow flag
case 'V':
this->flags = this->flags & 0xBF;
    break;

    //Sign flag: this is set if the result of an operation is negative, cleared if positive
case 'N':
this->flags = this->flags & 0x7F;
    break;

}

}






uint8_t CPU_6507::buscaInstrucao(){

 	uint8_t c;
 //	c = memoria.bytes[this->memPointer];

 	c = this->memoria->bytes[this->memPointer];
 	this->memPointer++;
 	return c;

}


// apenas teses ainda
void CPU_6507::decodificaInstrucao(uint8_t c){
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






	/**************************
	 * JMP (JuMP)
	 * Affects Flags: none
	 *************************/


		//mode Absolute Len 3 Tim 3
		case 0x4C:
		printf("JMP (JuMP) mode Absolute Len 3 Tim 3\n");

			uint8_t adressFim;
			uint8_t adressIni;

			// carrega os dois proximos bytes que representam o endereço da mémoria
			adressFim = this->buscaInstrucao();
			adressIni = this->buscaInstrucao();

			// seta o memPointer com o novo valor da memoria
			this->memPointer = adressIni << 8;
			this->memPointer = this->memPointer | adressFim;


		break;

		//mode Indirect Len 3 Tim 5
		case 0x6C:
		printf("JMP (JuMP) mode Indirect Len 3 Tim 5\n");
            // carrega os dois proximos bytes que representam o endereço da mémoria
			adressFim = this->buscaInstrucao();
			adressIni = this->buscaInstrucao();

			// seta o memPointer com o novo valor da memoria
			this->memPointer = adressIni << 8;
			this->memPointer = this->memPointer | adressFim;

            // carrega os dois proximos bytes que representam o endereço da mémoria
			adressFim = this->buscaInstrucao();
			adressIni = this->buscaInstrucao();

			// seta o memPointer com o novo valor da memoria
			this->memPointer = adressIni << 8;
			this->memPointer = this->memPointer | adressFim;


		break;

    /**************************
	* Flag (Processor Status) Instructions
	* Affects Flags: depends
	*************************/
        //CLC (CLear Carry)
		case 0x18:
		printf("CLC (CLear Carry) Flag Instructions\n");
		this->clearFlag('C');
		break;

        //SEC (SEt Carry)
		case 0x38:
		printf("SEC (SEt Carry) Flag Instructions\n");
		this->setFlag('C');
		break;

        //CLI (CLear Interrupt)
		case 0x58:
		printf("CLI (CLear Interrupt) Flag Instructions\n");
		this->clearFlag('I');
		break;

		//SEI (SEt Interrupt)
		case 0x78:
		printf("SEI (SEt Interrupt) Flag Instructions\n");
		this->setFlag('I');
		break;

        //CLV (CLear oVerflow)
		case 0xB8:
		printf("CLV (CLear oVerflow) Flag Instructions\n");
		this->clearFlag('V');
		break;

		//CLD (CLear Decimal)
		case 0xD8:
		printf("CLD (CLear Decimal) Flag Instructions\n");
		this->clearFlag('D');
		break;


		//SED (SEt Decimal)
		case 0xF8:
		printf("SED (SEt Decimal) Flag Instructions\n");
		this->setFlag('D');
		break;


    /**************************
	* Register Instructions
	* Affects Flags: S Z
	*************************/

        //TAX (Transfer A to X)
		case 0xAA:
		printf("TAX (Transfer A to X) Register Instructions\n");
        this->X = this->A;
		break;

        //TXA (Transfer X to A)
		case 0x8A:
		printf("TXA (Transfer X to A) Register Instructions\n");
        this->A = this->X;
		break;

        //DEX (DEcrement X)
		case 0xCA:
		printf("DEX (DEcrement X) Register Instructions\n");
        this->X--;
		break;

        //INX (INcrement X)
		case 0xE8:
		printf("INX (INcrement X) Register Instructions\n");
        this->X++;
		break;

        //TAY (Transfer A to Y)
		case 0xA8:
		printf("TAY (Transfer A to Y) Register Instructions\n");
        this->Y = this->A;
		break;


        //TYA (Transfer Y to A)
		case 0x98:
		printf("TYA (Transfer Y to A) Register Instructions\n");
        this->A = this->Y;
		break;



        //DEX (DEcrement Y)
		case 0x88:
		printf("DEY (DEcrement Y) Register Instructions\n");
        this->Y--;
		break;

        //INX (INcrement Y)
		case 0xC8:
		printf("INY (INcrement Y) Register Instructions\n");
        this->Y++;
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


