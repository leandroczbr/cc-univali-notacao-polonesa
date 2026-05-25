// ============================================================
// Expressao.hpp
// Funcoes auxiliares para verificar e calcular caracteres
// da expressao matematica.
// ============================================================

#ifndef EXPRESSAO_HPP
#define EXPRESSAO_HPP

// Verifica se um caractere e um operador matematico
bool ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Verifica se um caractere e um abre-parentese, colchete ou chave
bool ehAbre(char c) {
    return (c == '(' || c == '[' || c == '{');
}

// Verifica se um caractere e um fecha-parentese, colchete ou chave
bool ehFecha(char c) {
    return (c == ')' || c == ']' || c == '}');
}

// Retorna a precedencia do operador (quanto maior, mais prioritario)
// Ex: '*' e '/' tem mais prioridade que '+' e '-'
int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^')              return 3;
    return 0;
}

// Verifica se o fecha-parentese combina com o abre-parentese
// Ex: '(' so combina com ')', '[' so combina com ']'
bool combinam(char abre, char fecha) {
    if (abre == '(' && fecha == ')') return true;
    if (abre == '[' && fecha == ']') return true;
    if (abre == '{' && fecha == '}') return true;
    return false;
}

// Realiza a operacao matematica entre dois numeros
// Retorna o resultado de: a [operador] b
double calcular(double a, char op, double b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^') {
        // Potencia feita manualmente (sem usar pow() da biblioteca)
        double resultado = 1.0;
        int expoente = (int)b;
        for (int i = 0; i < expoente; i++) {
            resultado *= a;
        }
        return resultado;
    }
    return 0;
}

#endif // EXPRESSAO_HPP
