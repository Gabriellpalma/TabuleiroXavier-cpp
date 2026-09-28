#include <iostream>
#include <time.h>

using namespace std;
struct sjogador{
string nome;
int vida;
int posicao;
};

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
//coisas boas
else if(giro==4){
    cout<<"Você conseguiu entregar todas as listas a tempo, avance 4 casas."<<endl;
    jogador.posicao+=4;
    return;}
    else if(giro==5){
        cout<<"Você conseguiu uma nota boa na prova, ganhou 3 de vida."<<endl;
        jogador.vida+=5;
        return;
    }
    else if(giro==6){
            cout<<"Você ainda tem limites de falta, avance 4 casas."<<endl;
            jogador.posicao+=4;
            return;
    }
    else if(giro==7){
        cout<<"Você tirou a nota máxima do projeto, ganhou 7 de vida."<< endl;
        return;
    }


}//chave da funcao



int main()
{
    srand(time(NULL));
    sjogador jogador1;
    jogador1.posicao=10;
    cout << "informe o nome do jogador"<< endl;
    getline(cin, jogador1.nome);
   cout<< "nome:"<< jogador1.nome<<endl;
    return 0;
}
