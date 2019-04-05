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

const int N = 2e5+105;

class TaskE {
private:
    int n, m, sz;
    char arr[N];
    int len[N], pres[N];
    int sa[N], pos[N], tmp[N], lcp[N];
    void solve_sa() {
        for(int i = 0; i < sz; ++i) sa[i] = i, pos[i] = arr[i];
        for(int gap = 1; ; gap <<= 1) {
            auto cmp = [&](int a, int b) {
                if(pos[a] != pos[b]) return pos[a] < pos[b];
                a += gap, b += gap;
                return a < sz && b < sz ? pos[a] < pos[b] : a > b;
            };
            sort(sa, sa+sz, cmp);
            for(int i = 1; i < sz; ++i) tmp[i] = tmp[i-1] + cmp(sa[i-1], sa[i]);
            for(int i = 0; i < sz; ++i) pos[sa[i]] = tmp[i];
            if(tmp[sz-1] == sz-1) break;
        }
    }
    void solve_lcp() {
        for(int i = 0, k = 0; i < sz; ++i) if(pos[i] != sz-1) {
            for(int j = sa[pos[i]+1]; arr[i+k] == arr[j+k];) ++k;
            lcp[pos[i]] = k;
            if(k) --k;
        } else k = 0;
    }
    int t[18][N];
    void solve_rmq() {
        for(int i = 0; i < sz; ++i) t[0][i] = lcp[i];
        for(int i = 1; i < 18; ++i) {
            for(int j = 0; j + (1 << i) <= sz; ++j) {
                t[i][j] = min(t[i-1][j], t[i-1][j + (1 << (i-1))]);
            }
        }
    }
    int get_rmq(int l, int r) {
        int sz = log2(r-l);
        return min(t[sz][l], t[sz][r - (1 << sz)]);
    }
    int get_lcp(int a, int b) {
        a = pos[a], b = pos[b];
        if(a > b) swap(a, b);
        return get_rmq(a, b);
    }
    int countAns;
    int dp[N>>1];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> arr;
        n = strlen(arr);
        arr[n] = '#';
        pres[1] = n+1;
        cin >> m;
        for(int i = 1; i <= m; ++i) {
            cin >> arr + pres[i];
            len[i] = strlen(arr + pres[i]);
            pres[i+1] = pres[i] + len[i];
            arr[pres[i+1]++] = '#';
        }
        sz = pres[m+1];
        solve_sa();
        solve_lcp();
        solve_rmq();
        for(int z = 1; z <= m; ++z) {
            memset(dp, 0, sizeof dp);
            bool have = false;
            for(int i = 0; i <= n; ++i) {
                if(i+1 <= n) dp[i+1] = max(dp[i+1], dp[i]);
                int lcp = min({get_lcp(i, pres[z]), n-i, len[z]});
                if(i + lcp <= n) dp[i+lcp] = max(dp[i+lcp], lcp);
            }
            for(int i = 0; i <= n; ++i) {
                int lcp = min({get_lcp(i, pres[z] + dp[i]), n-i, len[z] - dp[i]});
                if(dp[i] + lcp == len[z]) have = true;
            }
            if(len[z] == 1) have = false;
            countAns += have;
        }
        cout << countAns << endl;
    }
};