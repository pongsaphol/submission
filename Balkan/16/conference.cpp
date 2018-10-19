#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int n, m, k;
int s[N], t[N];
int jour[N], tme[N];
int ans[2][N];

int par[N];
bool have[N];

int find(int u) { return par[u] = par[u] == u ? u : find(par[u]); }

int main() {
    iota(par, par+N, 0);
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1, a, b; i <= m; ++i) {
        scanf("%d %d", &a, &b);
        if(a > b) swap(a, b);
        s[i] = a, t[i] = b;
    }
    for(int i = k+1; i <= n; ++i) jour[i] = i;
    for(int i = m; i; --i) {
        if(s[i] > k) tme[s[i]] = i;
        if(t[i] > k) tme[t[i]] = i;
        if(s[i] > k and t[i] > k) continue;
        if(s[i] <= k and t[i] > k) {
            tme[s[i]] = tme[t[i]], jour[s[i]] = jour[t[i]];
            if(!ans[0][s[i]]) ans[0][s[i]] = i, ans[1][s[i]] = jour[t[i]];
            continue;
        }
        if(!ans[0][s[i]] and !ans[0][t[i]])  continue;
        if(ans[0][s[i]] and ans[0][t[i]]) {
            if(tme[s[i]] > tme[t[i]]) swap(s[i], t[i]);
            jour[t[i]] = jour[s[i]], tme[t[i]] = tme[s[i]];
            continue;
        }
        if(ans[0][s[i]] and !ans[0][t[i]]) swap(s[i], t[i]);
        tme[s[i]] = tme[t[i]], jour[s[i]] = jour[t[i]];
        ans[0][s[i]] = i, ans[1][s[i]] = jour[s[i]];
    }
    for(int i = 1; i <= m; ++i) {
        if(ans[0][s[i]] == i) have[s[i]] = true;
        if(ans[0][t[i]] == i) have[t[i]] = true;
        int a = find(s[i]), b = find(t[i]);
        if(have[a]) par[b] = a;
        else if(have[b]) par[a] = b;
    }
    for(int i = 1; i <= k; ++i) printf("%d ", ans[0][i] ? ans[0][i] : -1);
    puts("");
    vector<int> ret;
    for(int i = k+1; i <= n; ++i) if(have[find(i)]) ret.emplace_back(i);
    printf("%d ", (int)ret.size());
    for(int v : ret) printf("%d ", v);
    puts("");
    for(int i = 1; i <= k; ++i) printf("%d ", ans[1][i] ? ans[1][i] : -1);
    puts("");
}
