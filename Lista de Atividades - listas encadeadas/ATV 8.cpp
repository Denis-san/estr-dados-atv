/*8) Escreva uma função em C++ para remover o último nó de uma lista.
• Protótipo da função: no* removeFim(no * inicio);
• Parâmetros: Ponteiro para o início da lista e o valor inteiro a ser inserido (ou adicionado).
• Retorno: Ponteiro para a lista */

#include <iostream>
using namespace std; 

struct no{
	int valor;
	no* prox;
};

no* insereFim(no * inicio, int valor);
no* removeFim(no * inicio);
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
	lista = removeFim(lista);
	imprimir(lista);
}
no* removeFim(no * inicio){
	no * tmp = inicio->prox;
	no * tmp_2 = inicio;
	
	if (inicio == NULL) return inicio;
	
	if (inicio->prox == NULL){
		delete(inicio);
		cout << "Removido" << endl;
		return NULL;
	}
	else{
		while (tmp->prox != NULL){
			tmp_2 = tmp;
    		tmp = tmp->prox;
		}
		tmp_2->prox = NULL;
		delete(tmp);
		cout <<"Removido"<<endl;
		return inicio; 
	}	
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
