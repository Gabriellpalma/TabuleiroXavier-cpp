#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Jogador.h"
#include "Tabuleiro.h"
#include "windows.h"
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(0));
    char opcao;
    sjogador j1;
    sjogador j2;
    char tab[15][60];

    do{
    menuPrincipal(opcao);
    
    switch (opcao) {
            case '1':
                inicializarTabuleiro(tab);
                iniciarJogo(j1,j2,tab);
                break;
            case '2':
                imprimirHistorico();
                Sleep(1000);
                break;
            case '3':
                apagarHistorico();
                Sleep(1000);
                break;
            case '4':
                cout << "\nA sair do jogo..." << endl;
                exit(1);
                break;
            default:
                cout << "\nOpção inválida!" << endl;
                Sleep(1000);
                break;
        }
    }while(opcao != 4);



    return 0;
}
