#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <ctime>
using namespace std;

#define MAX 500
vector<int> ady[MAX];  // Lista de adyacencia
int V, E;              // Número de vértices y aristas

bool isBipartite(int src) {
    vector<int> color(V + 1, -1); // Inicializamos el color de todos los vértices a -1
    queue<int> q;

    color[src] = 1; // Asignamos el primer color al vértice fuente
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : ady[u]) {
            // Si el vértice adyacente no ha sido coloreado, le asignamos un color opuesto
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } 
            // Si el vértice adyacente tiene el mismo color, el grafo no es bipartito
            else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

bool checkBipartite() {
    for (int i = 1; i <= V; ++i) {
        if (ady[i].size() > 0) { // Solo comprobamos los vértices que tienen aristas
            if (!isBipartite(i)) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <nombre_archivo>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }

    // Leer el número de vértices y aristas
    file >> V >> E;
    int u, v;
    for (int i = 0; i < E; ++i) {
        file >> u >> v;
        ady[u].push_back(v);
        ady[v].push_back(u); // Grafo no dirigido
    }
    file.close();

    clock_t start = clock();
    bool bipartite = checkBipartite();
    clock_t end = clock();

    double executionTime = double(end - start) / CLOCKS_PER_SEC;
    cout << (bipartite ? "Bipartita" : "No bipartita") << endl;
    printf("Tiempo total de ejecucion: %.6f segundos\n", executionTime);

    return 0;
}
