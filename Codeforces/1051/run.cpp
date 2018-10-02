#include <bits/stdc++.h>
using namespace std;

int d[15][15];

int main() {
    fill_n(d[0], 15*15, 1000000000);
    int n, m; cin >> n >> m;
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
    }
    for(int i = 1; i <= n; ++i) d[i][i] = 0;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) for(int k = 1; k <= n; ++k) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        cout << d[a][b] << endl;
    }
}
