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

const int N = 1e5+5;

class patrol {
private:
    int n, k, ans1, ans2;
    vector<int> g[N];
    int A[N], B[N], D[N];
    void dfs(int u, int p) {
        if(p) g[u].erase(find(all(g[u]), p));
        set<pii, greater<pii> > pqA, pqD;
        for(int v : g[u]) {
            dfs(v, u);
            pqA.emplace(A[v], v), pqD.emplace(D[v], v);
            if(pqA.size() > 4) pqA.erase(*pqA.rbegin());
            if(pqD.size() > 2) pqD.erase(*pqD.rbegin());
            D[u] = max({D[u], D[v], A[u] + A[v] + 1});
            A[u] = max(A[v] + 1, A[u]), B[u] = max(B[v] + 1, B[u]);
        }
        ans1 = max(ans1, D[u]), ans2 = max(ans2, D[u]);
        if(k == 1) return;
        // B[u] = A[v1] + A[v2] + A[v3] + 3
        int sum = 0, cnt = 0;
        for(auto x : pqA) {
            sum += x.x + 1;
            if(++cnt == 3) break;
        }
        B[u] = max(B[u], sum);
        // B[u] = D[v1] + (A[v2] + 1)
        for(int v : g[u]) {
            sum = 0;
            for(auto x : pqA) if(x.y != v) {
                sum = x.x + 1; break;
            }
            B[u] = max(B[u], D[v] + sum);
        }
        sum = 0;
        // ans = A[v1] + A[v2] + A[v3] + A[v4] + 4;
        for(auto x : pqA) sum += x.x + 1;
        ans2 = max(ans2, sum);
        // ans = D[v] + max(A[v1] + A[v2] + 2, D[v'])
        for(int v : g[u]) {
            int ret = 0;
            cnt = 0;
            for(auto x : pqA) if(x.y != v) {
                ret += x.x + 1;
                if(++cnt == 2) break;
            }
            int other = 0;
            for(auto x : pqD) if(x.y != v) {
                other = x.x; break;
            }
            ans2 = max(ans2, D[v] + max(ret, other));
        }
        // ans = B[v] + A[v'] + 1
        for(int v : g[u]) {
            sum = 0;
            for(auto x : pqA) if(x.y != v) {
                sum = x.x + 1; break;
            }
            ans2 = max(ans2, B[v] + 1 + sum);
        }
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> k;
        for(int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v), g[v].emplace_back(u);
        }
        dfs(1, 0);
        if(k == 1) cout << 2 * (n-1) - ans1 + 1 << endl;
        else cout << 2 * (n-1) - ans2 + 2 << endl;
    }
};