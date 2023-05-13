/* 9) Escreva uma função em C++ para concatenar as duas listas construídas até agora, colocando
a lista com m nós no final da lista com n nós.
• Protótipo: no *concatena(no * inicio1, no * inicio2);
• Parâmetros: Ponteiro para o início da 1ª. lista (que pode ser NULL) e ponteiro para o início da
2ª. lista (que pode ser NULL).
• Retorno: Ponteiro para o início da lista resultante da concatenação */
#include <iostream>
using namespace std; 

struct no{
	int valor;
	no* prox;
};
no* insereFim(no * inicio, int valor);
no* insereFrente(no * inicio, int valor);
no *concatena(no * inicio1, no * inicio2);
void imprimir(no * lista);

int main (void){
	no * lista = NULL,* lista2 = NULL,* lista3 = NULL;
    int i ,m, valor;
   	cout << "Quantos valores pretende digitar? ";
   	cin >> m;

    for( i=0; i<m; i++) {
        cout << "Lista 1 - Digite o valor " << i+1 << ": ";
        cin >> valor;
        lista = insereFrente(lista, valor);
    }
    for( i=0; i<m; i++) {
        cout << "Lista 2 - Digite o valor " << i+1 << ": ";
        cin >> valor;
        lista2 = insereFim(lista2, valor);
    }
	imprimir(lista);
	imprimir(lista2);
	lista3 = concatena(lista,lista2);
	imprimir(lista3);
}

no* insereFrente(no * inicio, int valor) {
    no * tmp;
    tmp = new no;
    tmp->valor = valor;
    tmp->prox = NULL;
    
    if (inicio == NULL) inicio = tmp;
    else {
        tmp->prox= inicio;
        inicio = tmp;
    }
    return inicio;
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
no *concatena(no * inicio1, no * inicio2){
	no* fim = NULL;
	no* iterador= inicio2;
	while(iterador != NULL){
		fim = insereFrente(fim, iterador->valor);
		iterador = iterador->prox;
	}
	iterador = inicio1;
	while(iterador != NULL){
		fim = insereFrente(fim, iterador->valor);
		iterador = iterador->prox;
	}
	return fim;
}
void imprimir(no * lista) {
    no * tmp;
    tmp = lista;
    while(tmp != NULL) {
        cout << tmp->valor << endl;
        tmp = tmp->prox;
    }
}
