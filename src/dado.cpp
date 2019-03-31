/**
 * @file dado.cpp
 * @brief Implementação de Dado.
 * @author Mateus Patricio
 * @date 31/03/2019
 */


#include <random>

#include "dado.h"

using namespace std;

Dado::Dado():rd(), gen(rd()), dis(1,6) {
	valor = round(dis(gen));
}

/// @brief Atribui um valor aleatorio ao atributo valor e o retorna
int Dado::jogar(){
	valor = round(dis(gen));
	return valor;
}

int Dado::getValor(){
	return valor;
}