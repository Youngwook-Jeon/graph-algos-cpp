#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool solve(vector<vector<int> > graph)
{
    int n = graph.size();
    vector<int> visited(n + 1, -1);
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            queue<int> q;
            q.push(i);
            visited[i] = 0;

            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (auto nbr : graph[x]) {
                    if (visited[nbr] == -1) {
                        visited[nbr] = visited[x] ^ 1;
                        q.push(nbr);
                    } else {
                        if (visited[nbr] == visited[x]) return true;
                    }
                }
            }
        }
    }

    return false;
}