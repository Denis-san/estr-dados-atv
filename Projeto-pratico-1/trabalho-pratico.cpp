#include <iostream>
#include <string.h>
#include <locale.h>

#define MAX 10
using namespace std;

typedef struct {
	int codigo;	
	string nome; 
	int idade;	//merge sort
	int identificador; 
} Paciente;

void cadastrar(Paciente listaPaciente[], Paciente paciente, int &quantidade);
int buscarPorIdentificador(Paciente listaPaciente[], int identificador, int quantidade);
int buscarPorNome(Paciente listaPaciente[], int quantidade, string nome);

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
		cout << " 1 - Cadastrar paciente \n 2-Buscar paciente por Nome \n 3-Buscar paciente por Identificador \n 4-Exibir pacientes por ordem de idade " << endl;
		cout << " Digite a opção desejada: ";	
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
				
				cout << endl;
				
				break;
			case(2):
				cout << "\nDigite o nome do paciente a ser buscado: ";
				getline(cin >> ws, nome);
		    	
		    	codigo = buscarPorNome(listaPaciente, quantidade, nome);
		    	
		    	cout << "\nNome: " << listaPaciente[codigo].nome << endl;
				cout << "Idade: " << listaPaciente[codigo].idade << endl;
				cout << "identificador: " << listaPaciente[codigo].identificador << endl << endl;
				
				break;	
			case(3):
				cout << "\nDigite o identificador do paciente a ser buscado: ";
				cin >> identificador;
				
				codigo = buscarPorIdentificador(listaPaciente, identificador, quantidade);
				
				cout << "\nNome: " << listaPaciente[codigo].nome << endl;
				cout << "Idade: " << listaPaciente[codigo].idade << endl;
				cout << "identificador: " << listaPaciente[codigo].identificador << endl << endl;
				break;
			case(4):
			//	exibirPaciente();
			//	break;
			default:
				cout << "Digite uma opção valida " << endl;
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
    
    cout << "Paciente não encontrado!" << endl;
    return -1;
}