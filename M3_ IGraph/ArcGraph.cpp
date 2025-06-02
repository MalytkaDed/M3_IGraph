#include "ArcGraph.h"

ArcGraph::ArcGraph(int size) : verticesCount(size) {}

ArcGraph::ArcGraph(const IGraph& graph)
{
    verticesCount = graph.VerticesCount();

    for (int from = 0; from < verticesCount; ++from) {
        for (int to : graph.GetNextVertices(from)) {
            edges.push_back({ from, to });
        }
    }
}

ArcGraph::~ArcGraph() {}

void ArcGraph::AddEdge(int from, int to)
{
    if (from >= 0 && from < verticesCount) {
        if (to >= 0 && to < verticesCount) {
            edges.push_back({ from, to });
        }
    }
}

int ArcGraph::VerticesCount() const
{
    return verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const
{
    std::vector<int> nextVertices;

    if (vertex < 0 || vertex >= verticesCount) {
        return nextVertices;
    }

    for (const Edge& edge : edges) {
        if (edge.from == vertex) {
            nextVertices.push_back(edge.to);
        }
    }

    return nextVertices;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const
{
    std::vector<int> prevVertices;

    if (vertex < 0 || vertex >= verticesCount) {
        return prevVertices;
    }

    for (const Edge& edge : edges) {
        if (edge.to == vertex) {
            prevVertices.push_back(edge.from);
        }
    }

    return prevVertices;
}
