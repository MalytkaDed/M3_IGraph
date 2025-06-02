// Модуль 3 Задача 1. «Представление графа»

#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "GraphAlgorithms.h"


int main(int argc, const char* argv[]) {
    //ListGraph listGraph(7);
    //listGraph.AddEdge(0, 1);
    //listGraph.AddEdge(0, 5);
    //listGraph.AddEdge(1, 2);
    //listGraph.AddEdge(1, 3);
    //listGraph.AddEdge(1, 5);
    //listGraph.AddEdge(1, 6);
    //listGraph.AddEdge(3, 2);
    //listGraph.AddEdge(3, 4);
    //listGraph.AddEdge(3, 6);
    //listGraph.AddEdge(5, 4);
    //listGraph.AddEdge(5, 6);
    //listGraph.AddEdge(6, 4);

    ListGraph listGraph(6);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(2, 3);
    listGraph.AddEdge(3, 1);
    listGraph.AddEdge(3, 4);

    mainBFS(listGraph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(listGraph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;

    MatrixGraph matrixGraph(listGraph);

    mainBFS(listGraph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;
    mainDFS(listGraph, [](int vertex) { std::cout << vertex << " "; });
    std::cout << std::endl;

    // ArcGraph arcGraph(matrixGraph);
    // SetGraph setGraph(arcGraph);
    return 0;
}

