#include <bits/stdc++.h>
using namespace std;

const int N = 1<<17;

int n, w;
int ans[N], A[N];
vector<int> vec[N<<3];
int sz[N], par[N];

int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }

int main() {
    memset(ans, -1, sizeof ans);
    fill_n(sz, N, 1);
    iota(par, par+N, 0);
    scanf("%d %d", &n, &w);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", A+i);
        vec[A[i]].emplace_back(i);
    }
    for(int i = 1000000; i; --i) {
        for(auto v : vec[i]) {
            if(v != 1) if(A[v-1] >= A[v]) {
                int a = find(v), b = find(v-1);
                if(a != b) par[a] = b, sz[b] += sz[a];
            }
            if(v != n) if(A[v+1] >= A[v]) {
                int a = find(v), b = find(v+1);
                if(a != b) par[a] = b, sz[b] += sz[a];
            }
        }
        for(auto v : vec[i]) {
            int z = sz[find(v)] - 1;
            ans[z] = max(ans[z], i);
        }
    }
    if(w == -10) for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    else printf("%d", ans[w]);
    printf("\n");
}
