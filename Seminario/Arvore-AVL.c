// Código adaptado - fonte: https://wagnergaspar.com/testando-nossa-arvore-binaria-de-busca-balanceada-arvore-avl/
#include <iostream>

using namespace std;

typedef struct no{
    int valor;
    struct no *esquerdo, *direito;
    int altura;
}No;

// Retorna o maior dentre dois valores a, b -> altura de dois nós da árvore
int maior(int a, int b){
    return (a > b)? a: b;
}

// Retorna a altura de um nó ou -1 caso ele seja null
int alturaDoNo(No *no){
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

// Calcula e retorna o fator de balanceamento de um nó (Fb = altNoEsq - altNoDir)
int fatorDeBalanceamento(No *no){
    if(no != NULL)
        return (alturaDoNo(no->esquerdo) - alturaDoNo(no->direito));
    else
        return 0;
}

// Realiza a rotação à esquerda
No* rotacaoEsquerda(No *raiz){
    No *pivoRotacao, *filhoNo;

    pivoRotacao = raiz->direito;
    filhoNo = pivoRotacao->esquerdo;

    pivoRotacao->esquerdo = raiz;
    raiz->direito = filhoNo;

    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;
    pivoRotacao->altura = maior(alturaDoNo(pivoRotacao->esquerdo), alturaDoNo(pivoRotacao->direito)) + 1;

    return pivoRotacao;
}

// Realiza a rotação à direita
No* rotacaoDireita(No *raiz){
    No *pivoRotacao, *filhoNo;

    pivoRotacao = raiz->esquerdo;
    filhoNo = pivoRotacao->direito;

    pivoRotacao->direito = raiz;
    raiz->esquerdo = filhoNo;

    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;
    pivoRotacao->altura = maior(alturaDoNo(pivoRotacao->esquerdo), alturaDoNo(pivoRotacao->direito)) + 1;

    return pivoRotacao;
}

// Realiza a rotacao dupla esquerda-direita
No* rotacaoEsquerdaDireita(No *raiz){
    raiz->esquerdo = rotacaoEsquerda(raiz->esquerdo);
    return rotacaoDireita(raiz);
}

// Realiza a rotacao dupla direta-esquerda
No* rotacaoDireitaEsquerda(No *raiz){
    raiz->direito = rotacaoDireita(raiz->direito);
    return rotacaoEsquerda(raiz);
}

// Função para realizar o balanceamento da árvore após uma inserção ou remoção
// Recebe o nó que está desbalanceado e retorna a nova raiz após o balanceamento
No* balancear(No *raiz){
    int fb = fatorDeBalanceamento(raiz);

    if(fb < -1 && fatorDeBalanceamento(raiz->direito) <= 0) { // Rotação à esquerda
        raiz = rotacaoEsquerda(raiz);
        return raiz;
    }
    
    if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) >= 0) { // Rotação à direita
        raiz = rotacaoDireita(raiz);
        return raiz;
    }

    if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) < 0) { // Rotação dupla à esquerda
        raiz = rotacaoEsquerdaDireita(raiz);
        return raiz;
    }

    if(fb < -1 && fatorDeBalanceamento(raiz->direito) > 0) { // Rotação dupla à direita
        raiz = rotacaoDireitaEsquerda(raiz);
        return raiz;
    }
    
    return raiz;
}

// Insere um novo nó na árvore
// Retorno: endereço do novo nó ou nova raiz após o balanceamento
No* inserir(No *raiz, int valor){
    
    if(raiz == NULL) { // árvore vazia
        No *novo = new No;
        
        novo->valor = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
        
        return novo;
    }
    else{ // inserção será à esquerda ou à direita
        if(valor < raiz->valor)
            raiz->esquerdo = inserir(raiz->esquerdo, valor);
        else if(valor > raiz->valor)
            raiz->direito = inserir(raiz->direito, valor);
        else
            cout << "\nInsercao nao realizada!\nO elemento %d ja existe!\n" << valor;
    }

    // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    // verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);

    return raiz;
}

// Função para remover um nó da Árvore binária balanceada
// Pode ser necessário rebalancear a árvore e a raiz pode ser alterada por isso precisamos retornar a raiz
No* remover(No *raiz, int chave) {
   
    if(raiz == NULL){
        cout << "Valor nao encontrado!\n";
        return NULL;
    }
    
    if(raiz->valor == chave) {
        // remove nós folhas (nós sem filhos)
        if(raiz->esquerdo == NULL && raiz->direito == NULL) {
            delete raiz;
            cout << "Elemento folha removido: %d !\n" << chave;
            return NULL;
        }
        else{ 
            // remover nós que possuem 2 filhos
            if(raiz->esquerdo != NULL && raiz->direito != NULL){
                No *aux = raiz->esquerdo;
                
                while(aux->direito != NULL) {
                    aux = aux->direito;
                }
                
                raiz->valor = aux->valor;
                aux->valor = chave;
                
                cout << "Elemento trocado: %d !\n" << chave;
                
                raiz->esquerdo = remover(raiz->esquerdo, chave);
               
                return raiz;
            }
            else{
                // remover nós que possuem apenas 1 filho
                No *aux;
                
                if(raiz->esquerdo != NULL){
                    aux = raiz->esquerdo;
                }
                else{
                    aux = raiz->direito;
                }
                
                delete raiz;
                cout << "Elemento com 1 filho removido: %d !\n" << chave;
                
                return aux;
            }
        }
    } else {
        if(chave < raiz->valor)
            raiz->esquerdo = remover(raiz->esquerdo, chave);
        else
            raiz->direito = remover(raiz->direito, chave);
    }

    // Recalcula a altura de todos os nós entre a raiz e o novo nó inserido
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    // verifica a necessidade de rebalancear a árvore
    raiz = balancear(raiz);

    return raiz;
}

void imprimir(No *raiz, int nivel){
   int i;
    if(raiz){
        imprimir(raiz->direito, nivel + 1);
        cout << "\n\n";

        for(i = 0; i < nivel; i++)
            cout << "\t";

        cout << raiz->valor;
        imprimir(raiz->esquerdo, nivel + 1);
    }
}

int main(){

    int opcao, valor;
    No *raiz = NULL;

    do{
        cout << "\n\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n\n";
        cin >> opcao;

        switch(opcao){
        case 0:
            cout << "Encerrando...";
            break;
        case 1:
            cout << "\tDigite o valor a ser inserido: ";
            cin >> valor;
            raiz = inserir(raiz, valor);
            break;
        case 2:
            cout << "\tDigite o valor a ser removido: ";
            cin >> valor;
            raiz = remover(raiz, valor);
            break;
        case 3:
            imprimir(raiz, 1);
            break;
        default:
            cout << "\nOpcao invalida!!!\n";
        }

    }while(opcao != 0);

    return 0;
}