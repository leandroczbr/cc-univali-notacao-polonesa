// UNIVALI - Escola Politecnica - Ciencia da Computacao
// Disciplina: Estruturas de Dados
// Trabalho 2 - Pilhas e Filas - Notacao Polonesa Invertida
// Integrantes: Gustavo do Amaral da Silva, Leandro C. W. Mattos


#include <iostream>
#include <string>
#include "PilhaDinamica.hpp"  
#include "FilaDinamica.hpp"   
#include "Expressao.hpp"      
#include "Conversor.hpp"      
#include "Avaliador.hpp"    
using namespace std;

int main() {


    cout << "  Conversor e Avaliador de Expressoes" << endl;
    cout << "  Notacao Polonesa Invertida (NPI)" << endl;


    string expressao;
    cout << "\nDigite a expressao matematica:" << endl;
    cout << "  Operadores: +  -  *  /  ^" << endl;
    cout << "  Agrupadores: ()  []  {}" << endl;
    cout << "  Numeros: apenas um digito (0-9)" << endl;
    cout << "  Variaveis: apenas uma letra (a-z ou A-Z)" << endl;
    cout << "\n> ";
    getline(cin, expressao);

    cout << "\n--- Convertendo para Notacao Polonesa Invertida ---" << endl;

    Filad<char> filaRPN;
    inicializarFilad(filaRPN);

    bool sucesso = converterParaNPI(expressao, filaRPN);

    if (!sucesso) {
        cout << "\nConversao falhou. Corrija os erros e tente novamente." << endl;
        return 1;
    }

    cout << "Expressao original : " << expressao << endl;
    cout << "Expressao em NPI   : ";
    imprimirFila(filaRPN);

    //pega as variaveis
    char variaveis[26];
    double valores[26];
    int totalVariaveis = 0;

    coletarVariaveis(filaRPN, variaveis, totalVariaveis);

    //valor das variaveis
    if (totalVariaveis > 0) {
        cout << "\n--- Informe os valores das variaveis ---" << endl;

        for (int i = 0; i < totalVariaveis; i++) {
            cout << "Valor para '" << variaveis[i] << "': ";
            cin >> valores[i];
        }
    }

    //calcula e exibe o resultado
    cout << "\n--- Resultado ---" << endl;

    double resultado = avaliarNPI(filaRPN, variaveis, valores, totalVariaveis);

    cout << "Expressao : " << expressao << endl;
    cout << "Resultado : " << resultado << endl;


    return 0;
}
