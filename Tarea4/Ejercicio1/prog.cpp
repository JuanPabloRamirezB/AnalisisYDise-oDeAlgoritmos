#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

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
    if (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
        q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y)) {
        // std::cout << "Valor4: " << q.x << " " << q.y << std::endl;
        // std::cout << "Valor5: " << p.x << " " << p.y << std::endl;
        // std::cout << "Valor6: " << r.x << " " << r.y << std::endl;
        return true;
    }
    // std::cout << "Valor4: " << q.x << " " << q.y << std::endl;
    // std::cout << "Valor5: " << p.x << " " << p.y << std::endl;
    // std::cout << "Valor6: " << r.x << " " << r.y << std::endl;
    return false;
}

// Función para verificar si dos segmentos se intersectan
bool seIntersectan(Segmento s1, Segmento s2, Punto& interseccion) {
    Punto p1 = s1.p1, q1 = s1.p2, p2 = s2.p1, q2 = s2.p2;

    int o1 = orientacion(p1, q1, p2);
    int o2 = orientacion(p1, q1, q2);
    int o3 = orientacion(p2, q2, p1);
    int o4 = orientacion(p2, q2, q1);

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
    return false;

}   

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <archivo_entrada>" << std::endl;
        return 1;
    }

    std::ifstream archivoEntrada(argv[1]);
    if (!archivoEntrada) {
        std::cerr << "No se pudo abrir el archivo de entrada." << std::endl;
        return 1;
    }

    int n;
    archivoEntrada >> n;
    std::vector<Segmento> segmentos(n);

    for (int i = 0; i < n; ++i) {
        archivoEntrada >> segmentos[i].p1.x >> segmentos[i].p1.y
                       >> segmentos[i].p2.x >> segmentos[i].p2.y;
        // printf("x1: %d, y1: %d\n", segmentos[i].p1.x, segmentos[i].p1.y);
        // printf("x2: %d, y2: %d\n", segmentos[i].p2.x, segmentos[i].p2.y);
    }

    archivoEntrada.close();

    std::vector<Punto> intersecciones;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Punto interseccion;
            if (seIntersectan(segmentos[i], segmentos[j], interseccion)) {
                // Añadir la intersección ficticia (0,0) solo para ilustrar
                intersecciones.push_back(interseccion);
                
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
        } 
    archivoSalida.close();

    return 0;
}
