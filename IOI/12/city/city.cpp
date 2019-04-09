#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int M = 1e9;
const int N = 1e5+5;

vector<set<int> > g;
int ans, sz[N];

pii dfs(int u, int p) {
    pii now(sz[u], 0);
    for(auto v : g[u]) if(v != p) {
        pii z = dfs(v, u);
        ans = (ans + 1ll * now.x * z.y + 1ll * z.x * now.y) % M;
        now.x = (now.x + z.x) % M, now.y = (now.y + z.y) % M;
    }
    return pii(now.x, (now.y + now.x) % M);
}

int f(int n, int x[], int y[]) {
    g = vector<set<int> >(n+1);
    memset(sz, 0, sizeof sz);
    vector<pii> vec;
    for(int i = 0; i < n; ++i) vec.emplace_back(x[i], y[i]);
    sort(all(vec));
    map<pii, int> Mp;
    for(int i = 1, p = 0; p != n; ++i) {
        do {
            int z = Mp[pii(vec[p].x-1, vec[p].y)];
            if(z) g[z].emplace(i), g[i].emplace(z);
            Mp[vec[p++]] = i, sz[i]++;
        } while(p < n && vec[p-1].x == vec[p].x && vec[p-1].y + 1 == vec[p].y); 
    }
    ans = 0, dfs(1, 0);
    return ans % M;
}

int DistanceSum(int n, int x[], int y[]) {
    return (f(n, x, y) + f(n, y, x)) % M;
}
