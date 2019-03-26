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

class backup {
private:
    int n, k;
    int ans, arr[N], d[N];
    int pre[N], nxt[N];
    bool used[N];
    priority_queue<iii, vector<iii>, greater<iii> > Q;
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) {
            cin >> arr[i];
            pre[i] = i-1, nxt[i] = i+1;
            if(i != 1) Q.emplace(d[i] = arr[i] - arr[i-1], i-1, i);
        }
        while(k--) while(true) {
            int v, x, y; tie(v, x, y) = Q.top(); Q.pop();
            if(used[x] || used[y]) continue;
            ans += v;
            used[x] = used[y] = true;
            int s = pre[x], t = nxt[y];
            nxt[s] = t, pre[t] = s;
            d[t] = d[t] + d[x] - d[y];
            if(s >= 1 && t <= n && (!used[s] && !used[t])) Q.emplace(d[t], s, t);
            break;
        }
        cout << ans << endl;
    }
};