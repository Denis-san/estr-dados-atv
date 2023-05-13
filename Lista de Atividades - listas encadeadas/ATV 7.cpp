/* 7) Escreva uma função em C++ para inserir um valor inteiro no fim da lista. Esta função deverá
ser chamada na main de dentro de um loop, para que seja construída uma lista com m nós.
Não se esqueça de ler a quantidade m de nós e de inicializar a lista. Note que, m dever ser
maior ou igual a zero.
• Protótipo da função: no* insereFim(no * inicio, int valor);
• Parâmetros: Ponteiro para o início da lista e o valor inteiro a ser inserido (ou adicionado).
• Retorno: Ponteiro para o início da lista */

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
