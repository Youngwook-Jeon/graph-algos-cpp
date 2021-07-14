// 스타 그래프의 센터 찾기
#include <iostream>
#include <vector>
using namespace std;

int findCenter(vector<vector<int> >edges)
{
    int a = edges[0][0];
    int b = edges[0][1];
    
    for (int x : edges[1]) {
        if (x == a) {
            return a;
        } 
        
        if (x == b) {
            return b;
        }
    }
}

int main()
{
    vector<vector<int> > edges{{1, 2}, {2, 3}, {4, 2}};
    cout << findCenter(edges) << endl;
    return 0;
}