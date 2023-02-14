#include <iostream>

using namespace std;
const int MAX_TAMANHO_LISTA = 20;
// quantidade ~ posicao ~ ultimo elemento ~ tamanho do vetor
void inserirSemRepetir(int lista[], int valor, int &posicao, int tamanhoMax);
int buscar(int lista[], int valor, int quantidade);
void listar(int lista[], int quantidade);
int intercalar(int lista_A[], int qnt_lista_A, int lista_B[], int qnt_lista_B, int lista_Alvo[]);
int intersecao(int lista_A[], int qnt_lista_A, int lista_B[], int qnt_lista_B, int lista_Alvo[], int menorQuantidade);
int unir(int lista_A[], int qnt_lista_A, int lista_B[], int qnt_lista_B, int lista_Alvo[]);
void removerPeloIndice(int lista[], int &quantidadeLista, int indice);

int main() {
    
    int lista_A[MAX_TAMANHO_LISTA];
    int qnt_lista_A;
    
    int lista_B[MAX_TAMANHO_LISTA];
    int qnt_lista_B;
    
    int valor;
    
    cout << "Inserção de dados na lista A" << endl;
    do{
        cout << "Digite valor: ";
        cin >> valor;
       
        if (valor != 0){
          inserirSemRepetir (lista_A, valor, qnt_lista_A, MAX_TAMANHO_LISTA);  
        } 
    }while(valor != 0);
    
    cout << "Iserção de dados na lista B" << endl;
    do{
        cout << "Digite valor: ";
        cin >> valor;
       
        if (valor != 0){
          inserirSemRepetir (lista_B, valor, qnt_lista_B, MAX_TAMANHO_LISTA);  
        } 
    }while(valor != 0);
    
    cout << "\nImprimindo lista A: " << endl;
    listar(lista_A, qnt_lista_A);

    cout << "\n\nImprimindo lista B: " << endl;
    listar(lista_B, qnt_lista_B);
    
    int lista_C[MAX_TAMANHO_LISTA];
    int qnt_lista_C = intercalar(lista_A, qnt_lista_A, lista_B, qnt_lista_B, lista_C);
    
    cout << "\n\nImprimindo lista intercalada (C): " << endl;
    listar(lista_C, qnt_lista_C);
    
    
    int menorQuantidadeIntersecao = qnt_lista_A;
    
    if(qnt_lista_A < qnt_lista_B){
        menorQuantidadeIntersecao = qnt_lista_B;
    }
    
    int lista_D[menorQuantidadeIntersecao];
    int qnt_lista_D = intersecao(lista_A, qnt_lista_A, lista_B, qnt_lista_B, lista_D, menorQuantidadeIntersecao);
    
    cout << "\n\nImprimindo intersecao (lista d): " << endl;
    listar(lista_D, qnt_lista_D);
    
    // a lista c é intercalada, logo a sua qnt é uma soma entre A e B
    int lista_E[qnt_lista_C];
    int qnt_lista_E = unir(lista_A, qnt_lista_A, lista_B, qnt_lista_B, lista_E);
    
    cout << "\n\nImprimindo União entre A e B (E): " << endl;
    listar(lista_E, qnt_lista_E);
    
    int elementoARemover;
    cout << "\n\nInforme o elemento a remover da lista E (União): ";
    cin >> elementoARemover;
    
    int indiceARemover = buscar(lista_E, elementoARemover, qnt_lista_E);
    if(indiceARemover == -1){
        cout << "\n\nHmm... Elemento não encontrado!";
    }else{
        removerPeloIndice(lista_E, qnt_lista_E, indiceARemover);
        cout << "\n\nSucesso!" << endl;
        cout << "\nImprimindo União entre A e B (E), Após remoção: " << endl;
        listar(lista_E, qnt_lista_E);
    }
    
    return 0;
}


void inserirSemRepetir(int lista[], int valor, int &posicao, int tamanhoMax){
    
    if (posicao >= tamanhoMax){
        cout << "ERRO: Lista cheia!" << endl;
        return;
    }
    
    // Se não encontrar o valor...
    if(buscar(lista, valor, posicao) == -1){
        lista[posicao] = valor;
        posicao++;
        return;
    }
}
int buscar(int lista[], int valor, int quantidade){
    int i;
    for(i = 0; i < quantidade; i++){
       if(lista[i] == valor){
           return i;
       }
    }
    
    return -1;
}

void listar(int lista[], int quantidade){
    if(quantidade < 1){
        cout << "Erro! lista vazia" << endl;
        return;
    }
    
    int i;
    for(i = 0; i < quantidade; i++){
        cout << lista[i] << ", ";
    }
}

int intercalar(int lista_A[], int qnt_lista_A, int lista_B[], int qnt_lista_B, int lista_Alvo[]){
    if(qnt_lista_A < 1 || qnt_lista_B < 1 ){
        cout << "ERRO: Uma das listas está vazia!" << endl;
        return 0;
    }
    
    int qnt_lista_Alvo = qnt_lista_A + qnt_lista_B;
    lista_Alvo[qnt_lista_Alvo];
    
    int i, indice_A = 0, indice_B = 0;
    for(i = 0; i < qnt_lista_Alvo; i++){
        if(i % 2 == 0){
            lista_Alvo[i] = lista_A[indice_A];
            indice_A++;
        }else {
            lista_Alvo[i] = lista_B[indice_B];
            indice_B++;
        }
    }
    
    return qnt_lista_Alvo;
}

int intersecao(int lista_A[], int qnt_lista_A, int lista_B[], int qnt_lista_B, int lista_Alvo[], int menorQuantidade){
    
    int qnt_lista_Alvo = 0;
    
    int i, j;
    int indiceAlvo = 0;
    for(i = 0; i < qnt_lista_A; i++){
        for(j = 0; j < qnt_lista_B; j++){
            if(lista_A[i] == lista_B[j]){
                lista_Alvo[indiceAlvo] = lista_B[j];
                indiceAlvo ++;
                qnt_lista_Alvo++;
            }
        }
    }
    
    return qnt_lista_Alvo;
}

int unir(int lista_A[], int qnt_lista_A, int lista_B[], int qnt_lista_B, int lista_Alvo[]){
    int tamanhoMax = qnt_lista_A + qnt_lista_B;
    lista_Alvo[tamanhoMax];
    
    int qnt_lista_Alvo = 0;
    
    int i;
    int indiceAlvo = 0;
    for(i = 0; i < qnt_lista_A; i++){
        inserirSemRepetir(lista_Alvo, lista_A[i], qnt_lista_Alvo, tamanhoMax);
    }
    
    int j;
    for(j = 0; j < qnt_lista_B; j++){
        inserirSemRepetir(lista_Alvo, lista_B[j], qnt_lista_Alvo, tamanhoMax);
    }
    
    return qnt_lista_Alvo;
}

void removerPeloIndice(int lista[], int &quantidadeLista, int indice){
    
    if(indice == lista[quantidadeLista - 1]){
        quantidadeLista--;
        return;
    }
    
    int ultimoElemento = lista[quantidadeLista - 1];
    lista[indice] = ultimoElemento;
    
    quantidadeLista--;
}


