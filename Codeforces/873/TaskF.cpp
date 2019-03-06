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

class TaskF {
private:
    int n; long ans;
    int pos[N], sa[N], tmp[N], lcp[N];
    char A[N], B[N];
    void solve_sa() {
        for(int i = 0; i < n; ++i) sa[i] = i, pos[i] = A[i];
        for(int gap = 1; ; gap <<= 1) {
            auto cmp = [&](int i, int j) {
                if(pos[i] != pos[j]) return pos[i] < pos[j];
                i += gap, j += gap;
                return (i < n && j < n ? pos[i] < pos[j] : i > j);
            };
            sort(sa, sa+n, cmp);
            for(int i = 1; i < n; ++i) tmp[i] = tmp[i-1] + cmp(sa[i-1], sa[i]);
            for(int i = 0; i < n; ++i) pos[sa[i]] = tmp[i];
            if(tmp[n-1] == n-1) break;
        }
    }
    void solve_lcp() {
        for(int i = 0, k = 0; i < n; ++i) if(pos[i] != n-1) {
            for(int j = sa[pos[i]+1]; A[i+k] == A[j+k];) k++;
            lcp[pos[i]] = k;
            if(k) k--;
        } else k = 0;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> A >> B;
        reverse(A, A+n), reverse(B, B+n);
        solve_sa();
        solve_lcp();
        for(int i = 0; i < n; ++i) if(B[i] == '0') ans = max(ans, (long)n-i);
        for(int i = n; i; --i) swap(lcp[i], lcp[i-1]);
        for(int i = 1; i <= n; ++i) tmp[i] = tmp[i-1] + (B[sa[i-1]] == '0');
        lcp[0] = -1;
        stack<int> stk; stk.emplace(0);
        for(int i = 1; i <= n; ++i) {
            while(lcp[stk.top()] >= lcp[i]) {
                int u = stk.top(); stk.pop();
                ans = max(ans, 1ll * lcp[u] * (tmp[i] - tmp[stk.top()]));
            }
            stk.emplace(i);
        }
        cout << ans << endl;
    }
};