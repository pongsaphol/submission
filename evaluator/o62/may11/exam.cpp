#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+100;
const int K = 35;

int n, m;
char A[N][K];
vector<int> g[N];

int idx, zz;
int low[N], pre[N], pos[N];
bool instk[N];
bool in[N];
stack<int> stk;

void tarjan(int u) {
    low[u] = pre[u] = ++idx;
    stk.emplace(u), instk[u] = true;
    for(int v : g[u]) if(!pre[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
    } else if(instk[v]) low[u] = min(low[u], pre[v]);
    if(low[u] == pre[u]) {
        int v; ++zz;
        do {
            instk[v = stk.top()] = false, stk.pop();  
            pos[v] = zz;
        } while(v != u);
    } 
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%s", A[i]+1);
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(A[j][i] == '1') g[j].emplace_back(i+n);
            else g[i+n].emplace_back(j);
        }
    }
    for(int i = 1; i <= n; ++i) if(!pre[i]) tarjan(i);
    vector<int> apos;
    for(int i = 1; i <= n+m; ++i) {
        if(i <= n) apos.emplace_back(pos[i]);
        if(pos[i]) for(int v : g[i]) 
            if(pos[v] != pos[i]) in[pos[v]] = true;
    }
    sort(apos.begin(), apos.end());
    apos.resize(unique(apos.begin(), apos.end()) - apos.begin());
    int cnt = 0, ans;
    for(int v : apos) if(in[v] == 0) cnt++, ans = v;
    if(cnt != 1) return !printf("-1\n");
    for(int i = 1; i <= n; ++i) if(pos[i] == ans) printf("%d ", i);
    printf("\n");
}