#include <iostream>
#include <vector>
using namespace std;

bool dfs_helper(vector<int> graph[], int node, int *visited, int parent, int color) {
    visited[node] = color; // 0, 1, or 2
    for (auto nbr : graph[node]) {
        if (visited[nbr] == 0) {
            bool subprob = dfs_helper(graph, nbr, visited, node, 3 - color);
            if (subprob == false) {
                return false;
            }
        } else if (nbr != parent and color == visited[nbr]) {
            return false;
        }
    }
    return true;
}

bool dfs(vector<int> graph[], int N) {
    int visited[N];
    memset(visited, 0, sizeof(visited));
    int color = 1;
    bool ans = dfs_helper(graph, 0, visited, -1, color);

    for (int i = 0; i < N; i++) {
        cout << i << " - Color " << visited[i] << endl;
    }
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> graph[N];
    while (M--) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // BFS or DFS, by coloring the nodes at each step (current node has color 1, nbr should have a color 2)
    if (dfs(graph, N)) {
        cout << "It is a Bipartite graph";
    } else {
        cout << "Not Bipartite";
    }
    return 0;
}