#include <iostream>
#include <cstdlib>

// Función recursiva para calcular a^b
int potencia(int a, int b) {
    if (b == 0) return 1;
    return a * potencia(a, b - 1);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <base> <exponente>" << std::endl;
        return 1;
    }

    int a = std::atoi(argv[1]);
    int b = std::atoi(argv[2]);

    if (a <= 0 || b < 0) {
        std::cerr << "Por favor, ingrese dos enteros positivos." << std::endl;
        return 1;
    }

    int resultado = potencia(a, b);
    std::cout << a << "^" << b << " = " << resultado << std::endl;

    return 0;
}
