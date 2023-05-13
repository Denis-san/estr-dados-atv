/* 7) Escreva uma fun��o em C++ para inserir um valor inteiro no fim da lista. Esta fun��o dever�
ser chamada na main de dentro de um loop, para que seja constru�da uma lista com m n�s.
N�o se esque�a de ler a quantidade m de n�s e de inicializar a lista. Note que, m dever ser
maior ou igual a zero.
� Prot�tipo da fun��o: no* insereFim(no * inicio, int valor);
� Par�metros: Ponteiro para o in�cio da lista e o valor inteiro a ser inserido (ou adicionado).
� Retorno: Ponteiro para o in�cio da lista */

#include <iostream>
using namespace std; 
struct no{
	int valor;
	no* prox;
};
no* insereFim(no * inicio, int valor);
void imprimir(no * lista);
int main (void){
	no * lista = NULL;
    int m, valor;
    cout << "Quantos valores pretende digitar? ";
    cin >> m;

    for(int i=0; i<m; i++) {
        cout << "Digite o valor " << i+1 << ": ";
        cin >> valor;
        lista = insereFim(lista, valor);
    }
     imprimir(lista);
	
}
no* insereFim(no * inicio, int valor){
 	no* ptr;
 	ptr = new no;
 	no* tmp;
 	tmp = new no;
 	
    if (inicio == NULL){
    	tmp->valor = valor;
 		tmp->prox= NULL;
 		inicio = tmp;
 		return inicio;
	}	
    else {
    	ptr->valor = valor;
    	ptr->prox = NULL;
    	tmp = inicio;
    	while (tmp->prox != NULL){
    		tmp = tmp->prox;
		}
     	tmp->prox = ptr;
     	return inicio;
    }
    return inicio;
}

void imprimir(no * lista) {
    no * tmp;
    tmp = lista;
    while(tmp != NULL) {
        cout << tmp->valor << endl;
        tmp = tmp->prox;
    }
}
