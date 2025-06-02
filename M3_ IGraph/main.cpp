// Модуль 3 Задача 1. «Представление графа»

#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"
#include "GraphAlgorithms.h"


void printGraph(const IGraph& graph) {
     std::cout << "BFS: ";
    mainBFS(graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;

    std::cout << "DFS: ";
    mainDFS(graph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;

    std::cout << std::endl;
}

int main() {

    ListGraph listGraph(6);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 4);
    listGraph.AddEdge(3, 5);

    // Печать обходов для ListGraph
    std::cout << "   " << "ListGraph" << std::endl;
    printGraph(listGraph);

    // Копирование в другие представления и печать
    MatrixGraph matrixGraph(listGraph);
    std::cout << "   " << "MatrixGraph" << std::endl;
    printGraph(matrixGraph);

    ArcGraph arcGraph(matrixGraph);
    std::cout << "   " << "ArcGraph" << std::endl;
    printGraph(arcGraph);

    SetGraph setGraph(matrixGraph);
    std::cout << "   " << "SetGraph" << std::endl;
    printGraph(setGraph);

    return 0;
}

