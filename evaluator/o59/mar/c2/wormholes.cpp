#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 70;

int k, m;
pii pos[N];
vector<vector<pii> > g(N);

int dis(pii a, pii b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    scanf("%d %d", &k, &m);
    for(int i = 0, x1, y1, x2, y2; i < k; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        pos[i<<1] = pii(x1, y1);
        pos[i<<1|1] = pii(x2, y2);
        g[i<<1].emplace_back(i<<1|1, 0);
        g[i<<1|1].emplace_back(i<<1, 0);
    } 
    int st = (k << 1);
    for(int i = 2; i < st; ++i) {
        for(int j = i - 1 - (i&1); ~j; --j) {
            int d = dis(pos[i], pos[j]);
            g[i].emplace_back(j, d), g[j].emplace_back(i, d);
        }
    }
    while(m--) {
        int a, b, c, dd; scanf("%d %d %d %d", &a, &b, &c, &dd);
        pos[st] = pii(a, b);
        for(int i = 0; i < st; ++i) {
            g[st].emplace_back(i, dis(pos[i], pii(a, b)));
            g[i].emplace_back(st, dis(pos[i], pii(a, b)));
        }
        for(int i = 0; i <= st; ++i) {
            g[st+1].emplace_back(i, dis(pos[i], pii(c, dd)));
            g[i].emplace_back(st+1, dis(pos[i], pii(c, dd)));
        }
        g[st].emplace_back(st+1, dis(pii(a, b), pii(c, dd)));
        g[st+1].emplace_back(st, dis(pii(a, b), pii(c, dd)));
        vector<int> d(st+2, (int)1e9);
        priority_queue<pii, vector<pii>, greater<pii> > Q;
        Q.emplace(d[st] = 0, st);
        while(!Q.empty()) {
            pii now = Q.top(); Q.pop();
            if(now.x != d[now.y]) continue;
            for(auto v : g[now.y]) if(d[v.x] > now.x + v.y) Q.emplace(d[v.x] = now.x + v.y, v.x);
        }
        g[st].clear(), g[st+1].clear();
        for(int i = 0; i < st; ++i) g[i].pop_back(), g[i].pop_back();
        printf("%d\n", d[st+1]);
    }
}
