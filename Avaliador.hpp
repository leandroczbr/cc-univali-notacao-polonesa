#ifndef AVALIADOR_HPP
#define AVALIADOR_HPP


void coletarVariaveis(Filad<char> &fila, char variaveis[], int &totalVariaveis) {
    totalVariaveis = 0;

    // Mesma logica da impressao
    Pilhad<char> temp;
    inicializarPilhad(temp);

    Pilhad<char> temp2;
    inicializarPilhad(temp2);

    char c;
    while (!vaziaFilad(fila)) {
        dequeueFilad(fila, c);

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { // verifica se valores são variaveis

            // verifica se já existe
            bool jaExiste = false;
            for (int i = 0; i < totalVariaveis; i++) {
                if (variaveis[i] == c) {
                    jaExiste = true;
                    break;
                }
            }

            if (!jaExiste) { // Bota no total de variaveis
                variaveis[totalVariaveis] = c;
                totalVariaveis++;
            }
        }

        pushPilhad(temp, c);
    }
    //// Apenas vira
    while (!vaziaPilhad(temp)) {
        popPilhad(temp, c);
        pushPilhad(temp2, c);
    }
    while (!vaziaPilhad(temp2)) {
        popPilhad(temp2, c);
        queueFilad(fila, c);
    }
}


double avaliarNPI(Filad<char> &fila, char variaveis[], double valores[], int totalVariaveis) {
    Pilhad<double> pilhaNumeros;
    inicializarPilhad(pilhaNumeros);

    char c;

    while (!vaziaFilad(fila)) {
        dequeueFilad(fila, c);

        if (c >= '0' && c <= '9') { // se numero
            double numero = c - '0'; // char pra numero
            pushPilhad(pilhaNumeros, numero);

        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {// se variavel
            double valorVar = 0;
            for (int i = 0; i < totalVariaveis; i++) {
                if (variaveis[i] == c) {
                    valorVar = valores[i]; /// substitui variavel pelo valor
                    break;
                }
            }
            pushPilhad(pilhaNumeros, valorVar);

        } else if (ehOperador(c)) { // Tira numeros da operacao, e resolve
            double b, a;
            popPilhad(pilhaNumeros, b);
            popPilhad(pilhaNumeros, a);

            double resultado = calcular(a, c, b);
            pushPilhad(pilhaNumeros, resultado);
        }
    }
    double resultado;///só vai restar o resultado
    popPilhad(pilhaNumeros, resultado);
    return resultado;
}

#endif 
