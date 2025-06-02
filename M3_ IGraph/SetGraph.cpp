#include "SetGraph.h"

SetGraph::SetGraph(int size) : adjacencySets(size) {}

SetGraph::SetGraph(const IGraph& graph)
{
    int size = graph.VerticesCount();
    adjacencySets.resize(size);

    for (int from = 0; from < size; ++from) {
        for (int to : graph.GetNextVertices(from)) {
            adjacencySets[from].insert(to);
        }
    }
}

SetGraph::~SetGraph() {}

void SetGraph::AddEdge(int from, int to)
{
    if (from >= 0 && from < adjacencySets.size()) {
        if (to >= 0 && to < adjacencySets.size()) {
            adjacencySets[from].insert(to);
        }
    }
}

int SetGraph::VerticesCount() const
{
    return static_cast<int>(adjacencySets.size());
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const
{
    std::vector<int> nextVertices;

    if (vertex < 0 || vertex >= adjacencySets.size()) {
        return nextVertices;
    }

    for (int to : adjacencySets[vertex]) {
        nextVertices.push_back(to);
    }

    return nextVertices;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> prevVertices;

    if (vertex < 0 || vertex >= adjacencySets.size()) {
        return prevVertices;
    }

    for (int from = 0; from < adjacencySets.size(); ++from) {
        if (adjacencySets[from].find(vertex) != adjacencySets[from].end()) {
            prevVertices.push_back(from);
        }
    }

    return prevVertices;
}
