#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pss pair<short, short>
#define x first
#define y second

const int N = 2e3+5;

char A[N][N];
int n, k;
int dp[N][N];
pss par[N][N][12];
pii hsh[N][N];
int dep[N][N];

pii mm(131, 133);

pii add(pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }
pii sup(pii a, pii b) { return pii(a.x - b.x, a.y - b.y); }
pii mul(pii a, pii b) { return pii(a.x * b.x, a.y * b.y); }
pii pw[N<<1];
vector<pii> ldep[N<<1];

int main() {
    pw[0] = pii(1, 1);
    for(int i = 1; i < 2*N; ++i) pw[i] = mul(pw[i-1], mm);
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%s", A[i] + 1);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
        dep[i][j] = i+j-1;
        ldep[i+j-1].emplace_back(i, j);
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + (A[i][j] == 'a');
    }
    par[n][n][0] = pii(n, n);
    for(int i = 1; i < 11; ++i) par[n][n][i] = pii(n, n);
    for(int i = n; i; --i) for(int j = n; j; --j) {
        if(i == n and j == n) continue;
        int st = 0;
        if(i != n and j != n) {
            pii r(i, j+1), d(i+1, j);
            for(int k = 11; ~k; --k) {
                int x1, y1, x2, y2;
                tie(x1, y1) = par[r.x][r.y][k];
                tie(x2, y2) = par[d.x][d.y][k];
                pii rr = sup(mul(hsh[r.x][r.y], pw[dep[x1][y1] - dep[r.x][r.y]]), hsh[x1][y1]);
                pii dd = sup(mul(hsh[d.x][d.y], pw[dep[x2][y2] - dep[d.x][d.y]]), hsh[x2][y2]);
                if(rr == dd) r = pii(x1, y2), d = pii(x2, y2);
            }
            if(A[r.x][r.y] < A[d.x][d.y]) st = 1; else st = 2;
        }
        if(i == n || st == 1) par[i][j][0] = pii(i, j+1), hsh[i][j] = add(mul(hsh[i][j+1], mm), pii(A[i][j], A[i][j]));
        if(j == n || st == 2) par[i][j][0] = pii(i+1, j), hsh[i][j] = add(mul(hsh[i+1][j], mm), pii(A[i][j], A[i][j]));
        for(int k = 1; k < 12; ++k) {
            par[i][j][k] = par[par[i][j][k-1].x][par[i][j][k-1].y][k-1];
        }        
    }
    for(int i = n+n-1; i; --i) {
        bool st = false;
        vector<pii> V;
        for(auto x : ldep[i]) 
            if(i - dp[x.x][x.y] <= k) st = true, V.emplace_back(par[x.x][x.y][0]);
        if(st) {
            pii now = V[0];
            for(int i = 1; i < V.size(); ++i) {
                pii r = now, d = V[i];
                for(int k = 11; ~k; --k) {
                    int x1, y1, x2, y2;
                    tie(x1, y1) = par[r.x][r.y][k];
                    tie(x2, y2) = par[d.x][d.y][k];
                    pii rr = sup(mul(hsh[r.x][r.y], pw[dep[x1][y1] - dep[r.x][r.y]]), hsh[x1][y1]);
                    pii dd = sup(mul(hsh[d.x][d.y], pw[dep[x2][y2] - dep[d.x][d.y]]), hsh[x2][y2]);
                    if(rr == dd) r = pii(x1, y2), d = pii(x2, y2);
                }
                if(A[r.x][r.y] > A[d.x][d.y]) now = V[i];
            }
            for(int j = 1; j <= i; ++j) printf("a");
            if(i == n+n-1) return 0;
            while(1) {
                printf("%c", A[now.x][now.y]);
                if(now == pii(n, n)) break;
                now = par[now.x][now.y][0];
            }
            return 0;
        }
        if(i == 1) {
            pii now(1, 1);
            while(1) {
                printf("%c", A[now.x][now.y]);
                if(now == pii(n, n)) break;
                now = par[now.x][now.y][0];
            }
        }
    }
}
