/*
 * CPU.h
 *
 *  Created on: 5 de jun de 2017
 *      Author: eber
 */
 



#ifndef CPU_6507_H_
#define CPU_6507_H_


class CPU_6507 {


public:

	//flags (NV-BDIZC);
	unsigned char N,V,D,I,Z,C;

	//registradores
	unsigned char A,X,Y,S,PC;
	
	//apontador para a posição atual da memoria;
	int memPointer = 0xF000;


	//construtor
	CPU_6507();
	
	unsigned char buscaInstrucao(struct memoriaPrincipal memoria);

	void decodificaInstrucao(unsigned char c);

	void executa();


private:


};

#endif /* 6507_H_ */
