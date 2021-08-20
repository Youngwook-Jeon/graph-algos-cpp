// 주어진 시퀀스가 tree 형태의 그래프의 bfs를 통해 만들어 낼 수 있는 시퀀스인지 여부를 체크하기
#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

bool validBfs(int n, vector<int> sequence , vector<vector<int> > edges)
{
  int x, y, z, t;
  vector<vector<int> > adj(n + 1);
  vector<int> visited(n + 1);

  for (int i = 0; i < edges.size(); i++) {
    x = edges[i][0], y = edges[i][1];
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  queue<int> q;
  q.push(1);
  visited[1] = 1;
  int flag = 1;
  y = 1;

  while (!q.empty()) {
    x = q.front();
    q.pop();

    set<int> s;
    for (int i = 0; i < adj[x].size(); i++) {
      z = adj[x][i];
      if (visited[z] == 0) {
        s.insert(z);
        visited[z] = 1;
      }
    }

    t = 0;
    while (t < s.size()) {
      if (s.find(sequence[y]) == s.end()) {
        flag = 0;
        break;
      }
      q.push(sequence[y]);
      y++;
      t++;
    }
  }

  return (flag == 1) ? true : false;
}