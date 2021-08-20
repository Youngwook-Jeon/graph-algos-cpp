// 시작문자열에서 한 단계에 한 문자씩 바꿀 수 있다고 하자
// 또한 wordList 안에 있는 문자로만 바꿀 수 있다
// 이때 시작문자열에서 종료문자열까지 몇단계를 거쳐야 도달할 수 있는지 최소한의 단계 리턴
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList) {
    unordered_set<string> set;
    queue<string> q;

    for (auto word : wordList) {
      set.insert(word);
    }

    q.push(beginWord);
    int ans = 0;

    while (!q.empty()) {
      ans++;
      vector<string> v;
      int n = q.size();

      for (int i = 0; i < n; i++) {
        string s = q.front();
        if (s == endWord) return ans;

        for (int j = 0; j < s.size(); j++) {
          char c = s[j];

          for (int k = 0; k < 26; k++) {
            s[j] = char(97 + k);
            
            if (set.find(s) != set.end()) {
              set.erase(s);
              v.push_back(s);
            }
          }
          s[j] = c;
        }
        q.pop();
      }

      for (auto elm : v) {
        q.push(elm);
      }
    }

    return 0;
}