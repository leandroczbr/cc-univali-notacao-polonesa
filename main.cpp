#include <iostream>
#include <cctype>
#include "FilaDinamica.hpp"
#include "PilhaDinamica.hpp"

using namespace std;

int main() {
cout << "Programa iniciou\n";

    string expressao = "5x * 5";

    //cria as estruturas
    Filad<char> operandos;
    Pilhad<char> operadores;

    //inicializa
    inicializarFilad(operandos);
    inicializarPilhad(operadores);

    for (char c : expressao) {

    cout << "Lendo: " << c << endl;

    if (c == ' ')
        continue;

    if (isdigit(c) || isalpha(c)) {
        cout << "Operando encontrado\n";
        queueFilad(operandos, c);
    }

    else if (c == '+' || c == '-' || c == '*' || c == '/') {
        cout << "Operador encontrado\n";
        pushPilhad(operadores, c);
    }
}

    cout << "Operandos:\n";

    char valor;

    while (!vaziaFilad(operandos)) {
        dequeueFilad(operandos, valor);
        cout << valor << endl;
    }

    cout << "\nOperadores:\n";

    while (!vaziaPilhad(operadores)) {
        popPilhad(operadores, valor);
        cout << valor << endl;
    }

    return 0;
}