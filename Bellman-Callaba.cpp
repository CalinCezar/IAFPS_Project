#include <iostream>
#include <vector>
#include <list>
#include <climits>

void printSolution(const std::vector<int>& distance, const std::vector<int>& parent, int src, int dest, std::list<int>& l)
{
    if (dest == -1) 
    {
        std::cout << "There is no path from " << src << " to " << dest << std::endl;
        return;
    }

    for (int at = dest; at != -1; at = parent[at]) 
    {
        l.push_front(at);
    }
}
/// BELLMAN CALLABA MINIMUM
std::list<int> bellmanCallabaMin(std::vector<std::vector<int>> graph, int V, int src, int dest) 
{
    std::vector<int> distance(V, INT_MAX);
    std::vector<int> parent(V, -1);

    distance[src] = 0;

    for (int i = 0; i < V - 1; ++i) 
    {
        for (int u = 0; u < V; ++u)
        {
            for (int v = 0; v < V; ++v)
            {
                if (graph[u][v] != 0 && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v]) 
                {
                    distance[v] = distance[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < V; ++u)
    {
        for (int v = 0; v < V; ++v)
        {
            if (graph[u][v] != 0 && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
            {
                std::cout << "The graph contains a negative cycle!" << std::endl;
                return std::list<int>(); 
            }
        }
    }

    std::list<int> l;
    printSolution(distance, parent, src, dest, l);
    return l;
}
///BELMAN CALLABA MAXIMUM
std::list<int> bellmanCallabaMax(std::vector<std::vector<int>> graph, int V, int src, int dest)
{
    std::vector<int> distance(V, INT_MIN);
    std::vector<int> parent(V, -1);

    distance[src] = 0;

    for (int i = 0; i < V - 1; ++i)
    {
        for (int u = 0; u < V; ++u) 
        {
            for (int v = 0; v < V; ++v)
            {
                if (graph[u][v] != 0 && distance[u] != INT_MIN && distance[u] + graph[u][v] > distance[v])
                {
                    distance[v] = distance[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < V; ++u)
    {
        for (int v = 0; v < V; ++v) 
        {
            if (graph[u][v] != 0 && distance[u] != INT_MIN && distance[u] + graph[u][v] > distance[v]) 
            {
                std::cout << "The graph contains a negative cycle!" << std::endl;
                return std::list<int>();  
            }
        }
    }

    std::list<int> l;
    printSolution(distance, parent, src, dest, l);
    return l;
}

bool hamiltonianPathUtil(const std::vector<std::vector<int>>& graph, std::list<int>& path, std::vector<bool>& visited, int node) 
{    
    visited[node] = true;
    path.push_back(node);
    if (path.size() == graph.size()) return true;


    for (int i = 0; i < graph.size(); i++)
    {      
        if (visited[i] == false && graph[node][i])
        {
            if (hamiltonianPathUtil(graph, path, visited, i)) return true;
        }
            
    }

    visited[node] = false;
    path.pop_back();

    return false;
}

std::list<int> hamiltonianPath(const std::vector<std::vector<int>>& graph) {
    std::list<int> path;
    std::vector<bool> visited(graph.size(),0);
   
    for (int i = 0; i < graph.size(); i++)
    {
        if (hamiltonianPathUtil(graph, path, visited, i))
        {
            break;
        }
    }

    std::cout << "list: ";
    for (auto i : path)
    {
        std::cout << i << " ";
    }

    return path;
}



