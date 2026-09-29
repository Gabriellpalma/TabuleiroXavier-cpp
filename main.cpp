#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <windows.h>
#include "Jogador.h"
#include "Tabuleiro.h"
#include <conio.h>

// Estrutura para mapear as posições no tabuleiro do console
struct Posicao {
    int lin, col;
};

// Matriz do Tabuleiro em Texto
char tab[15][60];

// Vetor com as 28 CASAS exatas do percurso
Posicao caminho[28] = {
    {1, 2},  {1, 6},  {1, 10}, {1, 14}, {1, 18}, {1, 22}, {1, 26}, // Casas 0 a 6
    {3, 26}, {5, 26}, {7, 26},                                     // Casas 7 a 9
    {7, 22}, {7, 18}, {7, 14}, {7, 10}, {7, 6},  {7, 2},           // Casas 10 a 15
    {9, 2},  {11, 2},                                              // Casas 16 a 17
    {11, 6}, {11, 10},{11, 14},{11, 18},{11, 22},{11, 26},          // Casas 18 a 23
    {13, 26},{13, 30},{13, 34},{13, 38}                            // Casas 24 a 27 (Fim)
};


string nomeJ1 = "Jogador 1";
string nomeJ2 = "Jogador 2";

// Função para mudar a cor do texto no console
void mudarCor(int cor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, cor);
}

// Inicializa a matriz com o desenho do percurso de 28 casas
void inicializarTabuleiro() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 60; j++) {
            tab[i][j] = ' ';
        }
    }

    // Desenha as 28 casas no tabuleiro
    for (int i = 0; i < 28; i++) {
        if (i == 4 || i == 9 || i == 14 || i == 20) {
            tab[caminho[i].lin][caminho[i].col] = '?'; // Casas de eventos
        } else if (i == 27) {
            tab[caminho[i].lin][caminho[i].col] = 'F'; // Fim / OVER
        } else {
            tab[caminho[i].lin][caminho[i].col] = '[';
            tab[caminho[i].lin][caminho[i].col + 1] = ']';
        }
    }
}

// Imprime o tabuleiro simplificado com cores no console
void desenharTabuleiroConsole(sjogador& c, sjogador& c1) {
    system("cls");
    cout << "=========================================================\n";
    cout << "                  TABULEIRO XAVIER                       \n";
    cout << "=========================================================\n\n";

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 60; j++) {
            bool ehP = (i == caminho[c.posicao].lin && j == caminho[c.posicao].col);
            bool ehS = (i == caminho[c1.posicao].lin && j == caminho[c1.posicao].col);

            if (ehP && ehS) {
                mudarCor(13); // Roxo se ambos estiverem na mesma casa
                cout << "X";
            } else if (ehP) {
                mudarCor(12); // Vermelho para Jogador 1 (P)
                cout << "P";
            } else if (ehS) {
                mudarCor(9);  // Azul para Jogador 2 (S)
                cout << "S";
            } else {
                if (tab[i][j] == '?') {
                    mudarCor(14); // Amarelo para eventos
                } else {
                    mudarCor(7);  // Branco padrão
                }
                cout << tab[i][j];
            }
        }
        cout << "\n";
    }
    mudarCor(7);
    cout << "\nLegenda: ";
    mudarCor(12); cout << "P"; mudarCor(7); cout << " = " << nomeJ1 << " | ";
    mudarCor(9);  cout << "S"; mudarCor(7); cout << " = " << nomeJ2 << " | ";
    mudarCor(14); cout << "?"; mudarCor(7); cout << " = Especial | ";
    mudarCor(13); cout << "X"; mudarCor(7); cout << " = Ambos na mesma casa\n";
    cout << "=========================================================\n\n";
}


//função de
void roleta( sjogador &jogador){
int giro= rand()% 8;
if (giro==0){
cout<<"Alcides passou 3 lista de exercício, volte 3 casas."<< endl;
jogador.posicao-=3;
return;
}
else if(giro==1){
    cout<<"Você não entendeu nada da aula, perdeu 5 de vida."<< endl;
    jogador.vida-=5;
    return;
}
else if(giro==2){
    cout<<"Alcides passou 5 lista de exercício, volte 5 casas."<< endl;
jogador.posicao-=5;
return;
}
else if(giro==3){
     cout<<"Você não respondeu as atividades e perdeu 10 de vida."<< endl;
    jogador.vida-=10;
    return;
    }
}
// Funções de Gestão do Histórico
void historicoDePartidas(sjogador j1, sjogador j2, string ganhador) {
    ofstream historico("Historico.txt", ios::app);
    if (historico.is_open()) {
        historico << j1.nome << " VS " << j2.nome << " | Vencedor: " << ganhador << endl;
        historico.close();
        cout << "\n[Histórico] Partida registada com sucesso!" << endl;
    }
}

void imprimirHistorico() {
    system("cls");
    ifstream historico("Historico.txt");
    string linha;
    cout << "--- HISTÓRICO DE PARTIDAS ---\n" << endl;
    if (historico.is_open()) {
        bool vazio = true;
        while (getline(historico, linha)) {
            cout << linha << endl;
            vazio = false;
        }
        if (vazio) cout << "O histórico está vazio." << endl;
        historico.close();
    } else {
        cout << "Nenhum histórico encontrado." << endl;
    }
    cout << "\nPressione ENTER para voltar ao menu...";
    cin.ignore();
    cin.get();
}

void apagarHistorico() {
    ofstream historico("Historico.txt", ios::trunc);
    if (historico.is_open()) {
        historico.close();
        cout << "\nHistórico apagado com sucesso!" << endl;
    }
    Sleep(1500);
}

// Lógica Principal do Jogo
void iniciarJogo() {
    // 1. Instanciar os objetos da struct para cada jogador
    sjogador j1;
    sjogador j2;

    j1.posicao = 0;
    j1.vida = 100; // Defina a vida inicial (ex: 100)

    j2.posicao = 0;
    j2.vida = 100;

    bool fimDeJogo = false;
    string vencedor = "";

    inicializarTabuleiro();

    // Sorteia quem começa
    int turno = (rand() % 2) + 1;

    cout << "\nDigite o nome do Jogador 1 (P): ";
    cin >> j1.nome;
    cout << "Digite o nome do Jogador 2 (S): ";
    cin >> j2.nome;
    
    
    cout <<"Aperte qualquer tecla para dar inicio a partida:" << endl;
    getch();

    while (!fimDeJogo) {
             
        desenharTabuleiroConsole(j1, j2);

        // Identifica qual é o objeto do jogador atual
        string nomeAtual = (turno == 1) ? j1.nome : j2.nome;
        cout << "Vez de " << nomeAtual << " (Pressione ENTER para jogar o dado)..." << endl;
        cin.get();

        int dado = (rand() % 6) + 1;
        cout << nomeAtual << " tirou o numero: " << dado << endl;

        if (turno == 1) {
            // Atualiza a posição do Jogador 1
            j1.posicao += dado;

            // Chama a roleta passando a struct do Jogador 1
            if (j1.posicao == 4 || j1.posicao == 9 || j1.posicao == 14 || j1.posicao == 20) {
                cout << "\nCAIU NUMA CASA ESPECIAL!\n";
                roleta(j1);
            }

            // Evita posições negativas caso a roleta mande recuar
            if (j1.posicao < 0) j1.posicao = 0;

            // Verifica vitória
            if (j1.posicao >= 27 || j2.vida <= 0) {
                j1.posicao = 27;
                vencedor = j1.nome;
                cout << "Fim de Jogo! vencedor:"  << vencedor <<endl;
                historicoDePartidas(j1, j2,vencedor);
                fimDeJogo = true;
                getch();
                
            }
            turno = 2;

        } else {
            // Atualiza a posição do Jogador 2
            j2.posicao += dado;

            // Chama a roleta passando a struct do Jogador 2
            if (j2.posicao == 4 || j2.posicao == 9 || j2.posicao == 14 || j2.posicao == 20) {
                cout << "\nCAIU NUMA CASA ESPECIAL!\n";
                roleta(j2);
            }

            // Evita posições negativas
            if (j2.posicao < 0) j2.posicao = 0;

            // Verifica vitória
            if (j2.posicao >= 27 || j1.vida <= 0) {
                j2.posicao = 27;
                vencedor = j2.nome;
                cout << "Fim de Jogo! vencedor:"  << vencedor <<endl;
                 historicoDePartidas(j1, j2,vencedor);
                fimDeJogo = true;
                getch();
                return;
            }
            turno = 1;
        }
        cout << "Aperte qualquer tecla para passar o seu turno:" << endl;
        getch();
        Sleep(1000);
        
    }
}
// Menu Principal Corrigido
void menuPrincipal() {
    char opcao;
    do {
        system("cls");
        cout << "*********************************************\n";
        cout << "            TABULEIRO XAVIER                 \n";
        cout << "*********************************************\n";
        cout << "1 - Iniciar Novo Jogo\n";
        cout << "2 - Visualizar Histórico de Partidas\n";
        cout << "3 - Apagar Histórico\n";
        cout << "4 - Sair\n";
        cout << "Escolha uma opçao: ";
        cin >> opcao;

        switch (opcao) {
            case '1':
                iniciarJogo();
                break;
            case '2':
                imprimirHistorico();
                break;
            case '3':
                apagarHistorico();
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
    } while (opcao != 4);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(0));

    menuPrincipal();

    return 0;
}
