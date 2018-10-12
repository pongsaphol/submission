#include "wirelib.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int n, sol[N];

bool status[N];

void solve(int l, int r, vector<int> &now) {
    if(l == r) {
        for(int x : now) sol[x] = r;
        return;
    }
    int m = l + r >> 1;
    for(int i = l; i <= m; ++i) if(!status[i]) status[i] = cmd_C(i);
    for(int i = m+1; i <= r; ++i) if(status[i]) status[i] = cmd_C(i);
    vector<int> L, R;
    for(int x : now) if(cmd_T(x)) L.emplace_back(x); else R.emplace_back(x);
    solve(l, m, L), solve(m+1, r, R);
}

int main() {
    n = wire_init();
    vector<int> now;
    for(int i = 1; i <= n; ++i) now.emplace_back(i);
    solve(1, n, now);
    cmd_D(sol);
}
