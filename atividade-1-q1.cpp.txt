#include <iostream>
using namespace std;

void Teste1(int );
void Teste2(int &);
int Teste3(int);

// a) Global
// c) x = 20
int x = 20;

int main(void) {
    
    // a) Locais
    // c) numero = 10, outroNumero = lixo memória
    int numero = 10, outroNumero;
    
    Teste1(numero);
    // c) numero = 10
    cout << "Valor de numero (após Teste1) = " << numero << endl;
    
    // c) x = 21
    cout << "X = " << x << endl;
    
    Teste2(numero);
    
    // c) numero = 110
    cout << "Valor de numero (após Teste2) = " << numero << endl;
    
    // c) x = 22
    cout << "X = " << x << endl;
    
    outroNumero = Teste3(numero);
    
    // c) outroNumero = 310
    cout << "Valor de outro numero (após Teste3) = " << outroNumero << endl;
    
    // c) x = 21
    cout << "X = " << x << endl;
}

void Teste1(int numero) { // b) Por valor
    // a) Local
    numero = numero +x ;
    x++;
}
void Teste2(int &numero) { // b) Por referência
    // a) Local
    int valor = 100;
    numero = numero + valor;
    x++;
}
int Teste3(int n) { // b) Por valor
    // a) Local
    int valor = 200;
    n = n + valor;
    x--;
    return n;
}

// Respostas:

// a) Identifique as variáveis globais e locais. Quando identificar uma variável local, especifique o escopo da mesma.

// b) Identifique, em cada função, o tipo de passagem de parâmetros.

// c) Mostre, passo a passo, o valor de todas as variáveis, indicando o momento em que as variáveis não mais ocupam espaço na memória.
// - A variável global (x) não mais ocupam espaço na memória quando é encerrado o programa.
// - As Variáveis de escopo local  não mais ocupam espaço na memória quando é encerrado o subprograma, ou seja, a função à quem pertece.

// d) Diga o que é impresso na tela
// - Valor da variavel numero (após a função Teste1), que é igual a 10, depois,
// - a variável x incrementada: X = 21, 
// - o valor da variavel numero (após a função  Teste2) que é igual a 110, 
// - a variável x incrementada: X = 22, 
// - Valor da variavel "outro numero" (após a função Teste3) que é igual a 310 e por fim, 
// - a variável x decrementada: X = 21, 
