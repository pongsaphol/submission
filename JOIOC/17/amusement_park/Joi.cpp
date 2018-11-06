#include <bits/stdc++.h>
#include "Joi.h"
using namespace std;

void Joi(int N, int M, int A[], int B[], long long X, int T) {
    vector<vector<int> > g(N);
    vector<int> in(N), out(N), pos(N), par(N), bit(N);
    vector<bool> check(N);
    for(int i = 0; i < M; ++i) {
        g[A[i]].emplace_back(B[i]);
        g[B[i]].emplace_back(A[i]);
    }
    function<void(int)> dfs;
    dfs = [&](int u) {
        static int ptr = 0;
        check[u] = true, in[u] = ptr++, pos[in[u]] = u;
        for(int v : g[u]) if(!check[v]) par[v] = u, dfs(v);
        out[u] = ptr;
    };
    dfs(0);
    for(int l = 0; l < N;) {
        int r = out[pos[l]]; 
        int sz = r-l+1;
        if(sz >= 60) {
            r = l+59;
            for(int i = l; i <= r; ++i) bit[pos[i]] = i-l;
        } else {
            int b = bit[par[pos[l]]];
            if(b > sz) for(int i = l; i <= r; ++i) bit[pos[i]] = 60-sz+i-l;
            else {
                int ptr = l, cnt = 0;
                while(cnt < b) bit[pos[ptr++]] = cnt++;
                cnt = 60-(sz-b);
                while(ptr <= r) bit[pos[ptr++]] = cnt++;
            }
        }
        l = r+1;
    }
    for(int i = 0; i < N; ++i) MessageBoard(i, X >> bit[i] & 1);
}
