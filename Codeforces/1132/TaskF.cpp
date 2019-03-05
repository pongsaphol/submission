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

const int N = 505;

class TaskF {
private:
    int n;
    int dp[N][N][27];
    char A[N];
    int solve(int l, int r, int p) {
        if(l > r) return 0;
        if(dp[l][r][p] != INF) return dp[l][r][p];
        int &x = dp[l][r][p];
        if(l == r) return x = (A[l] != p);
        for(int i = l+1; i <= r; ++i) x = min(x, solve(i, r, A[l]) + solve(l+1, i-1, 26));
        if(p != A[l]) x++;
        return x;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        cin >> A+1;
        for(int i = 1; i <= n; ++i) A[i] -= 'a';
        fill_n(dp[0][0], N*N*27, INF);
        cout << solve(1, n, 26) << endl;
    }
};