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

	//flags (NV-BDIZC) (Processor Status);
	uint8_t flags;

	//registradores
	uint8_t A,X,Y,StackPointer;

	//apontador para a posi��o atual da memoria;
	uint16_t memPointer;

	//ponteiro para a memoria
	struct memoriaPrincipal *memoria;

	//construtor
	CPU_6507(memoriaPrincipal *mem);


	void escreveMemoria(uint16_t addr, uint8_t value);
	uint8_t leMemoria(uint16_t addr);

	uint8_t buscaInstrucao();

	void decodificaInstrucao(uint8_t c);

	void executa();

    void clearFlag(char flag);
	void setFlag(char flag);


private:


};

#endif /* 6507_H_ */
