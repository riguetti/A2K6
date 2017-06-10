/*
 * CPU.h
 *
 *  Created on: 5 de jun de 2017
 *      Author: eber
 */




#ifndef CPU_6507_H_
#define CPU_6507_H_
#include <stdint.h>

using namespace std;
class CPU_6507 {


public:

	//flags (NV-BDIZC);
	uint8_t flags;

	//registradores
	uint8_t A,X,Y,S,PC;

	//apontador para a posição atual da memoria;
	uint16_t memPointer;

	//ponteiro para a memoria
	struct memoriaPrincipal *memoria;

	//construtor
	CPU_6507(memoriaPrincipal *mem);

	uint8_t buscaInstrucao();

	void decodificaInstrucao(uint8_t c);

	void executa();

    void clearFlag(char flag);
	void setFlag(char flag);


private:


};

#endif /* 6507_H_ */
