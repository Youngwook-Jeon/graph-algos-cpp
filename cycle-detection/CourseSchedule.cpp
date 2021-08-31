// [a, b] 쌍의 의미는 a 과목을 듣기 위해 반드시 선수과목으로 b를 들어야 한다는 것
// 그런 쌍들의 배열이 주어졌을 때 모든 과목을 수강할 수 있는지 여부를 리턴하기
#include <iostream>
#include <vector>
using namespace std;

bool ans;
void dfs(int v, vector<vector<int> > &graph, vector<int> &progress) {
    progress[v] = 1;
    for (int next : graph[v]) {
        if (progress[next] == 0) {
            dfs(next, graph, progress);
        } else {
            if (progress[next] == 1) {
                ans = false;
            }
        }
    }
    progress[v] = 2;
}

bool canFinish(vector<vector<int> > prerequisites,int numCourses) {
        ans = true;
        vector<vector<int> > graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> progress(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            dfs(i, graph, progress);
        }
        return ans;
}