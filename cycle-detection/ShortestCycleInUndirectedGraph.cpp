#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int bfs_helper(int n, vector<vector<int> > &graph) {
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        vector<int> dist(n + 1, (int)1e9);
        vector<int> parent(n + 1, -1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int nbr : graph[x]) {
                if (dist[nbr] == (int)1e9) {
                    dist[nbr] = dist[x] + 1;
                    parent[nbr] = x;
                    q.push(nbr);
                } else if (parent[x] != nbr and parent[nbr] != x) {
                    ans = min(ans, dist[x] + dist[nbr] + 1);
                }
            }
        }
    }
    if (ans == INT_MAX) return -1;
    
    return ans;
}

int solve(int n, vector<vector<int> > edges) {
    vector<vector<int> > graph(n + 1, vector<int>());
    for (int i = 0; i < edges.size(); i++) {
        int x = edges[i][0], y = edges[i][1];
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    return bfs_helper(n, graph);

}