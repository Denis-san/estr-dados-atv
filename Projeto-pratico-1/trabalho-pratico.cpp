#include <iostream>
#include <string.h>
#include <locale.h>

#define MAX 10
using namespace std;

typedef struct {
	int codigo;	
	string nome; 
	int idade;	//mergesort e quicksort
	int identificador; 
} Paciente;

void cadastrar(Paciente listaPaciente[], Paciente paciente, int &quantidade);

int buscarPorIdentificador(Paciente listaPaciente[], int identificador, int quantidade);
int buscarPorNome(Paciente listaPaciente[], int quantidade, string nome);

void juntar(Paciente listaPaciente[], int inicio, int meio, int fim);
void trocar(Paciente listaPaciente[], int indice1, int indice2);

void ordernarPorQuickSort(Paciente listaPaciente[], int inicio, int fim);
void ordenarPorMergeSort(Paciente listaPaciente[], int inicio, int fim);

void exibirPacientes(Paciente listaPaciente[], int quantidade);

int main(void){
    
    setlocale(LC_ALL, "Portuguese");

	int opcao = -1;
	Paciente listaPaciente[10]; 
	
	Paciente pacienteDados;
	
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
		    	
                if(codigo > 0){
                    cout << "\nNome: " << listaPaciente[codigo].nome << endl;
                    cout << "Idade: " << listaPaciente[codigo].idade << endl;
                    cout << "identificador: " << listaPaciente[codigo].identificador << endl << endl;
                }

                cout << "Paciente não encontrado!" << endl;
				break;	
			case(3):
				cout << "\nDigite o identificador do paciente a ser buscado: ";
				cin >> identificador;
				
				codigo = buscarPorIdentificador(listaPaciente, identificador, quantidade);
				
				if(codigo > 0){
					cout << "\nNome: " << listaPaciente[codigo].nome << endl;
		        	cout << "Idade: " << listaPaciente[codigo].idade << endl;
				    cout << "identificador: " << listaPaciente[codigo].identificador << endl << endl;
				}
			
				cout << "Paciente não encontrado!\n";
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

void cadastrar(Paciente listaPaciente[], Paciente paciente, int &quantidade){
    
    if(quantidade >= MAX){
        cout << "Erro! Lista cheia!";
        return;
    }   

    listaPaciente[quantidade++] = paciente;
}

int buscarPorIdentificador(Paciente listaPaciente[], int identificador, int quantidade) {
    int inicio = 0;
    int fim = quantidade - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        
        if (identificador == listaPaciente[meio].identificador) {
            return meio;
        }
        
        if (identificador < listaPaciente[meio].identificador) { 
            fim = meio - 1;
        }
        
        if (identificador > listaPaciente[meio].identificador) { 
            inicio = meio + 1;
        }
    }
    
    return - 1;
}

int buscarPorNome(Paciente listaPaciente[], int quantidade, string nome){
    int i; 
    
    for(i = 0; i < quantidade; i++){
        if((nome.compare(listaPaciente[i].nome) == 0)){
            return i;
        }
    }
    
    return -1;
}

void ordernarPorQuickSort(Paciente listaPaciente[], int inicio, int fim){
    Paciente pivo = listaPaciente[inicio];
    int i = inicio;
    int indicePivo;
    
    int j;
    for(j = (i+1); j <= (fim  - 1); j++){
        if(listaPaciente[j].idade >= pivo.idade){
            i = i + 1;
            trocar(listaPaciente, i, j);
        }
    }
    
    trocar(listaPaciente, inicio, i);
    indicePivo = i;
    
    if(inicio < fim){
        ordernarPorQuickSort(listaPaciente, inicio, indicePivo); 
        ordernarPorQuickSort(listaPaciente, (indicePivo + 1), fim); 
    }
} 

void trocar(Paciente listaPaciente[], int indice1, int indice2){ 
    Paciente paciente_temp = listaPaciente[indice1]; 
	listaPaciente[indice1] = listaPaciente[indice2]; 
	listaPaciente[indice2] = paciente_temp; 
}

void exibirPacientes(Paciente listaPaciente[], int quantidade){
    
    if(quantidade <= 0){
        cout << "Lista vazia!";
        return;
    }
    
    int i;
    for(i = 0; i < quantidade; i++){
        cout << "Paciente #" << (i+1) << ":\n";
        cout << "\nNome: " << listaPaciente[i].nome << endl;
		cout << "Idade: " << listaPaciente[i].idade << endl;
		cout << "identificador: " << listaPaciente[i].identificador << endl;
        cout << "----------------------------------------------------------\n\n";
    }
}

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
        if (listaPaciente[i].idade < listaPaciente[j].idade) {
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

