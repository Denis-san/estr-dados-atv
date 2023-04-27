#include <iostream>
#include <string.h>
#include <locale.h>

#define MAX 10
using namespace std;

typedef struct {
	int codigo;	
	string nome; 
	int idade;
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
    
    setlocale(LC_ALL, "Portuguese"); // O(1)

	int opcao = -1; // O(1)
	Paciente listaPaciente[10];  // O(1)
	
	Paciente pacienteDados, resultadoBusca; // O(1)
	
	string nome; // O(1)
	int identificador = 0; // O(1)
	int codigo = 0; // O(1)
	int quantidade = 0; // O(1)

    // populando a lista (trecho com O(1))
    Paciente paciente1; 
	paciente1.nome = "Josue";
	paciente1.idade = 47;
	paciente1.identificador = 345;
	
	Paciente paciente2; 
	paciente2.nome = "Maria";
	paciente2.idade = 67;
	paciente2.identificador = 987;
	
	Paciente paciente3; 
	paciente3.nome = "Paulo";
	paciente3.idade = 55;
	paciente3.identificador = 111;
	
	cadastrar(listaPaciente, paciente1, quantidade);
	cadastrar(listaPaciente, paciente2, quantidade);
	cadastrar(listaPaciente, paciente3, quantidade);

	while(opcao != 0){ // O(n) complexidade linear 
	    cout << "\n+----------------------------------------------------------+\n"; // O(1)
        cout << "| 1 - Cadastrar paciente                                   |\n"; // O(1)
        cout << "| 2 - Buscar paciente por Nome                             |\n"; // O(1)
        cout << "| 3 - Buscar paciente por Identificador                    |\n"; // O(1)
        cout << "| 4 - Exibir pacientes por ordem de idade (com QuickSort)  |\n"; // O(1)
        cout << "| 5 - Exibir pacientes por ordem de idade (com MergeSort)  |\n"; // O(1)
        cout << "| 0 - Encerrar o programa                                  |\n"; // O(1)
        cout << "+----------------------------------------------------------+\n"; // O(1)
        
		cout << "\n - Digite a opção desejada: ";	// O(1)
		cin >> opcao;// O(1)
		
		switch(opcao){ // constante de o(1) 
			case(1):  // O(1)
			    cout << "\nDigite o nome do paciente: "; // O(1)
			    getline(cin >> ws, pacienteDados.nome); // O(1)
			    
			    cout << "Digite a idade paciente: "; // O(1)
			    cin >> pacienteDados.idade; // O(1)
			    
			    cout << "Digite o identificador (cpf) paciente: "; // O(1)
			    cin >> pacienteDados.identificador; // O(1)
			    
			    pacienteDados.codigo = quantidade; // O(1)
			    
				cadastrar(listaPaciente, pacienteDados, quantidade); // Constante de O(1)
				
				cout << "SUCESSO!" << endl; // O(1)
				break;

			case(2): // O(1)
				cout << "\nDigite o nome do paciente a ser buscado: "; // O(1)
				getline(cin >> ws, nome); // O(1)
		    	
		    	codigo = buscarPorNome(listaPaciente, quantidade, nome); // O(n)
		    	
                if(codigo > -1){ // O(1)
                    cout << "\nNome: " << listaPaciente[codigo].nome << endl; // O(1)
                    cout << "Idade: " << listaPaciente[codigo].idade << endl; // O(1)
                    cout << "identificador: " << listaPaciente[codigo].identificador << endl << endl; // O(1)
                } else {
                    cout << "Paciente não encontrado!" << endl; // O(1)
                }
				break;

			case(3):
				cout << "\nDigite o identificador do paciente a ser buscado: "; // O(1)
				cin >> identificador; // O(1)
				
				resultadoBusca = buscarPorIdentificador(listaPaciente, identificador, quantidade); // Log (n)
				
				if(resultadoBusca.identificador == identificador){ // O(1)
					cout << "\nNome: " << resultadoBusca.nome << endl; // O(1)
		        	cout << "Idade: " << resultadoBusca.idade << endl; // O(1)
				    cout << "identificador: " << resultadoBusca.identificador << endl << endl; // O(1)
				} else { // O(1)
                    cout << "Paciente não encontrado!\n"; // O(1)
                }
				break;

			case(4): // O(1)
			    ordernarPorQuickSort(listaPaciente, 0, quantidade); //  O(n^2) complexidade quadratica 

			    cout << "----------------------------------------------------------\n"; // O(1)
			    exibirPacientes(listaPaciente, quantidade); // O(n) complexidade linear
				break; 

			case(5): // O(1)
			    ordenarPorMergeSort(listaPaciente, 0, quantidade-1);  // O(n log n) complexidade n log de n;
			    
			    cout << "----------------------------------------------------------\n"; // O(1)
			    exibirPacientes(listaPaciente, quantidade);  // O(n) complexidade linear
				break; 

			default: // O(1)
				break;
		}
	}
}

void cadastrar(Paciente listaPaciente[], Paciente paciente, int &quantidade){ // Constante de O(1)
    
    if(quantidade >= MAX){ // O(1)
        cout << "Erro! Lista cheia!"; // O(1)
        return; // O(1)
    }   

    listaPaciente[quantidade++] = paciente; // O(1)
}
// O(1)+O(1)+O(1)+O(1)+O(1) = O(1)

Paciente buscarPorIdentificador(Paciente listaPaciente[], int identificador, int quantidade) {

    Paciente novaListaPaciente[MAX]; // O(1)
    int i;// O(1)

    for(i=0; i< quantidade; i++)  novaListaPaciente[i] = listaPaciente[i]; //O(n)
	
    bubbleSort(novaListaPaciente, quantidade);// O(n^2)

    int inicio = 0; // O(1)
    int fim = quantidade - 1; // O(1)
    int meio = fim/2; // O(1)
    int loop = 0; // O(1)

	// O iterador do laço é divido em duas partes e vai reduzindo o tamanho (n) do vetor, 
	// ex: [1,2,3,4,5,6,7,8] / 2
	// 	   [1,2,3,4] / 2
	// 	   [1,2] / 2
	// 	   [1]
	// A base da divisão: 2
	// tamanho do vetor: 8
	// numero de repetições: 3
	// log de 3 na base 2 é 8. Ou seja log2(3) = 8 -> log(tamanho-vetor) = numero de repetições; 
		
    while (loop != -1) { // O(log n)

        if (fim == inicio) loop = -1; // Implica na "interrupção do laço"
            
        if (identificador < novaListaPaciente[meio].identificador) { // O(1)
            fim = meio - 1;// O(1)
            meio = (fim+inicio)/2;// O(1)
        }
        
        else if (identificador > novaListaPaciente[meio].identificador) { // O(1)
            inicio = meio + 1;// O(1)
            meio = (fim+inicio)/2;// O(1)
        }

        if (identificador == novaListaPaciente[meio].identificador) { // O(1)
            return novaListaPaciente[meio]; // O(1)
        }
    }

    return novaListaPaciente[meio]; // O(1)
}

int buscarPorNome(Paciente listaPaciente[], int quantidade, string nome){ //O(N)
    int i; // O(1)
    
    for(i = 0; i < quantidade; i++){ // O(n)
        if((nome.compare(listaPaciente[i].nome) == 0)){  // O(1)
            return i;// O(1)
        }
    }
    
    return -1; // O(1)
}

void ordernarPorQuickSort(Paciente listaPaciente[], int inicio, int fim){ // O(n²)
    Paciente pivo = listaPaciente[inicio]; // O(1)
    int i = inicio; // O(1)
    int indicePivo; // O(1)
    int j;// O(1)
    
    for(j = (i+1); j <= (fim  - 1); j++){ // O(n) #1
        if(listaPaciente[j].idade >= pivo.idade){ // O(1)
            i = i + 1; // O(1)
            trocar(listaPaciente, i, j); // O(1)
        }
    }
    
    trocar(listaPaciente, inicio, i); // O(1)
    indicePivo = i; // O(1)
    
    if(inicio < fim){ // O(1)
        ordernarPorQuickSort(listaPaciente, inicio, indicePivo);  // Como estamos "quebrando" o vetor, ele terá ("n" - algo) -> n; logo O(n) #2
        ordernarPorQuickSort(listaPaciente, (indicePivo + 1), fim); // analago -> O(n) #3
    }
} // ignorando os trechos O(1): O(n)*O(n) + O(n)*O(n)-> O(n^2)+O(n^2) -> O(n^2)
  //							 #1   #2     #1   #3

void trocar(Paciente listaPaciente[], int indice1, int indice2){  // Todo escopo da função é O(1)
    Paciente paciente_temp = listaPaciente[indice1]; 
	listaPaciente[indice1] = listaPaciente[indice2]; 
	listaPaciente[indice2] = paciente_temp; 
}

void exibirPacientes(Paciente listaPaciente[], int quantidade){ //O(n)
    
    if(quantidade <= 0){ // O(1)
        cout << "Lista vazia!"; // O(1)
        return; // O(1)
    }
    
    int i; // O(1)
    for(i = 0; i < quantidade; i++){ //O(n)
    
        cout << "Paciente #" << (i+1) << ":\n"; // O(1)
        cout << "\nNome: " << listaPaciente[i].nome << endl; // O(1)
		cout << "Idade: " << listaPaciente[i].idade << endl; // O(1)
		cout << "identificador: " << listaPaciente[i].identificador << endl; // O(1)
        cout << "----------------------------------------------------------\n\n"; // O(1)
    }
}

void ordenarPorMergeSort(Paciente listaPaciente[], int inicio, int fim){ // O(n log n)
	int meio; // O(1)
	if(inicio<fim){ // O(1)
		meio = (inicio+fim)/2; // O(1)
		ordenarPorMergeSort(listaPaciente,inicio,meio); // O(n log n)
		ordenarPorMergeSort(listaPaciente,meio+1,fim); // O(n log n)
		juntar(listaPaciente,inicio,meio,fim); // O(n)
	}
}

void juntar(Paciente listaPaciente[], int inicio, int meio, int fim){ // O(n)
    int i, j, k; // O(1)
	Paciente listaPaciente_temp[fim+1]; // O(1)
    i = inicio; // O(1)
    k = inicio; // O(1)
    j = meio + 1; // O(1)
    while (i <= meio && j <= fim) { // O(n) complexidade linear
        if (listaPaciente[i].idade > listaPaciente[j].idade) { // O(1)
            listaPaciente_temp[k] = listaPaciente[i]; // O(1)
            k++; // O(1)
            i++; // O(1)
        }
        else  { // O(1)
            listaPaciente_temp[k] = listaPaciente[j]; // O(1)
            k++; // O(1)
            j++; // O(1)
        }
    }
    while (i <= meio) { // O(n) complexidade linear
        listaPaciente_temp[k] = listaPaciente[i]; // O(1)
        k++; // O(1)
        i++; // O(1)
    }
    while (j <= fim) { // O(n) complexidade linear
        listaPaciente_temp[k] = listaPaciente[j]; // O(1)
        k++; // O(1)
        j++; // O(1)
    }
    for (i = inicio; i < k; i++)  { // O(n) complexidade linear
        listaPaciente[i] = listaPaciente_temp[i]; // O(1)
    }
}

void bubbleSort(Paciente listaPaciente[], int quantidade) { // o(n²) complexidade quadratíca 
	int i,j=1; // O(1)
    Paciente aux; // O(1)
	while(j != 0) { // o(n) complexidade linear
		j=0; // O(1)
		for(i = 0; i < quantidade; i++) { // o(n) complexidade linear
			if(listaPaciente[i].identificador > listaPaciente[i+1].identificador) { // O(1)
				aux = listaPaciente[i]; // O(1)
				listaPaciente[i] = listaPaciente[i+1]; // O(1)
				listaPaciente[i+1] = aux; // O(1)
				j++; // O(1)
			}
		}
	}
}