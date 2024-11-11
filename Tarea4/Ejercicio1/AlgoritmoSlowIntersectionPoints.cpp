#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

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
    Punto p1 = s1.p1, q1 = s1.p2, p2 = s2.p1, q2 = s2.p2;

    int o1 = orientacion(p1, q1, p2);
    int o2 = orientacion(p1, q1, q2);
    int o3 = orientacion(p2, q2, p1);
    int o4 = orientacion(p2, q2, q1);
    cout << "Valor2: " << o1 << " " << o2 << " " << o3 << " " << o4 << endl;

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && enSegmento(p1, p2, q1)) return true;
    if (o2 == 0 && enSegmento(p1, q2, q1)) return true;
    if (o3 == 0 && enSegmento(p2, p1, q2)) return true;
    if (o4 == 0 && enSegmento(p2, q1, q2)) return true;

    return false;
}

int main(int argc, char* argv[]) {
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

    return 0;
}
