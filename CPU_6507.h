/*
 * CPU.h
 *
 *  Created on: 5 de jun de 2017
 *      Author: eberr
 */
 



#ifndef CPU_6507_H_
#define CPU_6507_H_

class CPU_6507 {


public:

	//flags (NV-BDIZC);
	unsigned char N,V,D,I,Z,C;

	//registradores
	unsigned char A,X,Y,S,PC;

	unsigned char buscaInstrucao(struct cartRom *rom);

	void decodificaInstrucao(cartRom *rom, unsigned char c);

	void executa();


private:


};

#endif /* 6507_H_ */
