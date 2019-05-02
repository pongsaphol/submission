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

const int N = 1<<19;

class election {
private:
    int n, m;
    int ans[N];
    char arr[N];
    vector<pii> que[N];
    int t[N<<1], lz[N<<1];
    void push(int p) {
        if(!lz[p]) return;
        t[p] += lz[p];
        if(p < N) lz[p<<1] += lz[p], lz[p<<1|1] += lz[p];
        lz[p] = 0;
    }
    template<typename T>
    void travel(int x, int y, const T &f, int p = 1, int l = 0, int r = N-1) {
        push(p);
        if(x > r || l > y || x > y) return;
        if(x <= l && r <= y) return f(p);
        int m = l + r >> 1;
        travel(x, y, f, p<<1, l, m), travel(x, y, f, p<<1|1, m+1, r);
        t[p] = min(t[p<<1], t[p<<1|1]);
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        cin >> arr+1;
        cin >> m;
        for(int i = 0, l, r; i < m; ++i) {
            cin >> l >> r;
            que[r].emplace_back(l, i);
        }
        vector<int> stk;
        auto query = [&](int l, int r) {
            int mn = 1e9;
            travel(l, r, [&](int p) { mn = min(mn, t[p]); });
            return mn;
        };
        for(int i = 1; i <= n; ++i) {
            if(arr[i] == 'C') {
                if(!stk.empty()) {
                    travel(stk.back(), n, [&](int p) { lz[p]--, push(p); });
                    stk.pop_back();
                }
                travel(i, n, [&](int p) { lz[p]++, push(p); });
            } else stk.emplace_back(i);
            for(auto x : que[i]) {
                int z = query(x.x, i) - query(x.x-1, x.x-1);
                int pre = lower_bound(all(stk), x.x) - stk.begin();
                ans[x.y] = ((int)stk.size() - pre) - min(0, z);
            }
        }
        for(int i = 0; i < m; ++i) cout << ans[i] << endl;
    }
};