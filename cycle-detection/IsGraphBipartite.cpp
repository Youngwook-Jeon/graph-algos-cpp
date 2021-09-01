// 주어진 그래프가 Bipartite 인지 여부를 체크하기
// 단 그래프가 반드시 connected 라는 보장이 없음
#include <iostream>
#include <vector>
using namespace std;

bool dfs_helper(int node, vector<vector<int> > &graph, int *visited, int parent, int color) {
    visited[node] = color;
    for (auto next : graph[node]) {
        if (visited[next] == 0) {
            bool res = dfs_helper(next, graph, visited, node, 3 - color);
            if (res == false) return false;
        } else if (next != parent and visited[next] == visited[node]) {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int> > graph){
    int N = graph.size();
    int visited[N];
    memset(visited, 0, sizeof(visited));

    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            flag= dfs_helper(i, graph, visited, -1, 1);
            if (!flag) return flag;
        }
    }
    return flag;
}