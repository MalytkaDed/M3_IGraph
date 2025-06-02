#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include "IGraph.h"
#include <vector>
#include <functional>

void BFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void(int)>& func);
void mainBFS(const IGraph& graph, const std::function<void(int)>& func);

void DFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void(int)>& func);
void mainDFS(const IGraph& graph, const std::function<void(int)>& func);

#endif // GRAPH_ALGORITHMS_H