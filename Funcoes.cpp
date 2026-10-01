#ifndef FUNCOES_H
 #define FUNCOES_H
    #include "Tabuleiro.h"
    #include <iostream>
    #include <cstdlib>
    #include <ctime>
    #include <fstream>
    #include <windows.h>
    #include "Jogador.h"
    

// Vetor com as 28 CASAS exatas do percurso
Posicao caminho[28] = {
    {1, 2},  {1, 6},  {1, 10}, {1, 14}, {1, 18}, {1, 22}, {1, 26}, // Casas 0 a 6
    {3, 26}, {5, 26}, {7, 26},                                     // Casas 7 a 9
    {7, 22}, {7, 18}, {7, 14}, {7, 10}, {7, 6},  {7, 2},           // Casas 10 a 15
    {9, 2},  {11, 2},                                              // Casas 16 a 17
    {11, 6}, {11, 10},{11, 14},{11, 18},{11, 22},{11, 26},          // Casas 18 a 23
    {13, 26},{13, 30},{13, 34},{13, 38}                            // Casas 24 a 27 (Fim)
};

// Função para mudar a cor do texto no console
    void mudarCor(int cor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, cor);
}
// Menu Principal 
void menuPrincipal(char& opcao) {
    
    
        system("cls");
        cout << "*********************************************\n";
        cout << "            TABULEIRO XAVIER                 \n";
        cout << "*********************************************\n";
        cout << "1 - Iniciar Novo Jogo\n";
        cout << "2 - Visualizar Histórico de Partidas\n";
        cout << "3 - Apagar Histórico\n";
        cout << "4 - Sair\n";
        cout << "Escolha uma opçao: ";
        opcao = cin.get();
}

// Inicializa a matriz com o desenho do percurso de 28 casas
void inicializarTabuleiro(char tab[][60]) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 60; j++) {
            tab[i][j] = ' ';
        }
    }

    // Desenha as 28 casas no tabuleiro
    for (int i = 0; i < 28; i++) {
        if (i == 1 || i == 4 || i == 9 || i == 14 || i == 20 || i == 23 || i == 24 ||i == 26) {
            tab[caminho[i].lin][caminho[i].col] = '?'; // Casas de eventos
        } else if (i == 27) {
            tab[caminho[i].lin][caminho[i].col] = 'F'; // Fim / OVER
        } else {
            tab[caminho[i].lin][caminho[i].col] = '[';
            tab[caminho[i].lin][caminho[i].col + 1] = ']';
        }
    }
}


//Função de sortear eventos
void eventosEspeciais( sjogador &jogador)
{
int giro= rand()% 8;
if (giro==0){
    cout<<"Alcides passou 3 lista de exercício, volte 3 casas."<< endl;
    jogador.posicao-=3;

}
else if(giro==1){
    cout<<"Você não entendeu nada da aula, perdeu 15 de vida."<< endl;
    jogador.vida -= 15;
    
}
else if(giro==2){
    cout<<"Alcides passou 5 lista de exercício, volte 5 casas."<< endl;
    jogador.posicao -= 5;
    
}
else if(giro==3){
     cout<<"Você não respondeu as atividades e perdeu 20 de vida."<< endl;
    jogador.vida -= 20;
    
    }
//coisas boas
else if(giro==4){
    cout<<"Você conseguiu entregar todas as listas a tempo, avance 2 casas."<<endl;
    jogador.posicao += 2;
    
}
else if(giro==5){
        cout<<"Você conseguiu uma nota boa na prova, ganhou 5 de vida."<<endl;
        jogador.vida += 5;
        
    }
else if(giro==6){
            cout<<"Você ainda tem limites de falta, avance 3 casas."<<endl;
            jogador.posicao+=3;
            
    }
else if(giro==7){
        cout<<"Você tirou a nota máxima do projeto, ganhou 10 de vida."<< endl;
        jogador.vida += 10;
        
    }
//evita posições negativas se a roleta mandar recuar
if (jogador.posicao < 0) 
    jogador.posicao = 0;
}
void eventosEspeciais(sjogador &jogador, sjogador &adversario, bool ehJ1,bool &rodadaP, bool &rodadaS, bool &doisDadosP, bool &doisDadosS, bool &roletaP, bool &roletaS, bool &somaDadosP, bool &somaDadosS)
{
    if(  jogador.posicao == 1||jogador.posicao==4)
    {
        cout<<"-------------Josevas Space-------------"<<endl;
        int op= rand()% 4;
        if (op==0)
        {
            cout<<"Você foi flagrado usando o raciocínio transdutivo para responder uma questão de Josevas. Por isso não irá jogar a próxima rodada."<< endl;
            if(ehJ1)
            {
                rodadaP=false;
            }
            else
            {
                rodadaS=false;
            }
            return;
        }

        else if(op == 1)
        {
            cout<<"Sua inteligência natural agradou Josevas. Na próxima rodada, gire o dado duas vezes e considere o maior valor."<< endl;
            if(ehJ1)
            {
                doisDadosP=true;
            }
            else
            {
                doisDadosS=true;
            }
            return;
        }

        else if(op==2)
        {
            cout<<"Foi detectado um alto nível de burrice natural. Caso tire 6 no dado na próxima rodada, não poderá girar a Roleta X"<< endl;
            if(ehJ1)
            {
                roletaP=false;
            }
            else
            {
                roletaS=false;
            }
            return;
        }
        else if(op==3)
        {
            cout<<"Você é um aluno que nunca se atrasou para a aula, diferente do seu adversário. Então, na rodada seguinte ele não poderá jogar"<< endl;
            if(ehJ1)
            {
                rodadaS=false;
            }
            else
            {
                rodadaP=false;
            }
            return;
        }

    }//fecha Josevas space

    if(jogador.posicao == 9 || jogador.posicao == 14)
    {
        cout<<"-------------Lili Space-------------"<<endl;
        int op= rand()% 3;
        if (op==0)
        {
            cout<<"Você solucionou corretamente um desafio. Ganhou 5 de vida."<< endl;
            jogador.vida+=5;
            if(jogador.vida>100)
            {
                jogador.vida=100;
            }
            return;
        }

        else if(op==1)
        {
            cout<<"Você esqueceu de declarar uma variável e seu programa não compilou. Na próxima rodada, você não poderá jogar."<< endl;
            if(ehJ1)
            {
                rodadaP=false;
            }
            else
            {
                rodadaS=false;
            }
            return;
        }

        else if(op==2)
        {
            cout<<"Você ganhou o Kahoot! Como consequência, seu adversário não poderá jogar na próxima rodada"<< endl;
            if(ehJ1)
            {
                rodadaS=false;
            }
            else
            {
                rodadaP=false;
            }
            return;
        }
    }//fecha Lili space

    if(jogador.posicao == 20 || jogador.posicao == 23)
    {
        cout<<"-------------Rapha Space-------------"<<endl;
        int op= rand()% 4;
        if (op==0)
        {
            cout<<"Você montou certo uma tabela verdade, garantindo que na próxima rodada jogue duas vezes o dado e escolha o maior valor."<< endl;
            if(ehJ1)
            {
                doisDadosP=true;
            }
            else
            {
                doisDadosS=true;
            }
            return;
        }

        else if(op==1)
        {
            cout<<"Você errou a resolução de um exercício, mas o professor não te penalizou"<< endl;
            //casa vazia
            return;
        }

        else if(op==2)
        {
            cout<<"Seu projeto seguiu todas as instruções, diferente do seu adversário, por isso ele não jogará a próxima rodada."<< endl;
            if(ehJ1)
            {
                rodadaS=false;
            }
            else
            {
                rodadaP=false;
            }
            return;
        }
        else if(op==3)
        {
            cout<<"Você se atrasou para a aula, mas o professor colocou presença em todos da turma. \nUsando sua boa sorte, na próxima rodada role o dado duas vezes e considere a soma dos resultados."<< endl;
            if(ehJ1)
            {
                somaDadosP=true;
            }
            else
            {
                somaDadosS=true;
            }
        }
        return;
    }//fecha Rapha space

    if(jogador.posicao == 24 || jogador.posicao == 26)
    {
        cout<<"-------------Dósea Space-------------"<<endl;
        int op= rand()% 3;
        if (op==0)
        {
            cout<<"Você foi chamada à sala do coordenador do curso e não comparecerá à próxima rodada."<< endl;
            if(ehJ1)
            {
                rodadaP=false;
            }
            else
            {
                rodadaS=false;
            }
            return;
        }

        else if(op==1)
        {
            cout<<"Você faltou a todos os eventos do curso, o coordenador não gostou e por isso esta casa está igual à sua presença."<< endl;
            //casa vazia
            return;
        }

        else if(op==2)
        {
            cout<<"Você criou um programa de agendamento para Dósea. E por isso vai direto para a linha de chegada."<< endl;
            jogador.posicao=27;
            return;
        }
    }//fecha Dósea space

}//fecha casas especiais

// Imprime o tabuleiro simplificado com cores no console
void desenharTabuleiroConsole(sjogador& j1, sjogador& j2, char tab [][60]) {
    system("cls");
    cout << "=========================================================\n";
    cout << "                  TABULEIRO XAVIER                       \n";
    cout << "=========================================================\n\n";

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 60; j++) {
            bool ehP = (i == caminho[j1.posicao].lin && j == caminho[j1.posicao].col);
            bool ehS = (i == caminho[j2.posicao].lin && j == caminho[j2.posicao].col);

            if (ehP && ehS) {
                mudarCor(13); // Roxo se ambos estiverem na mesma casa
                cout << "X";
            } else if (ehP) {
                mudarCor(12); // Vermelho para Jogador 1 (P)
                cout << "J1";
            } else if (ehS) {
                mudarCor(9);  // Azul para Jogador 2 (S)
                cout << "J2";
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
    mudarCor(12); cout << "J1"; mudarCor(7); cout << " = " << j1.nome << " Hp:"<< j1.vida << " | ";
    mudarCor(9);  cout << "J2"; mudarCor(7); cout << " = " << j2.nome << " Hp:"<< j2.vida << " | ";
    mudarCor(14); cout << "?"; mudarCor(7); cout << " = Especial | ";
    mudarCor(13); cout << "X"; mudarCor(7); cout << " = Ambos na mesma casa\n";
    cout << "=========================================================\n\n";
}



// Lógica Principal do Jogo
void iniciarJogo(sjogador j1, sjogador j2, char tab [][60])
{
       
    //deternima se o jogador vai participar da rodada
bool rodadaP= true;
bool rodadaS= true;
//determina se o jodagor pode girar o dado duas vezes
bool doisDadosP=false;
bool doisDadosS=false;
//deternima se o jodador pode girar a roleta X
bool roletaP=true;
bool roletaS=true;
//determina se o jodagor pode girar o dado duas vezes e somas esses valores
bool somaDadosP=false;
bool somaDadosS=false;


    j1.posicao = 0;
    j1.vida = 50; // Defina a vida inicial como 50, podendo chegar até a 100

    j2.posicao = 0;
    j2.vida = 50;

    bool fimDeJogo = false;
    string vencedor = "";

    inicializarTabuleiro(tab);

    // Sorteia quem começa
    int turno = (rand() % 2) + 1;

    cout << "\nDigite o nome do Jogador 1 (P): ";
    cin >> j1.nome;
    cout << "Digite o nome do Jogador 2 (S): ";
    cin >> j2.nome;
    cin.ignore();

    cout <<"Aperte qualquer tecla para dar inicio a partida:" << endl;
    cin.get();

    while (!fimDeJogo)
    {

        desenharTabuleiroConsole(j1, j2, tab);
        string nomeAtual;
        // Identifica qual é o objeto do jogador atual
        if(turno == 1)
        nomeAtual = j1.nome;
        
        else
        nomeAtual = j2.nome;

        cout << "Vez de " << nomeAtual << " (Pressione ENTER para jogar o dado)..." << endl;
        cin.get();


        if (turno == 1)
        {
            //Verifica se o jogador participa da rodada
            if(!rodadaP)
            {
                cout <<j1.nome<< " perdeu essa rodada!"<< endl;
                rodadaP=true;
                turno=2;
                cin.get();
                continue;
                //continue para não executar mais nada\, voltar para o começo do while
            }
            int dado;
            //verifica se usa dois dados
            if(doisDadosP || somaDadosP)
            {
                int dado1= (rand() % 6) + 1;
                int dado2= (rand() % 6) + 1;
                cout<<"Valor do primeiro giro no dado: "<<dado1<<endl;
                cout<<"Valor do segundo giro no dado: "<<dado2<<endl;
                //verifica se vai somar esses valores
                if(somaDadosP)
                {
                    dado= dado1 + dado2;
                    somaDadosP= false;
                }
                else if(dado1>dado2)
                {
                    dado=dado1;
                }
                else
                {
                    dado=dado2;
                }
                doisDadosP=false;
            }
            //rola apenas um dado
            else
            {
                dado = (rand() % 6) + 1;
            }
            cout << nomeAtual << " tirou o numero: " << dado << endl;
            // Atualiza a posição do Jogador 1
            j1.posicao += dado;
            //Verifica se o jagador 1 tirou 6 para chamar a roleta
            if(dado==6)
            {
                //Verifica se pode girar a roleta
                if(roletaP)
                {
                    cout<<"\nVocê tirou 6! Girando Roleta X...\n";
                    eventosEspeciais(j1);
                }
                else
                {
                    cout<<"\nVocê tirou 6. Mas não pode girar a Roleta X nesta rodada."<<endl;
                    roletaP=true;
                }
            }

            // Chama a função das casas especiais
            if (j1.posicao == 1 || j1.posicao == 4 || j1.posicao == 9 || j1.posicao == 14 || j1.posicao == 20 || j1.posicao == 23 || j1.posicao == 24 || j1.posicao == 26)
            {
                cout << "\n CASA ESPECIAL!\n";
                eventosEspeciais(j1,j2, true, rodadaP, rodadaS, doisDadosP, doisDadosS, roletaP, roletaS, somaDadosP, somaDadosS);
            }

            // Evita posições negativas caso a roleta mande recuar
            if (j1.posicao < 0) j1.posicao = 0;

            // Verifica vitória
            if (j1.posicao >= 27 || j2.vida <= 0)
            {
                j1.posicao = 27;
                vencedor = j1.nome;
                cout << "Fim de Jogo! vencedor:"  << vencedor <<endl;
                historicoDePartidas(j1, j2,vencedor);
                fimDeJogo = true;
                cin.get();

            }
            turno = 2;

        }
//------------------------turno2--------------------------------------------
        else
        {
            //Verifica se o jogador 2 participa da rodada
            if(!rodadaS)
            {
                cout <<j2.nome<< " perdeu essa rodada!"<< endl;
                rodadaS=true;
                turno=1;
                cin.get();
                continue;
            }
            int dado;
            //verifica se usa dois dados
            if(doisDadosS||somaDadosS)
            {
                int dado1= (rand() % 6) + 1;
                int dado2= (rand() % 6) + 1;
                cout<<"Valor do primeiro giro no dado: "<<dado1<<endl;
                cout<<"Valor do segundo giro no dado: "<<dado2<<endl;
                //verifica se soma esse valores
                if(somaDadosS)
                {
                    dado= dado1 + dado2;
                    somaDadosS= false;
                }
                else if(dado1>dado2)
                {
                    dado=dado1;
                }
                else
                {
                    dado=dado2;
                }
                doisDadosS=false;
            }
            //rola apenas um dado
            else
            {
                dado = (rand() % 6) + 1;
            }
            cout << nomeAtual << " tirou o numero: " << dado << endl;
            // Atualiza a posição do Jogador 2
            j2.posicao += dado;
            //Verifica se o jagador 2 tirou 6 para chamar a roleta
            if(dado==6)
            {
                //Verifica se pode girar a roleta
                if(roletaS)
                {
                    cout<<"\nVocê tirou 6! Girando Roleta X...\n";
                    eventosEspeciais(j2);
                }
                else
                {
                    cout<<"\nVocê tirou 6. Mas não pode girar a Roleta X nesta rodada."<<endl;
                    roletaS=true;
                }
            }

            // Chama Chama a função das casas especiais
            if (j2.posicao == 1 || j2.posicao == 4 || j2.posicao == 9 || j2.posicao == 14 || j2.posicao == 20 || j2.posicao == 23 || j2.posicao == 24 ||j2.posicao == 26)
            {
                cout << "\nCASA ESPECIAL!\n";
                eventosEspeciais(j2,j1, false, rodadaP, rodadaS, doisDadosP, doisDadosS, roletaP, roletaS, somaDadosP, somaDadosS);
            }

            // Evita posições negativas
            if (j2.posicao < 0) j2.posicao = 0;

            // Verifica vitória
            if (j2.posicao >= 27 || j1.vida <= 0)
            {
                j2.posicao = 27;
                vencedor = j2.nome;
                cout << "Fim de Jogo! vencedor:"  << vencedor <<endl;
                historicoDePartidas(j1, j2,vencedor);
                fimDeJogo = true;
                cin.get();
                return;
            }
            turno = 1;
        }
        if(fimDeJogo == false){
        cout << "Aperte qualquer tecla para passar o seu turno:" << endl;
        cin.get();
        Sleep(1000);
        }
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

#endif