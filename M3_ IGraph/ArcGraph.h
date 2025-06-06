#ifndef ARCGRAPH_H
#define ARCGRAPH_H

#include "IGraph.h"
#include <vector>

struct Edge {
    int from;
    int to;

    Edge(int f, int t) : from(f), to(t) {}
};

// реализация графа в виде массива пар
struct ArcGraph : public IGraph
{
public:
    ArcGraph(int size);
    ArcGraph(const IGraph& graph);
    ~ArcGraph();

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int verticesCount;
    std::vector<Edge> edges;
};

#endif // ARCGRAPH_H
