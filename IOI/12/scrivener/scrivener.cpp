#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;

int step, ptr;
int par[N][20];
char val[N];
int sz[N], pos[N];

void Init() { }

void TypeLetter(char L) {
  val[++ptr] = L;
  par[ptr][0] = pos[step];
  sz[step+1] = sz[step];
  for(int i = 1; i < 20; ++i) par[ptr][i] = par[par[ptr][i-1]][i-1];
  sz[++step]++;
  pos[step] = ptr;
}

void UndoCommands(int U) {
  pos[step+1] = pos[step-U];
  sz[step+1] = sz[step-U];
  step++;
}

char GetLetter(int P) {
  int jump = sz[step] - P - 1;
  int p = pos[step];
  for(int i = 19; ~i; --i) if(jump >> i & 1) p = par[p][i];
  return val[p];
}
