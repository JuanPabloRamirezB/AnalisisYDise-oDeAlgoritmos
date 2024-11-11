#include "Graph.h"

Graph::Graph() {
  adjList.clear();
  numNodes = 0;
  numEdges = 0;
  representa = 0;
  directedGraph = 0;
  weightedGraph = 0;
} 

Graph::~Graph() {
  adjList.clear();
  numNodes = 0;
  numEdges = 0;
  representa = 0;
  directedGraph = 0;
  weightedGraph = 0;
} 

void Graph::split(std::string line, std::vector<int> &res){
  size_t strPos = line.find(" ");
  size_t lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos + 1;
    strPos = line.find(" ", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void Graph::loadGraphList(std::istream &input) {
  std::string line;
  int i = 0;
  while (std::getline(input, line)) {
    if (i == 0) { // Ignora comentario
      i++;
      continue;
    }
    if (i == 1) {
      std::vector<int> result;
      split(line, result);
      numNodes = result[0];
      numEdges = result[1];
      // Reservar memoria para renglones
      adjList.resize(numNodes);
      // Declara lista vacia para cada renglon
      for (int k = 0; k < numNodes; k++) {
        std::list<std::pair<int, int>> tmpList;
        adjList[k] = tmpList;
      }
      i++;
      continue;
    }
    std::vector<int> result;
    split(line, result);
    int u = result[0] - 1; // nodos cero basados
    int v = result[1] - 1;
    // Si el grafo es ponderado se lee tambien el peso
    // grafo no ponderado entonces aristas con peso 1
    int w = weightedGraph == 1 ? result[2] : 1;
    // defino arista (u,v) con peso w
    adjList[u].push_back(std::make_pair(v, w));
    // Si el grafo es no dirigido agrego tambien arista (v,u) con peso w
    if (directedGraph == 0) 
      adjList[v].push_back(std::make_pair(u, w)); 
    i++;
  }
}

void Graph::loadGraphMatrix(std::istream &input) {
  std::string line;
  int i = 0;
  while (std::getline(input, line)) {
    if (i == 0) { // Ignora comentario
      i++;
      continue;
    }
    if (i == 1) {
      std::vector<int> result;
      split(line, result);
      numNodes = result[0];
      numEdges = result[1];
      // Reservar memoria para renglones y columnas
      adjMatrix.resize(numNodes, std::vector<int>(numNodes, 0));
      i++;
      continue;
    }
    std::vector<int> result;
    split(line, result);
    int u = result[0] - 1; // convierte nodos cero basados
    int v = result[1] - 1;
    // Si el grafo es ponderado se lee tambien el peso
    // grafo no ponderado entonces aristas con peso 1
    int w = weightedGraph == 1 ? result[2] : 1;
    // defino arista (u,v) con peso w
    adjMatrix[u][v] = w;
    // Si el grafo es no dirigido agrego tambien arista (v,u) con peso w
    if (directedGraph == 0) 
      adjMatrix[v][u] = w;
    i++;
  }
}
void Graph::readGraph(std::istream &input, int _representation, int _directed, int _weighted) {
  representa = _representation;
  directedGraph = _directed;
  weightedGraph = _weighted;
  // Matriz de adyacencia
  if (representa == 1)
    loadGraphMatrix(input);
  else // Lista de adyacencia
    loadGraphList(input);
}

void Graph::printAdjList() {
  std::cout << "numNodes: " << numNodes << std::endl;
  std::cout << "numEdges: " << numEdges << std::endl;
  std::cout << "Adjacency List" << std::endl;
  for (int nodeU = 0; nodeU < numNodes; nodeU++) {
    std::cout << "vertex " << nodeU + 1 << ": "; // convierte nodo a uno-basado
    std::list<std::pair<int, int>> g = adjList[nodeU];
    std::list<std::pair<int, int>>::iterator it;
    for (it = g.begin(); it != g.end(); ++it) {
      std::pair<int, int> par = *it;
      // convierte nodo a uno-basado
      std::cout << "{" << par.first + 1 << "," << par.second << "}" << " ";
    }
    std::cout << std::endl;
  }
}

void Graph::printAdjMatrix() {
  std::cout << "numNodes: " << numNodes << std::endl;
  std::cout << "numEdges: " << numEdges << std::endl;
  std::cout << "Adjacency Matrix" << std::endl;
  for (int nodeU = 0; nodeU < numNodes; nodeU++) {
    std::cout << "vertex " << nodeU + 1 << ": ";
    for (int nodeV = 0; nodeV < numNodes; nodeV++) {
      if (adjMatrix[nodeU][nodeV] > 0)
        std::cout << adjMatrix[nodeU][nodeV] << " ";
      else 
        std::cout << 0 << " ";
    }
    std::cout << std::endl;
  }
}

void Graph::print() {
  if (representa == 1)
    printAdjMatrix();
  else
    printAdjList();
}