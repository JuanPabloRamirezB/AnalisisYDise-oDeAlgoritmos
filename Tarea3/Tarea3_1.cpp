#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

// Función recursiva para calcular el promedio
double promedioRecursivo(const std::vector<int>& vec, int n) {
    if (n == 1) return vec[0];
    return (vec[n-1] + (n-1) * promedioRecursivo(vec, n-1)) / n;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <nombre_del_archivo>" << std::endl;
        return 1;
    }

    std::ifstream archivo(argv[1]);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo: " << argv[1] << std::endl;
        return 1;
    }

    int n;
    archivo >> n;
    std::vector<int> valores(n);

    for (int i = 0; i < n; ++i) {
        archivo >> valores[i];
    }

    archivo.close();

    double promedio = promedioRecursivo(valores, n);
    std::cout << "El promedio es: " << promedio << std::endl;

    return 0;
}
