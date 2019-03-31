/**
 * @file jogo.cpp
 * @brief Implementação de Jogo.
 * @author Mateus Patricio
 * @date 31/03/2019
 */

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <random>

#include "dado.h"
#include "jogador.h"

using namespace std;

/// @detail Função que faz a lógica do jogo, recebendo como parâmetro a pontuação máxima dos jogadores e um char com a escolha de jogar de novo ou não, que começa como 'S' 
void jogo(int &pontuacaoMaxima, char opc){
	int i = 42;
	string aux;
	string name;
	vector<Jogador> players;
	vector<Jogador> ranking;

	while(i != 0){

		while(players.size() < 2 || i == 1){
			cout << "Digite o nome do jogador número " << players.size() + 1 << endl;
			getline(cin, name);
			players.push_back(Jogador(name));
			i = 42;
		}

		while(i != 0 && i != 1){
			cout << "Digite 1 para adicionar outro jogador ou 0 para começar o jogo" << endl;
				getline(cin, aux);
				stringstream(aux) >> i;
		}

	}

	int tamanho = players.size();

	cout << "\n---------------------------Lista de Jogadores---------------------------\n" << endl;
	for (int i = 0; i < tamanho; i++){
		cout << players[i];
 	}


	cout << "\n---------------------------COMEÇO DA RODADA----------------------------\n" << endl;


	Dado dado1;
	Dado dado2;
	int opcao = 42;
	bool alguemParou; //variavel pra dizer se alguem parou naquela rodada

	while(tamanho > 1){

		for(i = 0; i < tamanho; i++){
			
			alguemParou = false;

			cout << "Vez de " << players[i].getNome() <<"(" << players[i].getPontuacao() << " pontos)!" << endl;
			while(opcao != 2 && opcao != 1){
				cout << "(1) Jogar dados" << endl;
				cout << "(2) Não jogar dados" << endl;
				cout << "(3) Pontuação Limite" << endl;
				getline(cin, aux);
				stringstream(aux) >> opcao;
				switch(opcao){
					case 1:
						players[i].jogarDados(dado1, dado2);
						cout << "Dado 1: " << dado1.getValor() << endl << "Dado 2: " << dado2.getValor() << endl;
						break;
					case 2:
						cout << "\nO jogador " << players[i].getNome() << " decide parar com " << players[i].getPontuacao() << " pontos!" << endl;
						alguemParou = true;
						break;
					case 3:
						cout << "A pontuação Limite é: " << pontuacaoMaxima << endl;
						break;
					default:
						cout << "Opção inválida!" << endl;
						break;
				}
			}
			opcao = 42;

			if(alguemParou == true){
				ranking.push_back(players[i]);
				players.erase(players.begin() + i);
					
				tamanho--;
				i--; //pq quando eu removo um elemento, o proximo toma o lugar do anterior
			}
			else if(players[i].getPontuacao() < pontuacaoMaxima && alguemParou == false){
				cout << "\nO jogador " << players[i].getNome() << " fez " << players[i].getPontuacao() << " pontos!" << endl;
			}
			else if(players[i].getPontuacao() > pontuacaoMaxima){
				cout << "\nO jogador " << players[i].getNome() << " fez " << players[i].getPontuacao() << " pontos e ultrapassou a pontuação máxima " << pontuacaoMaxima << " e por isso foi desclassificado." << endl;
				ranking.push_back(players[i]);
				players.erase(players.begin() + i);
				tamanho--;
				i--;
			}

			if(tamanho == 1){
				cout << "\nO jogador " << players[i].getNome() << " é o ultimo jogador ativo no jogo e por isso é o vencedor!" << endl;
				ranking.push_back(players[i]);	
				players.erase(players.begin() + i);
				tamanho--;
				i--;
			}
			else if(players[i].getPontuacao() == pontuacaoMaxima){
				cout << "\nO jogador " << players[i].getNome() << " fez exatamente " << players[i].getPontuacao() << " pontos que é a pontuação desejada e por isso ganhou!!1!" << endl;
				
				for (int j = 0; j < tamanho; j++){
					if(j != i){
						ranking.push_back(players[j]);	//adiciona os outros jogadores ao ranking
						players.erase(players.begin() + j); //remove os outros jogadores do vetor de jogadores
					}
				}
				ranking.push_back(players[i]);	//coloca o vencedor no fim
				players.erase(players.begin() + i);//apaga o vencedor do vetor
				tamanho--;
				i--;	
				break;
			}

			cout << "\n-------------------------------------------------------\n" << endl;

		}

	}
	
	cout << "\n---------------------------FIM DA RODADA----------------------------\n" << endl;

	tamanho = ranking.size();

	cout << "O ranking final ficou assim:" << endl;
	for (int i = tamanho; i > 0; i--){
		cout << "(" << tamanho - i + 1 << ")" << ranking[i-1];
 	}

	while(opc != 'n' && opc != 'N'){
		cout << "\nDeseja jogar novamente,(S)im ou (N)ão?" << endl;
		
		getline(cin, aux);
		stringstream(aux) >> opc;
		
		if(opc == 's' || opc == 'S'){
			jogo(pontuacaoMaxima, 'S');
		}
		else if(opc == 'n' || opc == 'N')
			cout << "Thanks for playing!!" << endl;
		else
			cout << "Opção inválida!" << endl;
	}


}