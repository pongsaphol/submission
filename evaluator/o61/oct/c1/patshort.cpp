#include <bits/stdc++.h>
using namespace std;

#define long long long
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define x first
#define y second

const int N = 305;

const int inf = 1e9 + 1000;

int m, q;

long d[N][N];
vector<pii> coor;

long dis(pii a, pii b) {
    int x = abs(a.x - b.x), y = abs(a.y - b.y);
    if(x >= y) return x;
    return y + ((x&1) ^ (y&1));
}

int main() {
    scanf("%d %d", &m, &q);
    fill_n(d[0], N*N, inf);
    vector<pair<pii, pii> > E;
    for(int i = 0, a, b, c, d; i < m; ++i) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        coor.emplace_back(a, b), coor.emplace_back(c, d);
        E.emplace_back(pii(a, b), pii(c, d));
    }
    sort(all(coor));
    coor.resize(unique(all(coor)) - coor.begin());
    m = coor.size();
    for(int i = 1; i <= coor.size(); ++i) d[i][i] = 0;
    for(auto &x : E) {
        pii s, t; tie(s, t) = x;
        int a = upper_bound(all(coor), s) - coor.begin();
        int b = upper_bound(all(coor), t) - coor.begin();
        d[a][b] = d[b][a] = 1;
    }
    for(int k = 1; k <= m; ++k) for(int i = 1; i <= m; ++i) for(int j = 1; j <= m; ++j) 
        d[i][j] = min({d[i][j], d[i][k] + d[k][j], dis(coor[i-1], coor[j-1]) });
    for(int i = 0, a, b, c, d; i < q; ++i) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        pii s(a, b), t(c, d);
        long mn = dis(s, t);
        for(int i = 1; i <= m; ++i) for(int j = 1; j <= m; ++j) mn = min(mn, dis(s, coor[i-1]) + ::d[i][j] + dis(coor[j-1], t));
        printf("%lld\n", mn);
    } 

}