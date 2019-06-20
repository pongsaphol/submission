#include <bits/stdc++.h>
#include "assistant.h"
using namespace std; 

void Assist(unsigned char *A, int N, int K, int R) {
  int bt = log2(N);
  set<int> S; 
  for(int i = 0; i < K; ++i) S.emplace(i);
  int ptr = 0;
  for(int i = 0; i < N; ++i) {
    int v;
    if(S.count(v = GetRequest())) continue;
    int val = 0;
    for(int i = 0; i < bt; ++i) if(A[ptr++]) val |= (1 << i);
    PutBack(val);
    S.erase(val);
    S.emplace(v);
  }
}
