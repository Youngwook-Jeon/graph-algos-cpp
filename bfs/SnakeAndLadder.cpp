// leetcode: 909
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *l;

public:
    Graph(int v) {
        V = v;
        l = new list<int>[V + 1];
    }

    void addEdge(int i, int j) {
        l[i].push_back(j);
    }

    int minCostBFS(int source, int dest) {
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *dist = new int[V]{0};

        q.push(source);
        visited[source] = true;
        dist[source] = 0;

        while (!q.empty()) {
            int f = q.front();
            q.pop();

            for (auto nbr : l[f]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    dist[nbr] = dist[f] + 1;
                    visited[nbr] = true;
                }
            }
        }
        return dist[dest];
    }
};

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    vector<int> board(n + 1, 0);

    for (auto sp : snakes) {
        int s = sp.first;
        int e = sp.second;
        board[s] = e - s;
    }

    for (auto lp : ladders) {
        int s = lp.first;
        int e = lp.second;
        board[s] = e - s;
    }

    Graph g(n + 1);
    for (int u = 1; u < n; u++) {
        for (int dice = 1; dice <= 6; dice++) {
            int v = u + dice;
            v += board[v];
            if (v <= n) {
                g.addEdge(u, v);
            }
        }
    }
    return g.minCostBFS(1, n);

}