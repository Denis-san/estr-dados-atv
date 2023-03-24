#include <iostream>

using namespace std;

#define MAX 10

int enfileirar(int fila[], int &final_fila, int valor, int &qntd);
int desenfileirar(int fila[], int &inicio_fila, int &valor, int &qntd);
void inverterFila(int fila[], int qntd);

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
    
   // cout << "Desenfileirando:" << endl;
//    while(desenfileirar(fila, inicio_fila, valor, qntd) == 0) {
  //     cout << valor << endl;
//    }
    
    cout << "\nInvertendo a fila:" << endl;
    inverterFila(fila, qntd);
    while(desenfileirar(fila, inicio_fila, valor, qntd) == 0) {
       cout << valor << endl;
    }
    
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
        cout << "Fim da fila";
        return -1;
    }
    
    valor = fila[inicio_fila++];
    
    if(inicio_fila >= MAX){
        inicio_fila = inicio_fila - MAX;
    }
    
    qntd = qntd - 1;
    
    return 0;
}

void inverterFila(int fila[], int qntd){
    int copia_fila[qntd];
    
    int i;
    int temp = qntd - 1;
    
    for(i = 0; i < qntd; i++){
        copia_fila[i] = fila[temp--];
    }
   
    int final_fila = -1;
    
    for(i = 0; i < qntd; i++){
        fila[++final_fila] = copia_fila[i];
    }
    
}
