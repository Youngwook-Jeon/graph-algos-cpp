#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool ans = false;

void dfs(vector<vector<char> > &grid, int visited[][501], int dist[][501], int x, int y, int m, int n, int len, int prev_dist, char ch) {
    if (x < 0 or y < 0 or x >= m or y >= n or grid[x][y] != ch) {
        return;
    }
    if (visited[x][y]) {
        if (abs(dist[x][y] - prev_dist) >= 3) {
            ans = true;
        }
        return;
    }
    visited[x][y] = 1;
    dist[x][y] = len;
    for (int i = 0; i < 4; i++) {
        dfs(grid, visited, dist, x + dx[i], y + dy[i], m, n, len + 1, dist[x][y], ch);
    }
}

bool containsCycle(vector<vector<char> > grid) {
    int m = grid.size(), n = grid[0].size();
    int visited[501][501], dist[501][501];
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    ans = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0) {
                dfs(grid, visited, dist, i, j, m, n, 1, 1, grid[i][j]);
            }
        }
    }
    return ans;
}