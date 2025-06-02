#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int size) : matrix(size, std::vector<bool>(size, false)) {}

MatrixGraph::MatrixGraph(const IGraph& graph)
{
    int size = graph.VerticesCount();
    matrix.resize(size, std::vector<bool>(size, false));

    for (int i = 0; i < size; ++i) {
        for (int j : graph.GetNextVertices(i)) {
            matrix[i][j] = true;
        }
    }
}

MatrixGraph::~MatrixGraph() {}

void MatrixGraph::AddEdge(int from, int to)
{
    if (from >= 0 && from < matrix.size()) {
        if (to >= 0 && to < matrix.size()) {
            matrix[from][to] = true;
        }
    }
}

int MatrixGraph::VerticesCount() const
{
    return static_cast<int>(matrix.size());
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> prevVertices;

    if (vertex < 0 || vertex >= matrix.size()) {
        return prevVertices;
    }

    for (int from = 0; from < matrix.size(); ++from) {
        if (matrix[from][vertex] == true) {
            prevVertices.push_back(from);
        }
    }

    return prevVertices;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const
{
    std::vector<int> nextVertices;

    if (vertex < 0 || vertex >= matrix.size()) {
        return nextVertices;
    }

    for (int to = 0; to < matrix.size(); ++to) {
        if (matrix[vertex][to] == true) {
            nextVertices.push_back(to);
        }
    }

    return nextVertices;
}