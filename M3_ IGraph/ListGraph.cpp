#include "ListGraph.h"

ListGraph::ListGraph(int size) : adjacencyLists(size) {}

ListGraph::ListGraph(const IGraph& graph) 
{
    int size = graph.VerticesCount();
    adjacencyLists.resize(size);
    for (int i = 0; i < size; ++i) {
        adjacencyLists[i] = graph.GetNextVertices(i);
    }
}

ListGraph::~ListGraph() {}

void ListGraph::AddEdge(int from, int to) 
{
    if (from >= 0 && from < adjacencyLists.size()) {
        if (to >= 0 && to < adjacencyLists.size()) {
            adjacencyLists[from].push_back(to);
        }
    }
}

int ListGraph::VerticesCount() const 
{
    return static_cast<int>(adjacencyLists.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const 
{
    if (vertex >= 0 && vertex < adjacencyLists.size()) {
        return adjacencyLists[vertex];
    }
    return {};
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const 
{
    std::vector<int> prevVertices;

    if (vertex < 0 || vertex >= adjacencyLists.size()) {
        return prevVertices;
    }

    for (int from = 0; from < adjacencyLists.size(); ++from) {
        for (int to : adjacencyLists[from]) {
            if (to == vertex) {
                prevVertices.push_back(from);
            }
        }
    }

    return prevVertices;
}
