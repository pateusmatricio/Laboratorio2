/**
 * @file jogador.cpp
 * @brief Implementação de Jogador.
 * @author Mateus Patricio
 * @date 31/03/2019
 */

#include <ostream>

#include "jogador.h"
#include "dado.h"

using namespace std;

/// @brief Construtor Parametrizado
Jogador::Jogador(string n):nome(n), pontuacao(0) {}

string Jogador::getNome(){
	return nome;
}

/// @brief Método que aumenta a pontuação no valor dos dois Dados recebiods como parametro
void Jogador::jogarDados(Dado &a, Dado &b){
	pontuacao += a.jogar() + b.jogar();
}

int Jogador::getPontuacao(){
	return pontuacao;
}

/// @brief Sobrecarga do operador << para mostragem na tela
ostream& operator<<(ostream &o, Jogador const &j){
	o << "Jogador: " << j.nome << "\nPontuação: " << j.pontuacao << "\n-----------------------\n";
}


Jogador::~Jogador(){
	
}