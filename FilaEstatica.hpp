
#define TAM 50
#endif

template <typename T>
struct Filae{
    T vetor[TAM];
    int comeco, fim;
};

template <typename T>
void inicializarFilae(Filae <T> &f){
    f.comeco = 0;
    f.fim = -1;
}

template <typename T>
bool vaziaFilae(Filae <T> f){
    return (f.comeco > f.fim) ? true : false;
}

template <typename T>
bool cheiaFilae(Filae <T> f){
    return (f.fim == TAM-1) ? true : false;
}

template <typename T>
bool queueFilae(Filae <T> &f, T valor){
    if( cheiaFilae(f) ) return false;
    f.fim++;
    f.vetor[f.fim] = valor;
    return true;
}

template <typename T>
bool dequeueFilae(Filae <T> &f, T &valor){
    if( vaziaFilae(f) ) return false;
    valor = f.vetor[f.comeco];
    f.comeco++;
    return true;
}

template <typename T>
void liberarFilae(Filae <T> *f){
    delete[] f->vetor;
    delete f;
}
