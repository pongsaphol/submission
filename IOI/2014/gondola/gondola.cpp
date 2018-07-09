#include <bits/stdc++.h>
#define long long long
#include "gondola.h"
using namespace std;

const long M = 1e9+9;

int valid(int n, int inputSeq[]) {
  map<int, int> M;
  for(int i = 0, st = -n-1; i < n; ++i, ++st) {
    M[inputSeq[i]]++;
    if(st == n+1) st = 1;
    if(inputSeq[i] <= n) {
      if(st < 0) st = inputSeq[i];
      else if(st != inputSeq[i]) return 0;
    }
  }
  for(auto x : M) if(x.second > 1) return 0;
  return 1;
}

//----------------------

int replacement(int n, int gondolaSeq[], int replacementSeq[]) {
  int sz = 0, shift = 0;
  for(int i = 0; i < n; ++i) if(gondolaSeq[i] <= n) shift = i - gondolaSeq[i] + 1;
  vector<int> ret(n);
  for(int i = 0; i < n; ++i) ret[i] = gondolaSeq[(i + shift + n) % n];
  int pos = max_element(ret.begin(), ret.end()) - ret.begin() + 1;
  int mx = *max_element(ret.begin(), ret.end());
  map<int, int> M;
  for(int i = 0; i < n; ++i) if(ret[i] > n) M[ret[i]] = i+1;
  for(int i = n+1; i <= mx; ++i) {
    if(M[i] == 0 || i == mx) replacementSeq[sz++] = pos, pos = i;
    else replacementSeq[sz++] = M[i];
  }
  return sz;
}

//----------------------

long powMod(long a, long b) {
  long val = 1;
  while(b) {
    if(b & 1) val = (val * a) % M;
    a = (a * a) % M;
    b >>= 1;
  }
  return val;
}

int countReplacement(int n, int inputSeq[]) {
  if(!valid(n, inputSeq)) return 0;
  vector<int> V; V.emplace_back(n);
  bool st = true;
  for(int i = 0; i < n; ++i) 
    if(inputSeq[i] > n) V.emplace_back(inputSeq[i]);
    else st = false;
  long ans = st ? n : 1; int s = V.size();
  sort(V.begin(), V.end());
  for(int i = 1; i < s; ++i) ans = (ans * powMod(s - i, V[i] - V[i-1] - 1)) % M;
  return ans;
}
