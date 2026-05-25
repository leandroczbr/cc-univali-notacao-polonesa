#ifndef AVALIADOR_HPP
#define AVALIADOR_HPP


void coletarVariaveis(Filad<char> &fila, char variaveis[], int &totalVariaveis) {
    totalVariaveis = 0;

    Pilhad<char> temp;
    inicializarPilhad(temp);

    Pilhad<char> temp2;
    inicializarPilhad(temp2);

    char c;

    //tira da fila e vê cada elemento
    while (!vaziaFilad(fila)) {
        dequeueFilad(fila, c);

        //se letra = variavel
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {

            // Verifica se essa variavel ja foi registrada antes
            bool jaExiste = false;
            for (int i = 0; i < totalVariaveis; i++) {
                if (variaveis[i] == c) {
                    jaExiste = true;
                    break;
                }
            }

            //se for nova, adiciona na lista
            if (!jaExiste) {
                variaveis[totalVariaveis] = c;
                totalVariaveis++;
            }
        }

        pushPilhad(temp, c);
    }

    //mesmo coisa do imprimir
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

        //digito numerico: converte para double e empilha
        if (c >= '0' && c <= '9') {
            double numero = c - '0';
            pushPilhad(pilhaNumeros, numero);

        //se variavel: busca o valor informado pelo usuario e empilha
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            double valorVar = 0;
            for (int i = 0; i < totalVariaveis; i++) {
                if (variaveis[i] == c) {
                    valorVar = valores[i];
                    break;
                }
            }
            pushPilhad(pilhaNumeros, valorVar);

        //operador: pega os dois ultimos valores, opera e empilha o resultado
        } else if (ehOperador(c)) {
            double b, a;
            popPilhad(pilhaNumeros, b);  // b foi empilhado por ultimo (segundo operando)
            popPilhad(pilhaNumeros, a);  // a foi empilhado antes (primeiro operando)

            double resultado = calcular(a, c, b);
            pushPilhad(pilhaNumeros, resultado);
        }
    }

    //resultado final é oq sobrou na pilha
    double resultado;
    popPilhad(pilhaNumeros, resultado);
    return resultado;
}

#endif 
