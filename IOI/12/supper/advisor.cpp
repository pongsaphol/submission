#include <bits/stdc++.h>
#include "advisor.h"
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

static queue<int> pos[N];
static bool inq[N];

void ComputeAdvice(int *C, int N, int K, int M) {
  int bt = log2(N);
  for(int i = 0; i < N; ++i) pos[C[i]].emplace(i);
  for(int i = 0; i < N; ++i) pos[i].emplace(N);
  set<pii, greater<pii> > Q;
  for(int i = 0; i < K; ++i) Q.emplace(pos[i].front(), i), inq[i] = true;
  for(int i = 0; i < N; ++i) {
    if(inq[C[i]]) {
      Q.erase(pii(pos[C[i]].front(), i));
    } else {
      int v = Q.begin()->y; Q.erase(Q.begin());
      inq[v] = false, inq[C[i]] = true;
      for(int i = 0; i < bt; ++i) WriteAdvice(v >> i & 1);
    } 
    pos[C[i]].pop();
    Q.emplace(pos[C[i]].front(), C[i]);
  }
}
