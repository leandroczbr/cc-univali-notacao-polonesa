#include "No.hpp"

template <typename T>
struct Filad{
    No <T> *comeco, *fim;
};

template <typename T>
void inicializarFilad(Filad <T> &f){
    f.comeco = nullptr;
    f.fim = nullptr;
}

template <typename T>
bool vaziaFilad(Filad <T> &f){
    return (f.fim == nullptr) ? true : false;
}

template <typename T>
bool cheiaFilad(Filad <T> &p){
    return false;
}

template <typename T>
bool queueFilad(Filad <T> &f, T valor){
    No <T> *novo = new No<T>;

    if( novo == nullptr ) return false;
    novo->info = valor;
    novo->eloP = nullptr;
    novo->eloA = nullptr;

    if( f.comeco == nullptr ){
        f.comeco = novo;
        f.fim = novo;
    }
    else{
        f.fim->eloP = novo;
        novo->eloA = f.fim;
        f.fim = novo;
    }
    return true;
}

template <typename T>
bool dequeueFilad(Filad <T> &f, T &valor){
    if( vaziaFilad(f) ) return false;

    No <T> *aux = f.comeco;
    if( aux == nullptr ) return false;
    valor = aux->info;

    if( aux == f.comeco && aux == f.fim  ){
        f.comeco = nullptr;
        f.fim = nullptr;
    }
    else {
        f.comeco = aux->eloP;
        f.comeco->eloA = nullptr;
    }
    delete aux;
    return true;

}

template <typename T>
void liberarFilad(Filad <T> *f){
    No <T> *aux = f->comeco;
    No <T> *aux2;
    while( aux != nullptr ){
        aux2 = aux;
        aux = aux->eloP;
        delete aux2;
    }
    delete f;
}
