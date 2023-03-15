#include <iostream>
#include<string>

using std::string;
using std::getline;
using namespace std;

#define MAX_LENGTH_STRING 50

void empilhar(char v[], int &topo, char character);
void desempilhar(char v[], int &topo, char &character);

int main(void) {
    char pilha[MAX_LENGTH_STRING];
    int topo = -1;

    string palavra;
    
    cout << "Digite a palavra: " ;
    getline(cin, palavra);
    
    int i;
    
    int divisao_palavra = ((palavra.length()) / 2);
    
    for(i = 0; i < divisao_palavra; i++){
        empilhar(pilha, topo, palavra[i]);
    }
    
    for(i = divisao_palavra; i < palavra.length(); i++){
        
        if(palavra[i] == pilha[topo]){
            desempilhar(pilha, topo, pilha[topo]);
        }
    }
    
    if(topo == -1){
        cout << "Essa palavra é um palíndromo.";
        return 0;
    }
    
    cout << "Essa palavra NÃO é um palíndromo.";
        
}

void empilhar(char v[], int &topo, char character) {

    if (topo>=MAX_LENGTH_STRING-1) {
        cout << "ERRO: Pilha cheia!" << endl;
        return;
    }

    topo = topo + 1;
    v[topo] = character;
    
    return;
}

void desempilhar(char v[], int &topo, char &character) {
    
    character = v[topo];
    topo = topo - 1;
    
    return;
}
