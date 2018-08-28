#include "grader.h"
#include "decoder.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;

static vector<int> g[N];
static int d[N], v[N], z[N];

int getInt(int len) {
    int sum = 0;
    for(int i = 0; i < len; ++i) sum = (sum<<1) + decode_bit();
    return sum;
}

static void dfs(int u, int p) {
    d[u] = d[p] + v[u];
    for(int v : g[u]) if(v != p) dfs(v, u);
}

void decode(int nv, int nh) {
    for(int i = 1; i < nv; ++i) {
        int p = getInt(10);
        g[p].emplace_back(i), g[i].emplace_back(p);
    }
    for(int i = 0; i < nh; ++i) {
        d[i] = 0;
        for(int j = 0; j < 200; ++j) {
            int ret = getInt(8);
            for(int k = 0; k < 5; ++k) z[j*5+k] = ret % 3, ret /= 3;
        }
        for(int j = 0; j < 1000; ++j) v[j] = (z[j] == 0 ? 0 : (z[j] == 1 ? -1 : 1));
        dfs(i, i);
        for(int j = 0; j < nv; ++j) hops(i, j, d[j]);
    }
    return;
}
