#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 105;

int n, m, q, t, r, c;
int X[] = {0, 0, -1, 1}, Y[] = {1, -1, 0, 0};
bool g[N][N];
int A[N][N];
vector<pii> que[1005];

void solve() {
    memset(g, 0, sizeof g), memset(A, 0, sizeof A);
    for(int i = 0; i < 1005; ++i) que[i].clear();
    scanf("%d %d %d %d %d %d", &n, &m, &q, &t, &r, &c);
    for(int i = 0, a, b, c; i < q; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        que[a].emplace_back(b, c);
    }
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
        char c; scanf(" %c", &c); g[i][j] = (c == '#');
    }
    A[r][c] = 1;
    for(int tc = 0; tc <= t; ++tc) {
        for(auto x : que[tc]) 
            if(A[x.x][x.y] == 1) return void(puts("NO"));
            else A[x.x][x.y] = 2;
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(A[i][j]) for(int k = 0; k < 4; ++k) {
            int x = i + X[k], y = j + Y[k];
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            if(g[x][y]) continue;
            if(!A[x][y]) A[x][y] = A[i][j];
            if(A[x][y] != A[i][j]) return void(puts("NO"));
        }
    }
    puts("YES");
}

int main() {
    int T; scanf("%d", &T);
    while(T--) solve();
}
