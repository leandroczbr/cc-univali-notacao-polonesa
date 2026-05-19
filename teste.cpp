#include "FilaEstatica.hpp"
#include "PilhaDinamica.hpp" // Ensure this header file defines the class PilhaEncadeada
#include "FilaDinamica.hpp"
#include "PilhaEstatica.hpp"
#include <iostream>
//#include "No.hpp"

using namespace std;

int main() {
    // Testing Pilha Estatica
    cout << "=== Testing Pilha Estatica ===" << endl;

    Pilhae<int> p;
    inicializarPilhae(p);
    cout << "Is the stack empty? " << (vaziaPilhae(p) ? "Yes" : "No") << endl;

    cout << "Pushing values 10, 20, 30 onto the stack..." << endl;
    pushPilhae(p, 10);
    pushPilhae(p, 20);
    pushPilhae(p, 30);

    int valor;
    topPilhae(p, valor);
    cout << "Top of the stack: " << valor << endl;

    popPilhae(p, valor);
    cout << "Popped value: " << valor << endl;

    cout << "Releasing the stack..." << endl;
    liberarPilhae(p);
    cout << "Stack released." << endl;

    // Add a separator for clarity
    cout << "\n=============================\n" << endl;

    // Testing Fila Estatica
    cout << "=== Testing Fila Estatica ===" << endl;

    Filae<int> f;
    inicializarFilae(f);
    cout << "Is the queue empty? " << (vaziaFilae(f) ? "Yes" : "No") << endl;

    cout << "Enqueuing values 100, 200, 300 into the queue..." << endl;
    queueFilae(f, 100);
    queueFilae(f, 200);
    queueFilae(f, 300);

    int valorFila;
    dequeueFilae(f, valorFila);
    cout << "Dequeued value: " << valorFila << endl;

    dequeueFilae(f, valorFila);
    cout << "Dequeued value: " << valorFila << endl;

    cout << "Releasing the queue..." << endl;
    liberarFilae(f);
    cout << "Queue released." << endl;

    // Add a separator for clarity
    cout << "\n=============================\n" << endl;

    // Testing Pilha Dinamica
    cout << "=== Testing Pilha Dinamica ===" << endl;

    Pilhad<int> pd;
    inicializarPilhad(pd);
    cout << "Is the dynamic stack empty? " << (vaziaPilhad(pd) ? "Yes" : "No") << endl;

    cout << "Pushing values 1000, 2000, 3000 onto the dynamic stack..." << endl;
    pushPilhad(pd, 1000);
    pushPilhad(pd, 2000);
    pushPilhad(pd, 3000);

    int valorPilhad;
    topPilhad(pd, valorPilhad);
    cout << "Top of the dynamic stack: " << valorPilhad << endl;

    popPilhad(pd, valorPilhad);
    cout << "Popped value: " << valorPilhad << endl;

    cout << "Releasing the dynamic stack..." << endl;
    liberarPilhad(pd);
    cout << "Dynamic stack released." << endl;

    // Add a separator for clarity
    cout << "\n=============================\n" << endl;

    // Testing Fila Dinamica
    cout << "=== Testing Fila Dinamica ===" << endl;

    Filad<int> fd;
    inicializarFilad(fd);
    cout << "Is the dynamic queue empty? " << (vaziaFilad(fd) ? "Yes" : "No") << endl;

    cout << "Enqueuing values 500, 600, 700 into the dynamic queue..." << endl;
    queueFilad(fd, 500);
    queueFilad(fd, 600);
    queueFilad(fd, 700);

    int valorFilad;
    dequeueFilad(fd, valorFilad);
    cout << "Dequeued value: " << valorFilad << endl;

    dequeueFilad(fd, valorFilad);
    cout << "Dequeued value: " << valorFilad << endl;

    cout << "Releasing the dynamic queue..." << endl;
    liberarFilad(fd);
    cout << "Dynamic queue released." << endl;

    return 0;
}