#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n, m;
int A[N], B[N];
vector<int> g[N];
bool chk[N][1<<N];

void dfs(int u, int st) {
    if(u == n) { puts("YES"); exit(0); }
    if(chk[u][st]) return;
    chk[u][st] = true;
    for(int v : g[u]) if(!(st & v)) dfs(u+1, st | v);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%d", A+i);
    for(int i = 0; i < m; ++i) scanf("%d", B+i);
    for(int i = 0; i < (1<<m); ++i) {
        int sum = 0;
        for(int j = 0; j < m; ++j) if(i >> j & 1) sum += B[j];
        for(int j = 0; j < n; ++j) if(sum == A[j]) g[j].emplace_back(i);
    } 
    dfs(0, 0);
    puts("NO");
}
