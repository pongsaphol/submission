#include <bits/stdc++.h>
#include "assistant.h"
using namespace std;

static int n, k;
static map<vector<int>, int> Mp;
static map<vector<int>, int> re;
static bool check[15];
static vector<int> vec;
static void dfs(int lv) {
  if(lv > n) {
    vector<int> now = vec;
    bool st = false;
    for(int i = 1; i <= n; ++i) if(!check[i]) {
      now.emplace_back(i);
      sort(now.begin(), now.end());
      if(Mp.count(now)) {
        now = vec;
      } else {
        Mp[now] = i, re[vec] = i;
        st = true;
        break;
      }
    }
    assert(st);
    return;
  }
  if(vec.size() < k) {
    vec.emplace_back(lv), check[lv] = true;
    dfs(lv+1);
    vec.pop_back(), check[lv] = false;
  }
  if(vec.size() + (n-lv) >= k) dfs(lv+1);
}

void initAssistant(int N, int K) {
  n = N, k = K;
  dfs(1);  
}

int giveClue(vector<int> cards) {
  return re[cards];
}
