#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int v) {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j) {
        l[i].push_back(j);
    }

    bool cyclic_util(int v, bool visited[], bool *recur_stack) {
        if (!visited[v]) {
            visited[v] = true;
            recur_stack[v] = true;

            list<int>::iterator it;
            for (it = l[v].begin(); it != l[v].end(); it++) {
                if (!visited[*it] and cyclic_util(*it, visited, recur_stack))
                    return true;
                else if (recur_stack[*it])
                    return true;
            }
        }
        recur_stack[v] = false;
        return false;
    }

    bool contains_cycle() {
        bool *visited = new bool[V];
        bool *recur_stack = new bool[V];

        for (int i = 0; i < V; i++) {
            visited[i] = false;
            recur_stack[i] = false;
        }

        for (int i = 0; i < V; i++) {
            if (cyclic_util(i, visited, recur_stack)) return true;
        }
        return false;
    }

};