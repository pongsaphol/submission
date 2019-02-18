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

const int N = 1e4+1, K = 101;

class uzastopni {
private:
    int n, A[N];
    vector<int> g[N];
    vector<pii> S[N];
    queue<int> Q[K];
    bitset<K> dp[N][K];
    void dfs(int u) {
        for(int v : g[u]) dfs(v);
        for(int v : g[u]) for(pii x : S[v]) if(x.x != A[u]) Q[x.x].emplace(x.y);
        for(int l = K-1; l; --l) {
            if(l == A[u]) dp[u][l] |= dp[u][l+1], dp[u][l][l] = true;
            else while(!Q[l].empty()) {
                int r = Q[l].front(); Q[l]u.pop();
                if(A[u] < l || A[u] > r) dp[u][l] |= dp[u][r+1], dp[u][l][r] = true;
            }
            for(int r = K-1; r; --r) if(dp[u][l][r] && l <= A[u] && A[u] <= r) S[u].emplace_back(l, r);
        }
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> A[i];
        for(int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v);
        }
        dfs(1);
        cout << S[1].size();
    }
};