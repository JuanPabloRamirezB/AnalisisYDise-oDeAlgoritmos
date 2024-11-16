#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <sstream>
#include <list>
#include <string>
#include <utility>
#include <vector>

class Graph {
private:
  int numNodes;
  int numEdges;
  int representa;    // 1: Matriz; 0: Lista
  int directedGraph; // 1: dirigido; 0: no dirigido
  int weightedGraph; // 1: ponderado; 0: no ponderado
  // Matriz de adyacencia
  std::vector<std::vector<int>> adjMatrix;
  // Lista de adyacencia
  std::vector<std::list<std::pair<int, int>>> adjList;

  void split(std::string line, std::vector<int> &res);
  void loadGraphList(std::istream &input);
  void loadGraphMatrix(std::istream &input);
  void printAdjList();
  void printAdjMatrix();

public:
  Graph();
  ~Graph();
  void readGraph(std::istream &input, int _representa, int _directed, int _weighted);
  void print();
};

#endif // _GRAPH_H_