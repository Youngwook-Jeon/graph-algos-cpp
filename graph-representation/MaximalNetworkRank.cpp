// 도시간 도로들이 주어졌을 때 최대 네트워크 랭크 계산하기
#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int> > roads) {
    vector<unordered_set<int> > graph(n);
    for (const auto& road : roads) {
        graph[road[0]].insert(road[1]);
        graph[road[1]].insert(road[0]);
    }

    int maximum = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cur = graph[i].size() + graph[j].size();

            if (graph[i].count(j))
                cur--;
        }
        maximum = max(cur, maximum);
    }

    return maximum;
}

int main() {
    vector<vector<int> > roads {{0, 1}, {0, 3}, {1, 2}, {1, 3}};
    cout << "ans: " << endl;
    cout << maximalNetworkRank(4, roads) << endl;
    return 0;
}