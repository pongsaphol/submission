#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define iii tuple<int, int, int>
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 55;

class pond {
private:
    int n, m;
    int inp[N][N];
    int col[N][N];
    int dp[1<<4][N][N];
    int step;
    void bfs() {
        queue<pii> Q; Q.emplace(0, 0), col[0][0] = -2;
        while(!Q.empty()) {
            int x = Q.front().x, y = Q.front().y; Q.pop();
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx > n+1 || ny < 0 || ny > m+1) continue;
                if(inp[nx][ny]) inp[nx][ny] = INF;
                if(inp[nx][ny] || col[nx][ny] != -1) continue;
                col[nx][ny] = -2;
                Q.emplace(nx, ny);
            }
        }
    }
public:
    void solve(istream& cin, ostream& cout) {
        fill_n(dp[0][0], (1<<4) * N * N, INF);
        memset(col, -1, sizeof col);
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> inp[i][j];
        bfs();
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) if(col[i][j] == -1 && !inp[i][j]){
            queue<pii> Q; Q.emplace(i, j), col[i][j] = step;
            while(!Q.empty()) {
                int x = Q.front().x, y = Q.front().y; Q.pop();
                dp[1<<step][x][y] = 0;
                for(int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || nx > n+1 || ny < 0 || ny > m+1) continue;
                    if(inp[nx][ny] || col[nx][ny] != -1) continue;
                    col[nx][ny] = step;
                    Q.emplace(nx, ny);
                }
            }
            step++;
        }
        for(int k = 1; k < (1 << step); ++k) {
            for(int u = k; u; u = (u-1) & k) {
                int v = k - u;
                for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
                    dp[k][i][j] = min(dp[k][i][j], dp[u][i][j] + dp[v][i][j] - inp[i][j]);
                }
            }
            priority_queue<iii, vector<iii>, greater<iii>> Q;
            for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) Q.emplace(dp[k][i][j], i, j);
            while(!Q.empty()) {
                int z, x, y; tie(z, x, y) = Q.top(); Q.pop();
                if(z != dp[k][x][y]) continue;
                for(int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    int nz = z + inp[nx][ny];
                    if(nx < 0 || nx > n+1 || ny < 0 || ny > m+1) continue;
                    if(dp[k][nx][ny] > nz) Q.emplace(dp[k][nx][ny] = nz, nx, ny);
                }
            }
        }
        int mn = INF;
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) mn = min(mn, dp[(1<<step)-1][i][j]);
        cout << mn << endl;
    }
};