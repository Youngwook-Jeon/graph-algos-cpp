// 각 룸에서 갈 수 있는 룸들의 번호가 적힌 배열이 주어졌을 때, 모든 룸들을 방문할 수 있는 지 여부를 리턴
#include <iostream>
#include <vector>
using namespace std;

void dfs(int k, vector<vector<int> > &rooms, vector<int> &visited) {
    visited[k] = 1;
    
    for (auto room_from_k: rooms[k]) {
        if (visited[room_from_k] == 0) {
            dfs(room_from_k, rooms, visited);
        }
    }
}

bool canVisitAllRooms(vector<vector<int> > rooms) {
    int n = rooms.size();
   vector<int> visited(n);
   
   dfs(0, rooms, visited);
   
   for (int i = 0; i < n; i++) {
       if (visited[i] == 0) {
           return false;
       }
   }
   return true;
}