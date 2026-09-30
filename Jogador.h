#ifndef STRUCT_JOGADOR
#define STRUCT_JOGADOR
using namespace std;
#include <string>
// Estrutura do Jogador    
    struct sjogador{
        string nome;
        int vida;
        int posicao;
    };

// Estrutura para mapear as posições no tabuleiro do console
    struct Posicao {
    int lin, col;
};
 

#endif