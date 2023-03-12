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

    string texto;
    
    cout << "Digite os parenteses: ";
    getline(cin, texto);
    
    int i;
    for(i = 0; i < texto.length(); i++){
        if(texto[i] == '('){
            empilhar(pilha, topo, texto[i]);
        }    
    }
    
    for(i = 0; i < texto.length(); i++){
        if(texto[i] == ')'){
            desempilhar(pilha, topo, pilha[topo]);
        }
    }
    
    cout << topo << endl;
    
    if(topo == -1){
        cout << "O número de abre parênteses é igual ao número de fecha parênteses.";
        return 0;
    }
    
    cout << "O número de abre parênteses é diferente do número de fecha parênteses.";
        
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


