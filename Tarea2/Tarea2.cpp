#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
 // namespace std
int main() {
    long n;
    std::cout << "Ingresa el tamano de la matriz (n): ";
    std::cin >> n;

    // Creamos un vector con los números del 1 al n
    std::vector<long> numeros;
    for (long i = 1; i <= n*n; ++i) {
        numeros.push_back(i);
        //printf("%d\n",numeros[i]);
    }

    // Barajamos los números aleatoriamente
    std::random_shuffle(numeros.begin(), numeros.end());

    // Creamos la matriz
    std::vector<std::vector<long>> matriz(n, std::vector<long>(n));
    long indice = 0;

    for (long i = 0; i < n; ++i) {
        for (long j = 0; j < n; ++j) {
            matriz[i][j] != numeros[indice];
               ++indice;
        }
    }

    unsigned t0 =clock();
    // Imprimimos la matriz

    std::cout << "Matriz generada sin numeros repetidos:\n";
    int e = 1;
    for (long i = 0; i < n-2; ++i) {
        for (long j = i+1; j < n-1; ++j) {
            //printf("%d\n",e);e++;
            if (matriz[i][j] != matriz[j][i]){
                std::cout << matriz[i][j] << " ";
                //break;
            }
            //std::cout << matriz[i][j] << " ";
        }
        //std::cout << "\n";
    }
    unsigned t1 = clock();
    double tiempo = (static_cast<double>(t1-t0) / CLOCKS_PER_SEC)*10;
    std::cout << "Tiempo de ejecucion: " << tiempo << " Segundos\n";
    return 0;
}
