#include <iostream>
#include <string.h>
#include <locale.h>

#define MAX 10
using namespace std;

// Trecho struct -> O(1)
typedef struct { 
	int codigo;	
	string nome; 
	int idade;	//mergesort e quicksort
	int identificador; 
} Paciente;

void cadastrar(Paciente listaPaciente[], Paciente paciente, int &quantidade);

Paciente buscarPorIdentificador(Paciente listaPaciente[], int identificador, int quantidade);
int buscarPorNome(Paciente listaPaciente[], int quantidade, string nome);

void juntar(Paciente listaPaciente[], int inicio, int meio, int fim);
void trocar(Paciente listaPaciente[], int indice1, int indice2);

void ordernarPorQuickSort(Paciente listaPaciente[], int inicio, int fim);
void ordenarPorMergeSort(Paciente listaPaciente[], int inicio, int fim);
void bubbleSort(Paciente listaPaciente[] , int quantidade);

void exibirPacientes(Paciente listaPaciente[], int quantidade);

int main(void){
    
    setlocale(LC_ALL, "Portuguese");

	int opcao = -1;
	Paciente listaPaciente[10]; 
	
	Paciente pacienteDados, resultadoBusca;
	
	string nome;
	int identificador = 0;
	int codigo = 0;
	int quantidade = 0;

	while(opcao != 0){
	    cout << "\n+----------------------------------------------------------+\n";
        cout << "| 1 - Cadastrar paciente                                   |\n";
        cout << "| 2 - Buscar paciente por Nome                             |\n";
        cout << "| 3 - Buscar paciente por Identificador                    |\n";
        cout << "| 4 - Exibir pacientes por ordem de idade (com QuickSort)  |\n";
        cout << "| 5 - Exibir pacientes por ordem de idade (com MergeSort)  |\n";
        cout << "| 0 - Encerrar o programa                                  |\n";
        cout << "+----------------------------------------------------------+\n";
        
		cout << "\n - Digite a opção desejada: ";	
		cin >> opcao;
		switch(opcao){
			case(1): 
			    cout << "\nDigite o nome do paciente: ";
			    getline(cin >> ws, pacienteDados.nome);
			    
			    cout << "Digite a idade paciente: ";
			    cin >> pacienteDados.idade;
			    
			    cout << "Digite o identificador (cpf) paciente: ";
			    cin >> pacienteDados.identificador;
			    
			    pacienteDados.codigo = quantidade;
			    
				cadastrar(listaPaciente, pacienteDados, quantidade);
				
				cout << "SUCESSO!" << endl;
				break;

			case(2):
				cout << "\nDigite o nome do paciente a ser buscado: ";
				getline(cin >> ws, nome);
		    	
		    	codigo = buscarPorNome(listaPaciente, quantidade, nome);
		    	
                if(codigo > -1){
                    cout << "\nNome: " << listaPaciente[codigo].nome << endl;
                    cout << "Idade: " << listaPaciente[codigo].idade << endl;
                    cout << "identificador: " << listaPaciente[codigo].identificador << endl << endl;
                } else {
                    cout << "Paciente não encontrado!" << endl;
                }
				break;

			case(3):
				cout << "\nDigite o identificador do paciente a ser buscado: ";
				cin >> identificador;
				
				resultadoBusca = buscarPorIdentificador(listaPaciente, identificador, quantidade);
				
				if(resultadoBusca.identificador == identificador){
					cout << "\nNome: " << resultadoBusca.nome << endl;
		        	cout << "Idade: " << resultadoBusca.idade << endl;
				    cout << "identificador: " << resultadoBusca.identificador << endl << endl;
				} else {
                    cout << "Paciente não encontrado!\n";
                }
				break;

			case(4):
			    ordernarPorQuickSort(listaPaciente, 0, quantidade);

			    cout << "----------------------------------------------------------\n";
			    exibirPacientes(listaPaciente, quantidade);
				break;

			case(5):
			    ordenarPorMergeSort(listaPaciente, 0, quantidade-1);
			    
			    cout << "----------------------------------------------------------\n";
			    exibirPacientes(listaPaciente, quantidade);
				break;

			default:
				break;
		}
	}
}

// O(1)
void cadastrar(Paciente listaPaciente[], Paciente paciente, int &quantidade){
    
    if(quantidade >= MAX){  // O(1)
        cout << "Erro! Lista cheia!"; // O(1)
        return; // O(1)
    }   

    listaPaciente[quantidade++] = paciente; // O(1)
} // O(1)+O(1)+O(1)+O(1)+O(1) = O(1)

Paciente buscarPorIdentificador(Paciente listaPaciente[], int identificador, int quantidade) {

	// O(1)
    Paciente novaListaPaciente[MAX]; 
    int i;

    for(i=0; i< quantidade; i++) // O(n)
    novaListaPaciente[i] = listaPaciente[i];
	
    bubbleSort(novaListaPaciente, quantidade); // O(n^2)

	// Trecho com O(1)
    int inicio = 0;
    int fim = quantidade - 1;
    int meio = fim/2;
    int loop = 0;

	// O iterador do laço é divido em duas partes e vai reduzindo o tamanho (n) do vetor, 
	// ex: [1,2,3,4,5,6,7,8] / 2
	// 	   [1,2,3,4] / 2
	// 	   [1,2] / 2
	// 	   [1]
	// A base da divisão: 2
	// tamanho do vetor: 8
	// numero de repetições: 3
	// log de 3 na base 2 é 8. Ou seja log2(3) = 8 -> log(tamanho-vetor) = numero de repetições; 
    while (loop != -1) { // O(log(n))

        if (fim == inicio) loop = -1; // Implica na "interrupção do laço"
            
        if (identificador < novaListaPaciente[meio].identificador) { 
            fim = meio - 1;
            meio = (fim+inicio)/2;
        }
        
        else if (identificador > novaListaPaciente[meio].identificador) { 
            inicio = meio + 1;
            meio = (fim+inicio)/2;
        }

        if (identificador == novaListaPaciente[meio].identificador) {
            return novaListaPaciente[meio];
        }
    }

    return novaListaPaciente[meio];
} // ignorando os trechos O(1) (constantes): O(n)+O(n^2)+O(log(n)) = O(n^2)

// O(n)
int buscarPorNome(Paciente listaPaciente[], int quantidade, string nome){
    int i;  // O(1)
    
    for(i = 0; i < quantidade; i++){ // O(n)
        if((nome.compare(listaPaciente[i].nome) == 0)){ // O(1)
            return i;
        }
    }
    
    return -1;
} // O(1)+O(n)+O(1)= O(n)

// O(n^2)
void ordernarPorQuickSort(Paciente listaPaciente[], int inicio, int fim){
    Paciente pivo = listaPaciente[inicio]; // Trecho com O(1)
    int i = inicio;
    int indicePivo;
    
    int j;
    for(j = (i+1); j <= (fim  - 1); j++){ // O(n) #1
        if(listaPaciente[j].idade >= pivo.idade){ // O(1) [3,2,8,1,67,5]
            i = i + 1; // O(1)
            trocar(listaPaciente, i, j); // O(1)
        }
    }
    
    trocar(listaPaciente, inicio, i); // O(1)
    indicePivo = i; // O(1)
    
    if(inicio < fim){
        ordernarPorQuickSort(listaPaciente, inicio, indicePivo); // Como estamos "quebrando" o vetor, ele terá ("n" - algo) -> n; logo O(n) #2
        ordernarPorQuickSort(listaPaciente, (indicePivo + 1), fim); // analago -> O(n) #3
    }
} // ignorando os trechos O(1): O(n)*O(n) + O(n)*O(n)-> O(n^2)+O(n^2) -> O(n^2)
  //							 #1   #2     #1   #3

// Todo escopo da função é O(1)
void trocar(Paciente listaPaciente[], int indice1, int indice2){ 
    Paciente paciente_temp = listaPaciente[indice1]; 
	listaPaciente[indice1] = listaPaciente[indice2]; 
	listaPaciente[indice2] = paciente_temp; 
}

void exibirPacientes(Paciente listaPaciente[], int quantidade){
    
	// Trecho com O(1)
    if(quantidade <= 0){
        cout << "Lista vazia!";
        return;
    }
    
    int i;
    for(i = 0; i < quantidade; i++){  // O(n)
        cout << "Paciente #" << (i+1) << ":\n";
        cout << "\nNome: " << listaPaciente[i].nome << endl;
		cout << "Idade: " << listaPaciente[i].idade << endl;
		cout << "identificador: " << listaPaciente[i].identificador << endl;
        cout << "----------------------------------------------------------\n\n";
    }
} // O(1)+O(n) = O(n)

void ordenarPorMergeSort(Paciente listaPaciente[], int inicio, int fim){
	int meio;
	if(inicio<fim){
		meio = (inicio+fim)/2;
		ordenarPorMergeSort(listaPaciente,inicio,meio);
		ordenarPorMergeSort(listaPaciente,meio+1,fim);
		juntar(listaPaciente,inicio,meio,fim);
	}
}

void juntar(Paciente listaPaciente[], int inicio, int meio, int fim){
    int i, j, k;
	Paciente listaPaciente_temp[fim+1];
    i = inicio;
    k = inicio;
    j = meio + 1;
    while (i <= meio && j <= fim) {
        if (listaPaciente[i].idade > listaPaciente[j].idade) {
            listaPaciente_temp[k] = listaPaciente[i];
            k++;
            i++;
        }
        else  {
            listaPaciente_temp[k] = listaPaciente[j];
            k++;
            j++;
        }
    }
    while (i <= meio) {
        listaPaciente_temp[k] = listaPaciente[i]; 
        k++;
        i++;
    }
    while (j <= fim) {
        listaPaciente_temp[k] = listaPaciente[j];
        k++;
        j++;
    }
    for (i = inicio; i < k; i++)  {
        listaPaciente[i] = listaPaciente_temp[i];
    }
}

// O(n^2)
void bubbleSort(Paciente listaPaciente[], int quantidade) {
	int i,j=1;  // O(1)
    Paciente aux; // O(1)
	while(j != 0) {  // O(n)
		j=0;
		for(i = 0; i < quantidade; i++) { // O(n)
			if(listaPaciente[i].identificador > listaPaciente[i+1].identificador) { // Trecho com O(1)
				aux = listaPaciente[i];
				listaPaciente[i] = listaPaciente[i+1];
				listaPaciente[i+1] = aux;
				j++;
			}
		}
	}
} // Ignorando os trechos com O(1): O(n)*O(n) = O(n^2)
