#include <stdio.h>//Para scanf
#include <cstring>//Para memset
#include <vector>//Para manejar vectores
#include <fstream>//Para manejar archivos
#include <iostream>//Para manejar entrada y salida
#include <ctime>//Para manejar tiempo
using namespace std;

#define MAX 500
vector<pair<int, int>> ady[MAX];  // Lista de adyacencia con pesos
bool visitado[MAX];    // Para nodos visitados
int V;
int path[MAX];         // Para guardar el path recorrido
bool first;

void dfs(int start, int fin, int dist, int& maxDist, vector<int>& tempPath, vector<int>& longestPath) {
    visitado[start] = true;
    tempPath.push_back(start);

    if (start == fin && dist > maxDist) {
        maxDist = dist;
        longestPath = tempPath;
    }

    for (size_t i = 0; i < ady[start].size(); ++i) {
        int v = ady[start][i].first;
        int peso = ady[start][i].second;
        if (!visitado[v]) {
            dfs(v, fin, dist + peso, maxDist, tempPath, longestPath);
        }
    }

    visitado[start] = false;
    tempPath.pop_back();
}

void findLongestPath(int start, int end) {
    int maxDist = 0;
    vector<int> longestPath;
    vector<int> tempPath;

    

    memset(visitado, 0, sizeof(visitado));
    dfs(start, end, 0, maxDist, tempPath, longestPath);

    

    printf("Distancia total de la ruta mas larga: %d\n", maxDist);
    printf("Ruta mas larga: ");
    for (size_t i = 0; i < longestPath.size(); ++i) {
        printf("%d ", longestPath[i]);
        if (i != longestPath.size() - 1) {
            printf("-> ");
        }
    }
    
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return 1;
    }
    ifstream file(argv[1]);
    if (!file.is_open()) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    int E, x, y, peso; 
    string line; 
    getline(file, line); 
    file >> V >> E; // Número de vértices y aristas 
    printf("Numero de vertices: %d\nNumero de aristas: %d\n", V, E); 
    for (int i = 0; i < E; ++i) { 
        file >> x >> y >> peso; // Origen, destino y peso 
        ady[x].push_back(make_pair(y, peso)); 
    } 
    file.close();

    int inicial, final;
    printf("Nodo inicial: ");
    scanf("%d", &inicial);
    printf("Nodo final: ");
    scanf("%d", &final);
    printf("\n");


    clock_t startTime = clock();
    findLongestPath(inicial, final);
    clock_t endTime = clock();
    double executionTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    printf("\n");
    printf("Tiempo total de ejecucion: %.6f segundos\n", executionTime);

    return 0;
}
