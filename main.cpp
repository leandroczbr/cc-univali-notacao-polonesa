// ============================================================
// UNIVALI - Escola Politecnica - Ciencia da Computacao
// Disciplina: Estruturas de Dados
// Trabalho 2 - Pilhas e Filas - Notacao Polonesa Invertida
// Integrantes:
//   - [SEU NOME AQUI]
//   - [NOME DO PARCEIRO AQUI]
// ============================================================
//
// ARQUIVOS DO PROJETO:
//   No.hpp          -> Estrutura do no (usada nas versoes dinamicas)
//   PilhaEstatica.hpp -> TAD Pilha com vetor (estatica)
//   PilhaDinamica.hpp -> TAD Pilha com lista encadeada (dinamica)
//   FilaEstatica.hpp  -> TAD Fila com vetor (estatica)
//   FilaDinamica.hpp  -> TAD Fila com lista encadeada (dinamica)
//   Expressao.hpp   -> Funcoes auxiliares (verificar char, calcular)
//   Conversor.hpp   -> Converte expressao infixa para NPI
//   Avaliador.hpp   -> Coleta variaveis e calcula o resultado
//   main.cpp        -> Programa principal (fluxo da aplicacao)
//
// PARA TROCAR ENTRE ESTRUTURA DINAMICA E ESTATICA:
//   1. Troque os #include abaixo (Dinamica <-> Estatica)
//   2. Troque tambem os mesmos includes dentro de Conversor.hpp e Avaliador.hpp
//   3. Troque os tipos e funcoes:
//        Pilhad -> Pilhae     Filad -> Filae
//        inicializarPilhad -> inicializarPilhae
//        inicializarFilad  -> inicializarFilae
//        pushPilhad -> pushPilhae    popPilhad -> popPilhae
//        vaziaPilhad -> vaziaPilhae  topPilhad -> topPilhae
//        queueFilad -> queueFilae    dequeueFilad -> dequeueFilae
//        vaziaFilad -> vaziaFilae
// ============================================================

#include <iostream>
#include <string>
#include "PilhaDinamica.hpp"  // Trocar por PilhaEstatica.hpp para versao estatica
#include "FilaDinamica.hpp"   // Trocar por FilaEstatica.hpp para versao estatica
#include "Expressao.hpp"      // Funcoes auxiliares (deve vir antes de Conversor e Avaliador)
#include "Conversor.hpp"      // Conversao infixa -> NPI
#include "Avaliador.hpp"      // Coleta variaveis e calcula resultado

using namespace std;

int main() {

    cout << "============================================" << endl;
    cout << "  Conversor e Avaliador de Expressoes" << endl;
    cout << "  Notacao Polonesa Invertida (NPI)" << endl;
    cout << "============================================" << endl;

    string expressao;

    cout << "\nDigite a expressao matematica:" << endl;
    cout << "  Operadores: +  -  *  /  ^" << endl;
    cout << "  Agrupadores: ()  []  {}" << endl;
    cout << "  Numeros: apenas um digito (0-9)" << endl;
    cout << "  Variaveis: apenas uma letra (a-z ou A-Z)" << endl;
    cout << "\n> ";
    getline(cin, expressao);

    // --- ETAPA 1: Converter a expressao para NPI ---
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

    // --- ETAPA 2: Coletar as variaveis encontradas na expressao ---
    char variaveis[26];   // Maximo de 26 variaveis diferentes (letras a-z)
    double valores[26];
    int totalVariaveis = 0;

    coletarVariaveis(filaRPN, variaveis, totalVariaveis);

    // --- ETAPA 3: Pedir ao usuario o valor de cada variavel ---
    if (totalVariaveis > 0) {
        cout << "\n--- Informe os valores das variaveis ---" << endl;

        for (int i = 0; i < totalVariaveis; i++) {
            cout << "Valor para '" << variaveis[i] << "': ";
            cin >> valores[i];
        }
    }

    // --- ETAPA 4: Calcular e exibir o resultado ---
    cout << "\n--- Resultado ---" << endl;

    double resultado = avaliarNPI(filaRPN, variaveis, valores, totalVariaveis);

    cout << "Expressao : " << expressao << endl;
    cout << "Resultado : " << resultado << endl;

    cout << "\n============================================" << endl;

    return 0;
}
