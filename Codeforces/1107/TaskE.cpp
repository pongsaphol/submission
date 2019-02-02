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

const int N = 105;

class TaskE {
private:
    int n, val[N];
    long dp[N][N][N];
    char A[N];
    long mic(int p, int l, int r) {
        if(l > r) return 0;
        if(l == r) return val[p];
        long &now = dp[p][l][r];
        if(now) return now;
        now = val[p] + mic(1, l+1, r);
        for(int i = l+1; i <= r; ++i) if(A[l] == A[i]) {
            now = max(now, mic(1, l+1, i-1) + mic(p+1, i, r));
        }
        return now;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        cin >> A+1;
        for(int i = 1; i <= n; ++i) cin >> val[i];
        cout << mic(1, 1, n) << endl;
    }
};