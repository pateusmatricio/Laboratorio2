#include <iostream>
#include <vector>

#include "jogador.h"
#include "jogo.h"

using namespace std;

int Jogador::pontuacaoMaxima = 50;

int main(int argc, char const *argv[]){
	
	jogo(Jogador::pontuacaoMaxima, 'S');
	
	return 0;
}