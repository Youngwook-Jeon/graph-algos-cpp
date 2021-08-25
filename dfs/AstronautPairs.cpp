// 같은 국가에서 온 비행사들의 쌍의 배열이 주어졌을 때, 서로 다른 국가에서 온 비행사들의 쌍들로 만들 수 있는 경우의 수 출력
#include <iostream>
#include <vector>
using namespace std;

int dfs(int v, vector<bool> &visited, vector<vector<int> > &graph) {
    if (visited[v] == true) return 0;
    int val = 1;
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); i++) {
        val += dfs(graph[v][i], visited, graph);
    }
    return val;
}

int count_pairs(int N, vector<pair<int,int> > astronauts){
    vector<vector<int> > graph(N);
    for (int i = 0; i < astronauts.size(); i++) {
        pair<int, int> p = astronauts[i];
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }
    
    vector<bool> visited(N, false);
    int ans = N *(N - 1) / 2;
    for (int i = 0; i < N; i++) {
        if (visited[i] == false) {
            int csize = dfs(i, visited, graph);
            ans -= csize * (csize - 1) / 2;
        }
    }
    return ans;
}

int main() {
    vector<pair<int, int> > astronauts = {{0, 1}, {2, 3}, {0, 4}};
    cout << count_pairs(5, astronauts) << endl;
    return 0;
}