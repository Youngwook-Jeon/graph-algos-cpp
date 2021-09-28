// 주어진 그래프가 트리들의 컬렉션인지 아닌지 여부를 체크하기
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

#define MAX_V 100001
vector<int> parent, sz;

int find(int x) {
    if (parent[x] != x) {
        return parent[x] = find(parent[x]);
    }
    return x;
}

void Union(int x, int y) {
    int parent_x = find(x);
    int parent_y = find(y);
    if (parent_x == parent_y) return;
    
    if (sz[parent_x] > sz[parent_y]) {
        swap(parent_x, parent_y);
    }
    parent[parent_x] = parent_y;
    sz[parent_y] += sz[parent_x];
}

bool solve(vector<vector<int> > edges) {
    parent.resize(MAX_V);
    iota(parent.begin(), parent.end(), 0);
    sz.assign(MAX_V, 1);
    int n = edges.size();
    
    for (int i = 0; i < n; i++) {
        int x = edges[i][0], y = edges[i][1];
        if (find(x) == find(y)) return false;
        
        Union(x, y);
    }
    return true;
}