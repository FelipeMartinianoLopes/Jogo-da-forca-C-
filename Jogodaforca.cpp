// compilar  mingw32-make
//executar   .\Jogodaforca

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

string palavra_secreta = "MELANCIA";
map<char, bool>chutou;
vector<char> chutes_errado;

bool letra_existe(char chute){
    for(char letra : palavra_secreta){
        if(chute == letra) {
            return true;

        }
    
    }
    return false;   

}

bool nao_acertou(){
    for(char letra : palavra_secreta){
        if(!chutou[letra]){
            return true;
        }
    }
    return false;
}
bool nao_enforcou(){
    return chutes_errado.size() < 5;
}
void imprime_cabecalho(){
    string mensagem = "jogo da forca";
    int largura = mensagem.length() + 4;

    std::cout << string(largura, '*') << endl;
    std::cout << "*" << string(largura - 2, ' ') << "*" << endl;
    std::cout << "* " << mensagem << " *" << endl;
    std::cout << "*" << string(largura - 2, ' ') << "*" << endl; 
    std::cout << string(largura, '*') << endl;

}
void imprime_erros(){
 cout <<"Chutes errados: ";
        for(char letra: chutes_errado){
            cout << letra << " ";
        }
        cout << endl;    
}
void imprime_palavra(){
for(char letra: palavra_secreta)
            if(chutou[letra]){
                cout << letra << " ";
            }
            else{
                cout <<"_ ";
            }
        cout << endl;
}
void chute(){
 cout<<"Seu chute: ";
        char chute;
        cin >> chute;
        chutou[chute] = true;

        if(letra_existe(chute)){
            cout << "Voce acertou! Seu chute esta na palavra."<< '\n';
        }
        else{
            cout << "Voce errou! Seu chute nao esta na palavra."<< '\n';
            chutes_errado.push_back(chute);
        }
        cout << endl;    
}
vector<string> le_arquivo(){
    ifstream arquivo;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()){
        int quantidade_palavras;
        arquivo >> quantidade_palavras;

        vector<string> palavras_do_arquivo;

        for(int i=0;i<quantidade_palavras;i++){
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_do_arquivo.push_back(palavra_lida);
        }
        arquivo.close();
        return palavras_do_arquivo;
    }
    else{
        cout << "Nao foi possivel acessar o banco de palavras." << endl;
        exit(0);
    }
}

void sorteia_palavra(){
    vector<string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista){
    ofstream arquivo;
    arquivo.open("palavras.txt");
    if(arquivo.is_open()){
        arquivo << nova_lista.size() << endl;
        for(string palavra : nova_lista){
            arquivo << palavra << endl;
        }
        arquivo.close();
    }
    else{
        cout << "Nao foi possivel acessar o banco de palavras." << endl;
        exit(0);
    }
}
void adicionar_palavra(){
    cout << "Digite a nova palavra, usando letras maiusculas." << endl;
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);
}

int main() {
    imprime_cabecalho();
    
    le_arquivo();
    sorteia_palavra();

    while (nao_acertou() && nao_enforcou()){
        imprime_erros();
        imprime_palavra();
        chute();
    }
    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;
    if(nao_acertou()){
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Parabens! Voce acertou a palavra secreta!" << endl;

        cout << "Voce deseja adicionar uma nova palavra ao jogo? (S/N) ";
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adicionar_palavra();
        }
    }
    
    return 0; //(Opcional, mas boa prática)
}

