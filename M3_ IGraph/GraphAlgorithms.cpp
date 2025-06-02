#include "GraphAlgorithms.h"
#include <queue>

void BFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void(int)>& func) {
    std::queue<int> q;
    q.push(vertex);
    visited[vertex] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        func(current);

        for (int next : graph.GetNextVertices(current)) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

void mainBFS(const IGraph& graph, const std::function<void(int)>& func) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            BFS(graph, i, visited, func);
        }
    }
}

void DFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void(int)>& func) {
    visited[vertex] = true;
    func(vertex);

    for (int next : graph.GetNextVertices(vertex)) {
        if (!visited[next]) {
            DFS(graph, next, visited, func);
        }
    }
}

void mainDFS(const IGraph& graph, const std::function<void(int)>& func) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            DFS(graph, i, visited, func);
        }
    }
}
