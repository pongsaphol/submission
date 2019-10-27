#include <bits/stdc++.h>
using namespace std;

const int sq = 490;

const int  N = 240005;

int n, m, q;

bool status[N];
int num[N];
vector<int> shop[N];
vector<int> que[N];
int val[N];

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for(int i = 1; i <= m; ++i) {
    int sz; scanf("%d", &sz);
    if(sz <= sq) {
      status[i] = true;
      shop[i].resize(sz);
      for(int &v : shop[i]) scanf("%d", &v);
    } else {
      status[i] = false;
      for(int j = 0, val; j < sz; ++j) {
        scanf("%d", &val);
        que[val].emplace_back(i);
      }
    }
  }
  while(q--) {
    int t; scanf("%d", &t);
    if(t == 1) {
      int a, b; scanf("%d %d", &a, &b);
      int ad = b - num[a];
      num[a] = b;
      if(status[a]) 
        for(int v : shop[a]) val[v] += ad;
    } else {
      int a; scanf("%d", &a);
      int sum = val[a];
      for(int v : que[a]) sum += num[v];
      printf("%d\n", sum);
    }
  }

}