#include "tile.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;

vector<int> A;
int par[N][19];

void init(int N, int K, int Q, int M, vector<int> AA) {
    A = AA;
    par[M][0] = M;
    A.emplace_back(N+1);
    for(int i = 0; i < M; ++i) par[i][0] = lower_bound(A.begin(), A.end(), A[i]+K) - A.begin();
    for(int i = 1; i < 19; ++i) 
        for(int j = 0; j <= M; ++j) par[j][i] = par[par[j][i-1]][i-1];
}

int getNumberOfSpecialTiles(int L, int R) {
    auto i1 = lower_bound(A.begin(), A.end(), L), i2 = upper_bound(A.begin(), A.end(), R);
    if(i1 == i2) return 0;
    int p = i1 - A.begin(), e = i2 - A.begin();
    int sum = 1;
    for(int i = 18; ~i; --i) 
        if(A[par[p][i]] < A[e]) p = par[p][i], sum += (1 << i);
    return sum;
}
