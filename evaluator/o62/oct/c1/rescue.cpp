#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#include "rescuelib.h"
using namespace std; 

const int N = 1005;

int n, m;
int cnt[N][N];

function<pii(int, int)> f[4] = {
    [](int x, int y) { return pii(x, y); },
    [](int x, int y) { return pii(n-x+1, y); },
    [](int x, int y) { return pii(x, m-y+1); },
    [](int x, int y) { return pii(n-x+1, m-y+1); }
};

void solve(int x, int y, int dist) {
    if(dist == -1) return;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        if(abs(i-x) + abs(j-y) == dist) {
            cnt[i][j]++;
        }
    }
}

int ask(int x, int y, int id) {
    tie(x, y) = f[id](x, y);
    int val = drop_robot(x, y);
    solve(x, y, val);
    return val;
}

int main() {
    get_size(n, m);
    int id, cc = 0;
    for(int i = 0, x, y; i < 4; ++i) {
        if(ask(1, 1, i) != -1) id = i, cc++;
    }
    if(cc != 1) {
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
            if(cnt[i][j] == cc) answer(i, j);
        }
        return 0;
    }
    int l = 1, r = n;
    while(l < r) {
        int m = (l + r) >> 1;
        int v1 = ask(m, 1, id);
        int v2 = ask(m+1, 1, id);
        if(v2 == -1 || v2 > v1) r = m;
        else l = m+1;
    }
    int val = ask(r, 1, id);
    int a, b; tie(a, b) = f[id](r, val+1);
    answer(a, b);
    return 0;
}