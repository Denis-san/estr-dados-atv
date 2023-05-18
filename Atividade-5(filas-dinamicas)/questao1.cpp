#include <iostream>

using namespace std;

struct no{
    int valor;
    no *prox;
};

void enfileirar(no** fila, int valor);
void imprimir(no *inicio);
int desenfileirar(no** fila);
int contarDadosInseridosNaFila(no *fila);
void desenfileirarTudoExibirSomentePar(no** fila);

int main(){
    no *fila = NULL;
    
    int valor;

    do{
        cout << "Digite o valor: ";
        cin >> valor;
        
        if(valor > 0){
            enfileirar(&fila, valor);
        }
    } while(valor > 0);
    
    imprimir(fila);
    
    int valorDesenfileirado = desenfileirar(&fila);
    cout << "\nElemento desenfileirado!: " << valorDesenfileirado << endl;
    
    imprimir(fila);
    
    int qntdDadosLista = contarDadosInseridosNaFila(fila);
    cout << "\nQuantidade de elementos na lista: " << qntdDadosLista << endl;

    cout << "Desenfileirando e exebindo somente pares:" << endl;
    // Letra d)
    while (fila != NULL) {
        valorDesenfileirado = desenfileirar(&fila);
        
        if(valorDesenfileirado % 2 == 0){
            cout << valorDesenfileirado << ", ";
        }
        
        fila = fila->prox;
    }
    return 0;
}

void enfileirar(no** fila, int valor){
    no *temp = new no;
    
    temp->valor = valor;
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

// Letra a)
void imprimir(no *inicio){
    while (inicio != NULL) {
        cout << inicio->valor << ", ";
        inicio = inicio->prox;
    }
}

// Letra b)
int desenfileirar(no** fila){
    
    no *temp = *fila;
    *fila = temp->prox;
   
    int valor = temp->valor;
    
    delete temp;
    
    return valor;
}

// Letra c)
int contarDadosInseridosNaFila(no *fila){
    int result = 0;   
    while (fila != NULL) {
        result = result + 1;
        fila = fila->prox;
    }
    
    return result;
}
