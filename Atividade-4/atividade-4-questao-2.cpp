#include <iostream>

using namespace std;

#define MAX 10

int enfileirar(int fila[], int &final_fila, int valor, int &qntd);
int desenfileirar(int fila[], int &inicio_fila, int &valor, int &qntd);

int qntd_valores_impares_da_fila(int fila[], int &inicio_fila, int &valor, int &qntd);
int qntd_valores_pares_da_fila(int fila[], int &inicio_fila, int &valor, int &qntd);

int main(){
    
    int fila[MAX];
    int inicio_fila = 0;
    int final_fila = -1;
    int qntd = 0;
    
    int valor;
    
     do{
        cout << "Digite o número: ";
        cin >> valor;
        
        if(valor > 0){    
            enfileirar(fila, final_fila, valor, qntd);
        }
    }while(valor > 0);
    
   // cout << "Qantidade de números ímpares: "; 
   // cout << qntd_valores_impares_da_fila(fila, inicio_fila, valor, qntd );

    cout << "Qantidade de números pares: "; 
    cout << qntd_valores_pares_da_fila(fila, inicio_fila, valor, qntd );
    
    return 0;
}

int enfileirar(int fila[], int &final_fila, int valor, int &qntd){
    if(qntd >= MAX){
        cout << "Erro fila cheia";
        return -1;
    }
    
    final_fila = final_fila + 1;
    
    if(final_fila == MAX){
        final_fila = final_fila - MAX;
    }
    
    fila[final_fila] = valor;
    
    qntd = qntd + 1;
    
    return 0;
}

int desenfileirar(int fila[], int &inicio_fila, int &valor, int &qntd){
    if(qntd <= 0){
        return -1;
    }
    
    valor = fila[inicio_fila++];
    
    if(inicio_fila >= MAX){
        inicio_fila = inicio_fila - MAX;
    }
    
    qntd = qntd - 1;
    
    return 0;
}

int qntd_valores_impares_da_fila(int fila[], int &inicio_fila, int &valor, int &qntd ){
    
    int result = 0;
    
    while(desenfileirar(fila, inicio_fila, valor, qntd) == 0) {
       if((valor % 2) != 0){
           result++;
       }
    }
    
    return result;
}

int qntd_valores_pares_da_fila(int fila[], int &inicio_fila, int &valor, int &qntd){
    
    int result = 0;
    
    while(desenfileirar(fila, inicio_fila, valor, qntd) == 0) {
       if((valor % 2) == 0){
           result++;
       }
    }
    
    return result;
}
