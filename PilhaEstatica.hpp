#ifndef TAM
#define TAM 50
#endif

template <typename T>
struct Pilhae{
    T vetor[TAM];
    int topo;
};

template <typename T>
void inicializarPilhae(Pilhae <T> &p){
    p.topo = -1;
}

template <typename T>
bool vaziaPilhae(Pilhae <T> p){
    return (p.topo == -1) ? true : false;
}

template <typename T>
bool cheiaPilhae(Pilhae <T> p){
    return (p.topo == TAM-1) ? true : false;
}

template <typename T>
bool pushPilhae(Pilhae <T> &p, T valor){
    if( cheiaPilhae(p) ) return false;
    p.topo++;
    p.vetor[p.topo] = valor;
    return true;
}

template <typename T>
bool popPilhae(Pilhae <T> &p, T &valor){
    if( vaziaPilhae(p) ) return false;
    valor = p.vetor[p.topo];
    p.topo--;
    return true;
}

template <typename T>
bool topPilhae(Pilhae <T> &p, T &valor){
    if( vaziaPilhae(p) ) return false;
    valor = p.vetor[p.topo];
    return true;
}

template <typename T>
void liberarPilhae(Pilhae <T> p){

}
