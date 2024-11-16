#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
<<<<<<< HEAD
#include <ctime>
=======
using namespace std;
>>>>>>> 32dc1c0bc0970a5c9f44fb8c70f0072ad9f5614e

// Estructura para almacenar puntos en el plano
struct Punto {
    int x, y;
};

// Estructura para almacenar segmentos de línea
struct Segmento {
    Punto p1, p2;
};

// Función para determinar la orientación de tres puntos (p, q, r)
int orientacion(Punto p, Punto q, Punto r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // colineal
    return (val > 0) ? 1 : 2; // horario o antihorario
}

// Función para verificar si q está en el segmento pr
bool enSegmento(Punto p, Punto q, Punto r) {
<<<<<<< HEAD
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y)) {
        return true;
    }
    return false;
}

// Función para verificar si dos segmentos se intersectan y encontrar el punto de intersección
bool seIntersectan(Segmento s1, Segmento s2, Punto& interseccion) {
=======
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)){
        cout << "Valor4: " << q.x << " " << q.y << endl;
        cout << "Valor5: " << p.x << " " << p.y << endl;
        cout << "Valor6: " << r.x << " " << r.y << endl;
        return true;}
    cout << "Valor4: " << q.x << " " << q.y << endl;
    cout << "Valor5: " << p.x << " " << p.y << endl;
    cout << "Valor6: " << r.x << " " << r.y << endl;
    return false;
}

// Función para verificar si dos segmentos se intersectan
bool seIntersectan(Segmento s1, Segmento s2) {
>>>>>>> 32dc1c0bc0970a5c9f44fb8c70f0072ad9f5614e
    Punto p1 = s1.p1, q1 = s1.p2, p2 = s2.p1, q2 = s2.p2;

    int o1 = orientacion(p1, q1, p2);
    int o2 = orientacion(p1, q1, q2);
    int o3 = orientacion(p2, q2, p1);
    int o4 = orientacion(p2, q2, q1);
<<<<<<< HEAD

    if (o1 != o2 && o3 != o4) {
        // Encuentra el punto de intersección real (esto es una simplificación)
        int a1 = q1.y - p1.y;
        int b1 = p1.x - q1.x;
        int c1 = a1 * p1.x + b1 * p1.y;
        
        int a2 = q2.y - p2.y;
        int b2 = p2.x - q2.x;
        int c2 = a2 * p2.x + b2 * p2.y;

        int det = a1 * b2 - a2 * b1;
        if (det == 0) {
            interseccion = {0, 0}; // líneas colineales
        } else {
            interseccion.x = (b2 * c1 - b1 * c2) / det;
            interseccion.y = (a1 * c2 - a2 * c1) / det;
        }
        return true;
    }
    if (o1 == 0 && enSegmento(p1, p2, q1)) {
        interseccion = p2;
        return true;
    }
    if (o2 == 0 && enSegmento(p1, q2, q1)) {
        interseccion = q2;
        return true;
    }
    if (o3 == 0 && enSegmento(p2, p1, q2)) {
        interseccion = p1;
        return true;
    }
    if (o4 == 0 && enSegmento(p2, q1, q2)) {
        interseccion = q1;
        return true;
    }
=======
    cout << "Valor2: " << o1 << " " << o2 << " " << o3 << " " << o4 << endl;

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && enSegmento(p1, p2, q1)) return true;
    if (o2 == 0 && enSegmento(p1, q2, q1)) return true;
    if (o3 == 0 && enSegmento(p2, p1, q2)) return true;
    if (o4 == 0 && enSegmento(p2, q1, q2)) return true;
>>>>>>> 32dc1c0bc0970a5c9f44fb8c70f0072ad9f5614e

    return false;
}

int main(int argc, char* argv[]) {
<<<<<<< HEAD

    clock_t startTime = clock();

    // if (argc != 2) {
    //     std::cerr << "Uso: " << argv[0] << " <archivo_entrada>" << std::endl;
    //     return 1;
    // }

    // std::ifstream archivoEntrada(argv[1]);
    // if (!archivoEntrada) {
    //     std::cerr << "No se pudo abrir el archivo de entrada." << std::endl;
    //     return 1;
    // }

    int n;
    std::cin >> n;
    std::vector<Segmento> segmentos(n);

    for (int i = 0; i < n; ++i) {
        // archivoEntrada >> segmentos[i].p1.x >> segmentos[i].p1.y
        //                >> segmentos[i].p2.x >> segmentos[i].p2.y;
        std::cin >> segmentos[i].p1.x >> segmentos[i].p1.y
                 >> segmentos[i].p2.x >> segmentos[i].p2.y;
    }
    

    //archivoEntrada.close();

    
    std::vector<Punto> intersecciones;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Punto interseccion;
            if (seIntersectan(segmentos[i], segmentos[j], interseccion)) {
                intersecciones.push_back(interseccion);

                //std::cout << i << " " << j << " " << interseccion.x << " " << interseccion.y << std::endl;
            }
        }
    }
    
    
    std::ofstream archivoSalida("resultado.txt");
    if (!archivoSalida) {
        std::cerr << "No se pudo abrir el archivo de salida." << std::endl;
        return 1;
    }

    archivoSalida << intersecciones.size() << std::endl;

    for (const auto& interseccion : intersecciones) {
        archivoSalida << interseccion.x << " " << interseccion.y << std::endl;
        //printf("%d %d\n", interseccion.x, interseccion.y);
    }
    archivoSalida.close();

    clock_t endTime = clock();
    double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;
    //std::cout << executionTime<<"\n"<< std::endl;
    printf("%.6f\n", executionTime);


=======
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <archivo_entrada>" << endl;
        return 1;
    }

    ifstream archivoEntrada(argv[1]);
    if (!archivoEntrada) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }
    
    int n;
    archivoEntrada >> n;
    vector<Segmento> segmentos(n);

    for (int i = 0; i < n; ++i) {
        archivoEntrada >> segmentos[i].p1.x >> segmentos[i].p1.y
                       >> segmentos[i].p2.x >> segmentos[i].p2.y;
        printf("x1: %d, y1: %d\n", segmentos[i].p1.x, segmentos[i].p1.y);
        printf("x2: %d, y2: %d\n", segmentos[i].p2.x, segmentos[i].p2.y);
    }

    archivoEntrada.close();

    vector<pair<int, int>> intersecciones;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cout << "Valor1: " << seIntersectan(segmentos[i], segmentos[j]) << endl;
            if (seIntersectan(segmentos[i], segmentos[j])) {
                // Añadir la intersección ficticia (0,0) solo para ilustrar
                intersecciones.emplace_back(0, 0);
                //cout << "Valor3: " << intersecciones[j].first << " " << intersecciones[j].second << endl;
            }
            //printf("%d\n",intersecciones.size());
        }
    }
    // for (const auto& interseccion : intersecciones) { 
    //     cout << "(" << interseccion.first << ", " << interseccion.second << ")" << endl; 
    //     }

    ofstream archivoSalida("resultado.txt");
    if (!archivoSalida) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    archivoSalida << intersecciones.size() << endl;
    for (const auto& interseccion : intersecciones) {
        archivoSalida << interseccion.first << " " << interseccion.second << endl;
    }

    archivoSalida.close();

>>>>>>> 32dc1c0bc0970a5c9f44fb8c70f0072ad9f5614e
    return 0;
}
