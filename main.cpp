#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

void limpaTela(){
    system("CLS");
}

void mostraStatus(string maskedPalavra, int tentativas, int tamanhoPalavra,string letrasChutadas){
    cout << "Palavra: " << maskedPalavra << endl;
    cout << "Tamanho da palavra: " << tamanhoPalavra << endl;
    cout <<  "Letras ja Usadas: ";
    for(int i = 0;i < letrasChutadas.size();i++){
        cout << letrasChutadas[i] << ", ";
    }
    cout << "\nTentativas restantes: " << tentativas << endl;
}

//Palavras estão aqui!
//-------------------
string retornaPalavraRandom(){

    srand ( time(NULL) );


    //Palavras para o jogar sozinho
    //-----------------------------
    string palavras[10] = {"carro", "teclado", "celular", "bicicleta","jardim","gato","cachorro","borracharia","academia","hospital"};

    //Indice gerado no intervalo (0, 1, 2, 3, 4, 5)
    //-----------------------------------
    int randomIndex =  0+ (rand() % 10);
    return palavras[randomIndex];
}

string returnMaskedPalavra(string palavra, int tamanhoPalavra){
   string maskedPalavra;
   for(int i = 0; i < tamanhoPalavra; i++){
    maskedPalavra += '_';
   }
    return maskedPalavra;
}


int jogar(int multiplayer){
    //Palavra a ser adivinhada
    //------------------------
    string palavra;

    //decisao se vai ser modo multiplayer ou single.
    //----------------------------------------------
    if(multiplayer == 1){
        cout << "Digite uma palavra: " << endl;
        cin >> palavra;
    }
    else palavra = retornaPalavraRandom();

    //pega o numero de letras na palavra a ser advinhada
    //-------------------------------------------
    int tamanhoPalavra = palavra.size();
    string maskedPalavra = returnMaskedPalavra(palavra, tamanhoPalavra);

    //Variaveis Principais
    //-------------------
    int tentativas = 5;
    int jogarDnv;
    char aux;        //Usuario come�a com 5 tentativas
    char letra;                //Pega valor que o usuario digitar
    bool acertouLetra;
    bool letraJaChutada;         //Verifica se a letra existe na palavra
    string letrasChutadas;       //Letras que o usuario ja tentou
    string chutarPalavra;

    while(palavra != maskedPalavra && tentativas > 0){

        limpaTela();
        mostraStatus(maskedPalavra, tentativas, tamanhoPalavra, letrasChutadas);
        acertouLetra = false;

        cout << "Chute uma letra ou digite 1 para tentar chutar a palavra inteira:  " << endl;
        cin >> letra;


        //Se o usuario quiser chutar a palavra.
        //-------------------------------------
        if(letra == '1'){
            cout << "que palavra vc acha que eh? ";
            cin >> chutarPalavra;                            //Pega a string que o player digitou

            if(chutarPalavra == palavra){                    //Se o usuario acertar a palavra
                maskedPalavra = chutarPalavra;               //Revela a palavra terminando o jogo
                cout << "Parabens vc venceu!\n" << endl;       //Da mensagem de vitoria
            }else   tentativas = 0;                          //se não, zera as tentativas do jogador
        }


        //Verifica se o usuario ja tentou a mesma letra.
        //----------------------------------------------
        for(int i = 0; i < letrasChutadas.size(); i++){
            if(tolower(letra) == letrasChutadas[i]){        //Se o a letra que o player dugutou ja foi tentada antes,
                letraJaChutada = true;                      //defini letraJaChutada como true
            }
        }
        //Caso o usario tente uma letra pela 1ª vez, concatena essa letra na string "letrasChutadas".
        //-------------------------------------------------------------------------------------------
        if(letraJaChutada == false){
        letrasChutadas += tolower(letra);
        }


        //Verifica se a letra que o usuario digitou existe na string.
        //-----------------------------------------------------------
        for(int i = 0; i <= tamanhoPalavra; i++){
            if(palavra[i] == tolower(letra) ){
                maskedPalavra[i] = palavra[i];
                acertouLetra = true;
            }
        }
        //Se o usuario nao acertou a letra subtrai as tentativa.
        //------------------------------------------------------
        if(acertouLetra == false && letraJaChutada == false){  
            tentativas--;
        }
        letraJaChutada = false;
        //FIM DO WHILE
    }


    //Se a string masked for igual a palavra escolhida o jogo acaba e mostra a mensagem de vitoria/derrota.
    //----------------------------------------------------------------------------------------------------
    if(maskedPalavra == palavra)
        {
            limpaTela();
            cout << "Parabens vc venceu!" << endl;
        }else cout << "\nGAME OVER, vc perdeu  :'( \na palavra certa era: " << palavra << "\n" << endl;  //


    cout << "Deseja jogar novamente?" << endl;
    cout << "1 - Sim" << endl;
    cout << "2 - Nao (volta para o menu)" << endl;
    cin >> jogarDnv;
    return jogarDnv;
}


void mostraMenu(){
    int option = 0;

    //Menu do inicial do jogo.
    //-----------------------
    while(option != 4 ){

        cout << "Bem vindo ao Jogo" << endl;
        cout << "1 - Jogar sozinho" << endl;
        cout << "2 - jogar em dupla" << endl;
        cout << "3 - Sobre o jogo" << endl;
        cout << "4 - Sair" << endl;
        
        int teste1;
        cin >> option;
        limpaTela();

        switch (option)
        {
        case 1:
    
            teste1 = 1;
            while(teste1 == 1){
                teste1 = jogar(0);
            }
            break;
        case 2:
            
            teste1 = 1;
            while(teste1 == 1){
                teste1 = jogar(1); 
            }
            break;
        case 3:
            limpaTela();
             cout << "Informacoes do jogo " << endl;
             cout << "Jogo desenvolvido por Gabriel Goulart em 2022" << endl;
             cout << "Meu linkedin -> https://www.linkedin.com/in/gabriel-goulart-551349189/ " << endl;
             cout << "\n1 - Voltar para o Menu" << endl;
             cout << "2 - Sair" << endl;
             cin >> option;
             if(option == 1){
                mostraMenu();
             }
            break;
        }
    }
}



int main(){

 mostraMenu();



    return 0;
}
