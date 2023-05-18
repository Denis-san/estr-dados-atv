#include <iostream>

using namespace std;

struct Aluno {
    int matricula;
    float media;
};

struct no{
    Aluno aluno;
    no *prox;
};

void enfileirar(no** fila, Aluno aluno);
void imprimir(no *inicio);
Aluno desenfileirar(no** fila);

int main(){
    
    no *fila = NULL;
    Aluno aluno;
    
    int n;

    do{
        cout << "Quantos alunos deseja enfileirar? ";
        cin >> n;
        
        if(n < 0){
            cout << "Insira uma quantidade maior que 0!" << endl;
        }
    } while(n < 0);
    
    
    while (n > 0) {
        cout << "\nDigite a matricula do aluno: ";
        cin >> aluno.matricula;
        
        cout << "Digite a nota do aluno: ";
        cin >> aluno.media;
        
        enfileirar(&fila, aluno);
        
        n--;
    }
    
    cout << "\nExibindo todos os alunos: " << endl;
    imprimir(fila);
    
    cout << "\nDesenfileirando e exibindo somente quem possui media acima/igual a 5:" << endl;
   
    // Letra b)
    Aluno alunoDesenfileirado;
    int i = 0;
    while (fila != NULL) {
        alunoDesenfileirado = desenfileirar(&fila);
        
        if(alunoDesenfileirado.media >= 5){
            cout << "--------------------" << endl;
            cout << "Aluno [" << ++i << "]: " << endl;
            cout << "matricula: " << alunoDesenfileirado.matricula << endl;
            cout << "media: " << alunoDesenfileirado.media << endl;
        }
        
        fila = fila->prox;
    }
    
    return 0;
}

void enfileirar(no** fila, Aluno aluno){
    no *temp = new no;
    
    temp->aluno = aluno;
    temp->prox = NULL;
    
    if(*fila == NULL){
        *fila = temp;
        return;
    }
    
    no *elementoFinal = *fila;
    
    if (fila != NULL) {
        while(elementoFinal->prox != NULL){
            elementoFinal = elementoFinal->prox;
        }
        
        elementoFinal->prox = temp;
    }
}

void imprimir(no *inicio){
    int i = 0;
    while (inicio != NULL) {
        cout << "--------------------" << endl;
        cout << "Aluno [" << ++i << "]: " << endl;
        cout << "matricula: " << inicio->aluno.matricula << endl;
        cout << "media: " << inicio->aluno.media << endl;
        inicio = inicio->prox;
    }
}

Aluno desenfileirar(no** fila){
    
    no *temp = *fila;
    *fila = temp->prox;
   
    Aluno aluno = temp->aluno;
    
    delete temp;
    
    return aluno;
}