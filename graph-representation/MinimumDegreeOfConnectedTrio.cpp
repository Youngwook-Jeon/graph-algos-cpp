// 그래프가 주어졌을 때 connected trio중 가장 작은 degree를 리턴하기
#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
using namespace std;

int minTrioDegree(int n, vector<vector<int> > edges) {
    map<int, unordered_set<int> > graph;
    for (const auto& edge : edges) {
        graph[edge[0]].insert(edge[1]);
        graph[edge[1]].insert(edge[0]);
    }

    int min_val = INT_MAX;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (graph[i].count(j) and graph[i].count(k) and graph[j].count(k)) {
                    int cur = graph[i].size() + graph[j].size() + graph[k].size() - 6;
                    min_val = min(cur, min_val);
                }
            }
        }
    }
    if (min_val == INT_MAX)
        min_val = -1;

    return min_val;
}

int main() {
    vector<vector<int> > edges {{1, 2}, {1, 3}, {3, 2}, {4, 1}, {5, 2}, {3, 6}};
    cout << minTrioDegree(6, edges) << endl;
    return 0;
}