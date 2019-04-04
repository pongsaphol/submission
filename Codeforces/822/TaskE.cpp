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

const int N = 2e5+5;

class TaskE {
private:
    int n, m, z;
    char arr[N];
    int sa[N], lcp[N], pos[N], tmp[N];
    void solve_sa() {
        z = n+m+1;
        for(int i = 0; i < z; ++i) sa[i] = i, pos[i] = arr[i];
        for(int gap = 1;; gap <<= 1) {
            auto cmp = [&](int a, int b) {
                if(pos[a] != pos[b]) return pos[a] < pos[b];
                a += gap, b += gap;
                return (a < z && b < z ? pos[a] < pos[b] : a > b);
            };
            sort(sa, sa+z, cmp);
            for(int i = 1; i < z; ++i) tmp[i] = tmp[i-1] + cmp(sa[i-1], sa[i]);
            for(int i = 0; i < z; ++i) pos[sa[i]] = tmp[i];
            if(tmp[z-1] == z-1) break;
        }
    }
    void solve_lcp() {
        for(int i = 0, k = 0; i < z; ++i) if(pos[i] != z-1) {
            for(int j = sa[pos[i]+1]; arr[i+k] == arr[j+k];) k++;
            lcp[pos[i]] = k;
            if(k) --k;
        } else k = 0;
    }
    int t[N<<1];
    void build_rmq() {
        for(int i = 0; i < z; ++i) t[i+z] = lcp[i];
        for(int i = z-1; i; --i) t[i] = min(t[i<<1], t[i<<1|1]);
    }
    int get_rmq(int l, int r) {
        int mn = INF;
        for(l += z, r += z; l < r; l >>= 1, r >>= 1) {
            if(l & 1) mn = min(mn, t[l++]);
            if(r & 1) mn = min(mn, t[--r]);
        }
        return mn;
    }
    int get_lcp(int a, int b) {
        a = pos[a], b = pos[b];
        if(a > b) swap(a, b);
        return get_rmq(a, b);
    }
    int x, dp[35][N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> arr;
        arr[n] = '#';
        cin >> m >> arr+n+1;
        cin >> x;
        solve_sa();
        solve_lcp();
        build_rmq();
        bool have = false;
        for(int cnt = 0; cnt <= x; ++cnt) for(int i = 0; i <= n; ++i) {
            if(i+1 < n) dp[cnt][i+1] = max(dp[cnt][i+1], dp[cnt][i]);
            int lcp = get_lcp(i, dp[cnt][i] + n + 1);
            if(cnt + 1 <= x && i + lcp <= n) dp[cnt+1][i+lcp] = max(dp[cnt+1][i+lcp], dp[cnt][i] + lcp);
            if(dp[cnt][i] == m) have = true;
        }
        cout << (have ? "YES" : "NO") << endl;
    }
};