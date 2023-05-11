// Questões 1, 2, 3, 4, 5 e 6;

#include <iostream>

using namespace std;

struct no{
    int valor;
    no *prevNo;
};

no * insereFrente(no * lista, int valor);
void imprimir(no *inicio);
void substituir(no * inicio, int valor, int novoValor);
no * removerInicio(no * inicio);
no * busca(no * inicio, int valor);
int contaNos(no * inicio);

int main() {
  
    no * lista = NULL;

    int valor;

    do{
        cout << "Digite o valor: ";
        cin >> valor;
        
        if(valor > 0){
            lista = insereFrente(lista, valor);
        }
    } while(valor > 0);

    imprimir(lista);
    
    cout << "\nApos remover o 1o no: " << endl;
    if(lista == NULL){
        cout << "lista vazia!";
    }else{
        lista = removerInicio(lista);
    }
    
    imprimir(lista);
    
    cout << "\nDigite o valor a ser buscado: ";
    cin >> valor;
    
    no *temp;
    temp = busca(lista, valor);
    
    if(temp == NULL){
        cout << "Valor nao encontrado!";
    }else{
        cout << "Endereco de memoria: " << temp; 
    }
    
    int count = contaNos(lista);
    cout << "\nQuantidade de nos: " << count;
    
    cout << "\nQual valor deseja substituir: ";
    cin >> valor;
    
    if(valor > 0 && valor < count){
        int novoValor;
        
        cout << "Por qual valor (novo valor): ";
        cin >> novoValor;
        
        substituir(lista, valor, novoValor);
        
        cout << "lista depois da substituicao: " << endl;
        imprimir(lista);
    }else{
        cout << "troca nao realizada, o valor eh menor que 0 ou maior que a quantidade de itens na lista";
    }
    
    return 0;
    
}

// Questão 1
no * insereFrente(no * lista, int valor){
    
    no *tempNo;
    
    tempNo = new no;
    tempNo->valor = valor;
    tempNo->prevNo = NULL;
    
    if(lista == NULL){
        lista = tempNo;
        return lista;
    }
    
    tempNo->prevNo = lista;
    lista = tempNo;
    
    return lista;
    
}

// Questão 2
void imprimir(no *inicio){
    no *tempNo;
    tempNo = inicio;
    
    while(tempNo != NULL){
        cout << tempNo->valor << ", ";
        tempNo = tempNo->prevNo;
    }
}

// Questão 3
void substituir(no * inicio, int valor, int novoValor){
    no *tempNo;
    
    tempNo = busca(inicio, valor);
    
    if(tempNo != NULL){
        tempNo->valor = novoValor;
    }
}

// Questão 4
no * removerInicio(no * inicio){
    if(inicio == NULL){
        return inicio;
    }
    
    no *tempNo;
    
    tempNo = inicio;
    inicio = tempNo->prevNo;
    
    delete tempNo;
    return inicio;
}

// Questão 5
no * busca(no * inicio, int valor){
    
    if(inicio == NULL){
        return NULL;
    }
    
    no *tempNo;
    tempNo = inicio;
    
    while(tempNo != NULL){
        
        if(tempNo->valor == valor){
            return tempNo;
        }
        
        tempNo = tempNo->prevNo;
    }

    delete tempNo;
    return NULL;
}

// Questão 6
int contaNos(no * inicio){
    no *tempNo;
    tempNo = inicio;
    
    int result = 0;
    
    while(tempNo != NULL){
        result = result + 1;
        tempNo = tempNo->prevNo;
    }
    
    return result;
}











