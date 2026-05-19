#include "No.hpp"

template <typename T>
struct Pilhad{
    No <T> *comeco, *fim;
};

template <typename T>
void inicializarPilhad(Pilhad <T> &p){
    p.comeco = nullptr;
    p.fim = nullptr;
}

template <typename T>
bool vaziaPilhad(Pilhad <T> p){
    return (p.fim == nullptr) ? true : false;
}

template <typename T>
bool cheiaPilhad(Pilhad <T> p){
    return false;
}

template <typename T>
bool pushPilhad(Pilhad <T> &p, T valor){
    No <T> *novo = new No<T>;

    if( novo == nullptr ) return false;
    novo->info = valor;
    novo->eloP = nullptr;
    novo->eloA = nullptr;

    if( p.comeco == nullptr ){
        p.comeco = novo;
        p.fim = novo;
    }
    else{
        p.fim->eloP = novo;
        novo->eloA = p.fim;
        p.fim = novo;
    }
    return true;
}

template <typename T>
bool popPilhad(Pilhad <T> &p, T &valor){
    if( vaziaPilhad(p) ) return false;

    No <T> *aux = p.fim;
    if( aux == nullptr ) return false;
    valor = aux->info;

    if( aux == p.comeco && aux == p.fim  ){
        p.comeco = nullptr;
        p.fim = nullptr;
    }
    else {
        p.fim = aux->eloA;
        p.fim->eloP = nullptr;
    }
    delete aux;
    return true;

}

template <typename T>
bool topPilhad(Pilhad <T> &p, T &valor){
    if( vaziaPilhad(p) ) return false;
    valor = p.fim->info;
    return true;
}

template <typename T>
void liberarPilhad(Pilhad <T> &p){
    No <T> *aux = p.comeco;
    No <T> *aux2;
    while( aux != nullptr ){
        aux2 = aux;
        aux = aux->eloP;
        delete aux2;
    }
}
