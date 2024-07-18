#ifndef GRAPHALGORITHMS_HPP
#define GRAPHALGORITHMS_HPP

#include <iostream>
#include <climits>
#include <vector>
#include <list>

void printSolution(const std::vector<int>& distance, const std::vector<int>& parent, int src, int dest, std::list<int>& l);
std::list<int> bellmanCallabaMin(std::vector<std::vector<int>> graph, int V, int src, int dest);
std::list<int> bellmanCallabaMax(std::vector<std::vector<int>> graph, int V, int src, int dest);

bool isSafe(int v, const std::vector<std::vector<int>>& graph, std::vector<int>& path, int pos);
bool hamiltonianPathUtil(const std::vector<std::vector<int>>& graph, std::vector<int>& path, std::vector<int>& result, int pos);
std::list<int> hamiltonianPath(const std::vector<std::vector<int>>& graph);
#endif // !GRAPHALGORITHMS_HPP
