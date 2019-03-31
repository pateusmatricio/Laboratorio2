/**
 * @author Mateus Patricio
 * @date 31/03/2019
 * 
 * @brief Programa que cria jogadores para jogarem um jogo de dados
 * @mainpage Jogo de Dados
 * @section intro_sec Introdução
 * Este é segundo programa requerido na atividade de laboratório 1, no qual o usuário, 
 	através de um menu, irá criar jogadores até decidir começar o jogo, no qual ele decide
 	entre jogar os dados ou parar. Vence o ultimo Jogador com a maior pontuação abaixo da 
 	pontuação máxima ou aquele que acumular pontos iguais a pontuação máxima. 
 	Para resolução da atividade foram usados os conceitos de orientação a objetos 
 	aprendidos em sala.
 */

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