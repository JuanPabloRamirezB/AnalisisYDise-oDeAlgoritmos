#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <ctime>
//using namespace std;

#define MAX 500
std::vector<std::pair<int, int>> ady[MAX];  // Lista de adyacencia
//std::vector<int> ady[MAX];                  // Lista de adyacencia
int V, E;                                   // Número de vértices y aristas

bool isBipartite(int i) {
    std::vector<int> color(V + 1, -1); // Inicializamos el color de todos los vértices a -1
    std::queue<int> q;
    //printf("src: %d\n", i);

    color[i] = 1; // Asignamos el primer color al vértice fuente
    q.push(i);

    while (!q.empty()) {
        int u = q.front();
        //printf("u: %d\n", u);
        q.pop();

        for (auto& vecino : ady[u]) {
            int v = vecino.first;
            //printf("v: %d\n", v);
            //printf("color[v]: %d\n", color[v]);
            //printf("color[u]: %d\n", color[u]);
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
        //printf("Paso: %d\n", i);
        if (ady[i].size() > 0) { // Solo comprobamos los vértices que tienen aristas
            if (!isBipartite(i)) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Uso: " << argv[0] << " <nombre_archivo> <1 ponderado||2 no ponderado>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return 1;
    }

    int peso = *argv[2];
    //printf("Peso: %d\n", peso);
    std::string line;
    getline(file, line);
    printf("%s\n", line.c_str());
    // Leer el número de vértices y aristas
    file >> V >> E;
    printf("Numero de vertices: %d\nNumero de aristas: %d\n", V, E);
    int u, v, w = 1;
    for (int i = 0; i < E; ++i) {
        if(peso == 49)
            file >> u >> v >> w;
        if(peso == 50)
            file >> u >> v;

        //printf("u: %d, v: %d\n", u, v);
        ady[u].emplace_back(v, w); // Grafo dirigido
        //ady[v].emplace_back(u,w); // Grafo no dirigido

        //ady[u].push_back(std::make_pair(v, w)); 
    }
    file.close();

    clock_t start = clock();
    bool bipartite = checkBipartite();
    clock_t end = clock();
    //printf("%d\n",bipartite);
    double executionTime = double(end - start) / CLOCKS_PER_SEC;
    std::cout << (bipartite ? "\nBipartita\n" : "\nNo bipartita\n") << std::endl;
    printf("Tiempo total de ejecucion: %.6f segundos\n", executionTime);

    return 0;
}
