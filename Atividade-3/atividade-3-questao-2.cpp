#include <iostream>
#include <cctype>

using std::string;

#define MAX_FRASE 20
using namespace std;

int enfileirar(char fila[], int &fim_fila, char caractere);
int desenfileirar(char fila[], int fim_fila, int &inicio_fila, char &caractere);

void empilhar(char pilha[], int &topo, char caractere);
int desempilhar(char pilha[], int &topo, char &caractere);

int main() {
    char frase[MAX_FRASE];
    
    char fila[MAX_FRASE];
    int fim_fila = -1;
    int inicio_fila = 0;
    
    cout<<"Digite a frase: ";
    cin.getline(frase, MAX_FRASE, '\n');
    
    int i;
    for(i = 0; frase[i] != '\0'; i++){
       enfileirar(fila, fim_fila, frase[i]);
    }
    
    cout << "Fila: ";
    
    char caractere;
    char pilha[MAX_FRASE];
    int topo = 0;
    
    while(desenfileirar(fila, fim_fila, inicio_fila, caractere) == 0){
        cout << caractere << ", ";
        empilhar(pilha, topo, tolower(caractere));
    }
    
    cout << "\nPilha: ";
    
    while(desempilhar(pilha, topo, caractere) == 0){
       cout << caractere << ", ";
    }
    
    return 0;
}

int enfileirar(char fila[], int &fim_fila, char caractere){
    if(fim_fila >= MAX_FRASE -1){
        cout << "ERRO! fila cheia";
        return -1;
    }
    
    fila[++fim_fila] = caractere;
    
    return 0;
}

int desenfileirar(char fila[], int fim_fila, int &inicio_fila, char &caractere){
    
    if(fim_fila < inicio_fila){
        return -1;
    }
    
    caractere = fila[inicio_fila++];
    
    return 0;
}

void empilhar(char pilha[], int &topo, char caractere){
    if(topo >= MAX_FRASE -1){
        return;
    }
    
    pilha[++topo] = caractere;
    
    return;
}

int desempilhar(char pilha[], int &topo, char &caractere){
    if(topo <= 0){
        return -1;
    }
    
    caractere = pilha[topo--];
    
    return 0;
}