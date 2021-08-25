// {출발지, 도착지}들로 이루어진 티켓 배열이 주어졌을 때, 티켓을 오직 한번씩 사용하여 만들 수 있는 경유지 루트 중 사전식 순서가 가장 
// 작은 경로를 리턴하기. 단 출발은 반드시 JFK에서 함.
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<string> ans;
map<string, multiset<string> > m;
void dfs(string str) {
    while (m[str].size() > 0) {
        auto it = m[str].begin();
        string next = *it;
        m[str].erase(next);
        dfs(next);
    }
    ans.push_back(str);
}

// Eulerian path / Greedy DFS
vector<string> findItinerary(vector<vector<string> > tickets) {
    int n = tickets.size();
    ans.clear();
    m.clear();
    
    for (int i = 0; i < n; i++) {
        string now = tickets[i][0], next = tickets[i][1];
        m[now].insert(next);
    }
    dfs("JFK");
    reverse(ans.begin(), ans.end());
    return ans;
}