#include <iostream>
#include <string>
#include <list>
using namespace std;

struct no{
	int chave;
	string nome;
	no* prox;
	
	no(int k, const string& n): chave(k), nome(n), prox(NULL){} //codigo necessario para a utilização do no dentro da class
};

// Classe para a tabela hash
class TabelaHash{
	private: 
		int tamTabela;
		list<no*>* compartimento;
		
		int espalhamento(int chave){ //função para calcular o indice do espalhamento
			return chave%tamTabela;
		}
	public:
		TabelaHash(int tam) : tamTabela(tam){
			compartimento = new list<no*>[tamTabela];
		}
		void inserir(int chave, const string& nome){ // Função para inserir ou atribuir o valor em um chave na tabela hash
			int indice = espalhamento(chave);
			no* novoNo = new no(chave, nome);
			compartimento[indice].push_back(novoNo);
		}
		string busca(int chave){ //função para procurar o nome com a chave
			int indice = espalhamento(chave);
			for (list<no*>::iterator it = compartimento[indice].begin(); it!=compartimento[indice].end(); ++it){
				if((*it)->chave== chave){
					return (*it)->nome;
				}
			}
		return "";
		}
		void imprimirTabela(){ //Função para imprimir o conteudo da tabela hash
			for(int i=0; i<tamTabela; i++){
				cout << "Compartimento " << i << ": ";
				for(list<no*>::iterator it = compartimento[i].begin(); it!=compartimento[i].end(); ++it) {
					cout << "(" << (*it)->chave << ", "<<(*it)->nome<<") "; 
				}
				cout << endl;
			}
		}
		void remover(int chave){
			int indice = espalhamento(chave);
			for(list<no*>::iterator it = compartimento[indice].begin(); it!=compartimento[indice].end(); ++it){
				if((*it)->chave == chave){
					no* removedor = *it;
					compartimento[indice].erase(it);
					delete removedor;
					return;
				}
			}
		}
		~TabelaHash(){
			for (int i=0; i< tamTabela; i++){
				for(list<no*>::iterator it = compartimento[i].begin(); it!=compartimento[i].end(); ++it)
					delete *it;
			}
			delete[] compartimento;
		}		
};

int main(){
	TabelaHash tabelaHash(20);	
	
	tabelaHash.inserir(1, "Josue");
	tabelaHash.inserir(33, "Aligator");
	tabelaHash.inserir(45, "Manoel Gomes");
	tabelaHash.inserir(35, "A Feiticeira");
	tabelaHash.inserir(98, "Vinicin");
	tabelaHash.inserir(75, "Joaquin");
	tabelaHash.inserir(88, "Toninho");
						
	int chavedebusca = 35;
	string resultadobusca = tabelaHash.busca(chavedebusca);
	if(!resultadobusca.empty())
		cout << "Valor encontrado com a chave: " << chavedebusca <<": " << resultadobusca << endl;
	else cout << "Valor não encontrado com a chave: "<< chavedebusca << endl;
	
	cout<< "Tabela Hash: "<< endl;
	tabelaHash.imprimirTabela();
	
	int chaveremovida = 75;
	tabelaHash.remover(chaveremovida);
	cout << "removido a chave:" << chaveremovida << endl;
	cout << "Tabela Hash: "<<endl;
	tabelaHash.imprimirTabela();
	
	return 0;
}