// ============================================================
// Conversor.hpp
// Funcoes para converter uma expressao infixa para
// Notacao Polonesa Invertida (NPI), usando pilhas e filas.
// ============================================================

#ifndef CONVERSOR_HPP
#define CONVERSOR_HPP

#include <iostream>
#include <string>
// NOTA: Pilha e Fila ja sao incluidos pelo main.cpp antes deste arquivo.
// Expressao.hpp tambem ja foi incluido antes. Nao repetir aqui para evitar
// redefinicao (os .hpp originais nao possuem include guard).

using namespace std;

// ============================================================
// converterParaNPI
//
// Recebe a expressao (string) e preenche a fila 'saida'
// com os tokens na ordem da Notacao Polonesa Invertida.
//
// Retorna true se tudo correu bem, false se houver erro.
//
// Algoritmo usado: Shunting Yard (de Dijkstra)
// Regras simples:
//   - Numero ou variavel -> vai direto para a fila de saida
//   - Operador           -> vai para a pilha de operadores
//                          (antes, descarrega os de maior prioridade)
//   - Abre-parentese     -> empilha
//   - Fecha-parentese    -> descarrega ate encontrar o abre correspondente
// ============================================================
bool converterParaNPI(string expressao, Filad<char> &saida) {

    // Pilha para guardar operadores e parenteses temporariamente
    Pilhad<char> pilhaOp;
    inicializarPilhad(pilhaOp);

    // Pilha separada so para verificar se os parenteses/colchetes/chaves
    // estao sendo fechados na ordem e tipo corretos
    Pilhad<char> pilhaParenteses;
    inicializarPilhad(pilhaParenteses);

    int tamanho = expressao.size();

    for (int i = 0; i < tamanho; i++) {
        char c = expressao[i];

        // Ignora espacos em branco
        if (c == ' ') continue;

        // --- NUMERO (apenas um digito, conforme enunciado) ---
        if (c >= '0' && c <= '9') {
            queueFilad(saida, c);

        // --- VARIAVEL (apenas uma letra minuscula ou maiuscula) ---
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            queueFilad(saida, c);

        // --- OPERADOR (+, -, *, /, ^) ---
        } else if (ehOperador(c)) {
            char topo;

            // Enquanto houver operador no topo da pilha com prioridade
            // maior ou igual, retira ele e manda para a saida
            // (exceto '^' que e direito-associativo: nao descarrega igual)
            while (!vaziaPilhad(pilhaOp)) {
                topPilhad(pilhaOp, topo);

                if (ehOperador(topo) && precedencia(topo) >= precedencia(c) && c != '^') {
                    popPilhad(pilhaOp, topo);
                    queueFilad(saida, topo);
                } else {
                    break;
                }
            }

            // Empilha o operador atual
            pushPilhad(pilhaOp, c);

        // --- ABRE PARENTESE, COLCHETE OU CHAVE ---
        } else if (ehAbre(c)) {
            pushPilhad(pilhaOp, c);           // Guarda na pilha de operadores
            pushPilhad(pilhaParenteses, c);   // Guarda para verificar casamento

        // --- FECHA PARENTESE, COLCHETE OU CHAVE ---
        } else if (ehFecha(c)) {

            // Erro: fechar sem ter aberto nada
            if (vaziaPilhad(pilhaParenteses)) {
                cout << "ERRO: Fechamento '" << c << "' sem abertura correspondente!" << endl;
                return false;
            }

            // Erro: o tipo nao combina (ex: abriu '[' mas fechou com ')')
            char abreCorrespondente;
            topPilhad(pilhaParenteses, abreCorrespondente);

            if (!combinam(abreCorrespondente, c)) {
                cout << "ERRO: Fechamento '" << c << "' nao combina com abertura '"
                     << abreCorrespondente << "'!" << endl;
                return false;
            }

            // Remove da pilha de controle de parenteses
            popPilhad(pilhaParenteses, abreCorrespondente);

            // Descarrega operadores da pilha para a saida
            // ate encontrar o abre-parentese correspondente
            char topo;
            bool encontrouAbre = false;

            while (!vaziaPilhad(pilhaOp)) {
                popPilhad(pilhaOp, topo);

                if (ehAbre(topo)) {
                    encontrouAbre = true;
                    break;  // Abre-parentese e descartado (nao vai para saida)
                }

                queueFilad(saida, topo);
            }

            if (!encontrouAbre) {
                cout << "ERRO: Parentese sem par encontrado!" << endl;
                return false;
            }

        // --- CARACTERE INVALIDO ---
        } else {
            cout << "ERRO: Caractere invalido encontrado: '" << c << "'" << endl;
            return false;
        }
    }

    // Ao terminar a expressao, verifica se ficou algum parentese aberto
    if (!vaziaPilhad(pilhaParenteses)) {
        cout << "ERRO: Ha parentese/colchete/chave aberto sem fechamento!" << endl;
        return false;
    }

    // Descarrega o restante dos operadores da pilha para a saida
    char topo;
    while (!vaziaPilhad(pilhaOp)) {
        popPilhad(pilhaOp, topo);

        if (ehAbre(topo)) {
            cout << "ERRO: Parentese sem par encontrado no final!" << endl;
            return false;
        }

        queueFilad(saida, topo);
    }

    return true;
}

// ============================================================
// imprimirFila
//
// Exibe os elementos da fila sem destrui-la.
// Usa pilhas temporarias para percorrer e reconstruir a fila.
// ============================================================
void imprimirFila(Filad<char> &fila) {
    Pilhad<char> temp;
    inicializarPilhad(temp);

    Pilhad<char> temp2;
    inicializarPilhad(temp2);

    char c;
    bool primeiro = true;

    // Esvazia a fila imprimindo e guardando numa pilha
    while (!vaziaFilad(fila)) {
        dequeueFilad(fila, c);

        if (!primeiro) cout << " ";
        cout << c;
        primeiro = false;

        pushPilhad(temp, c);
    }
    cout << endl;

    // Inverte a pilha numa segunda pilha (para restaurar a ordem)
    while (!vaziaPilhad(temp)) {
        popPilhad(temp, c);
        pushPilhad(temp2, c);
    }

    // Reconstroi a fila original
    while (!vaziaPilhad(temp2)) {
        popPilhad(temp2, c);
        queueFilad(fila, c);
    }
}

#endif // CONVERSOR_HPP
