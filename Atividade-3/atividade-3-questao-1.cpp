#include <iostream>
using namespace std;

#define MAX 50

int enfileirar(int fila[], int &fim_fila, int valor);
int desenfileirar(int fila[], int &inicio_fila, int fim_fila, int &valor);

int main(){
    
    int fila[MAX];
    int inicio_fila = 0;
    int fim_fila = -1;
    
    int opcao;
    int valor;
    
    do{
        
        cout << "\n+-------------------------------------------------------------+\n";
        cout << "| 1 - Enfileirar um número                                    |\n";
        cout << "| 2 - Desenfileirar tudo e imprimir valores múltiplos de 2    |\n";
        cout << "| 3 - Encerrar o programa                                     |\n";
        cout << "+-------------------------------------------------------------+\n";
        
        cout << "Digite a opção: ";
        cin >> opcao;
        
        if(opcao == 1){
            cout << "Digite o número: ";
            cin >> valor;
            enfileirar(fila, fim_fila, valor);
            continue;
        }
        
        if(opcao == 2){
            while(desenfileirar(fila, inicio_fila, fim_fila, valor) == 0) {
                if((valor % 2) == 0) {
                    cout << valor << endl;
                }
            }
            continue;
        }
    }while(opcao != 3);
    
    return 0;
}

int enfileirar(int fila[], int &fim_fila, int valor){
    if(fim_fila >= MAX-1){
        cout << "Erro! Fila cheia!";
        return -1;
    }
    
    fila[++fim_fila] = valor;
    
    return 0;
    
}
int desenfileirar(int fila[], int &inicio_fila, int fim_fila, int &valor){
    if(fim_fila < inicio_fila){
        cout << "Fim da Fila!" << endl;
        return -1;
    }
    
    valor = fila[inicio_fila++];
    
    return 0;
}



