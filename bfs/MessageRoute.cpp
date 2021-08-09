// 컴퓨터 간의 네트워크 존재 여부가 엣지로 정의된 엣지들의 배열이 주어졌을 때, 1번 컴퓨터에서 n번 컴퓨터까지 이르기 위한 최소한의
// 네트워크의 갯수 찾기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int messageRoute(int n, vector<vector<int> >edges)
{
    vector<vector<int> > graph(n + 1);
    for (auto edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, 1e9);
    visited[1] = true;
    dist[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (auto nbr : graph[v]) {
            if (!visited[nbr]) {
                q.push(nbr);
                visited[nbr] = true;
            }
            if (dist[nbr] > dist[v] + 1) {
                dist[nbr] = dist[v] + 1;
            }
        }
    }
    if (dist[n] == 1e9) {
        return -1;
    }
    return dist[n];
}