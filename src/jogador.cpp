#include <ostream>

#include "jogador.h"
#include "dado.h"

using namespace std;

Jogador::Jogador(string n):nome(n), pontuacao(0) {}

string Jogador::getNome(){
	return nome;
}

void Jogador::jogarDados(Dado &a, Dado &b){
	pontuacao += a.jogar() + b.jogar();
}

int Jogador::getPontuacao(){
	return pontuacao;
}

ostream& operator<<(ostream &o, Jogador const &j){
	o << "Jogador: " << j.nome << "\nPontuação: " << j.pontuacao << "\n-----------------------\n";
}


Jogador::~Jogador(){
	
}