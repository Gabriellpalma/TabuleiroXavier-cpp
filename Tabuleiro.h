#ifndef FUNCOES_JOGO
#define FUNCOES_JOGO
#include "Jogador.h"
#include <iostream>
#include <string>
//Biblioteca Gráfica e Menu{
void mudarCor(int cor);
void menuPrincipal(char& opcao);
//}

//Funções da lógica do jogo{
void eventosEspeciais( sjogador &jogador);
void eventosEspeciais(sjogador &jogador, sjogador &adversario, bool ehJ1,bool &rodadaP, bool &rodadaS, bool &doisDadosP, bool &doisDadosS, bool &roletaP, bool &roletaS, bool &somaDadosP, bool &somaDadosS);
void iniciarJogo(sjogador j1, sjogador j2, char tab [][60]);
void desenharTabuleiroConsole(sjogador& j1, sjogador& j2, char tab [][60]);
void inicializarTabuleiro(char tab[][60]);
//

// Funções de manipulação de arquivos{
void apagarHistorico();
void imprimirHistorico();
void historicoDePartidas(sjogador j1, sjogador j2, string ganhador);
// 
#endif