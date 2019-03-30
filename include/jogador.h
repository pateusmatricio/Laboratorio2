#ifndef JOGADOR_H
#define JOGADOR_H

#include <ostream>

#include "dado.h"

using namespace std;

class Jogador{
	private:
		string nome;
		int pontuacao;

	public:
		static int pontuacaoMaxima;

		Jogador(string n);
		~Jogador();
		string getNome();
		void jogarDados(Dado &a, Dado &b);
		int getPontuacao();

		friend ostream& operator<< (ostream &o, Jogador const &j);

};

#endif