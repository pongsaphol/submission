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

class subrev {
private:
    int n, arr[N];
    int dp[N][N][N][N];
    int solve(int l, int r, int lo, int hi) {
        int &now = dp[l][r][lo][hi];
        if(now != -1) return now;
        if(lo > hi) return now = -INF;
        if(l > r) return now = 0;
        if(l == r) return now = (arr[l] >= lo && arr[r] <= hi);
        now = 0;
        // case swap l and r
        now = max(now, solve(l+1, r-1, lo, hi));
        if(arr[r] >= lo) now = max(now, solve(l+1, r-1, arr[r], hi) + 1);
        if(arr[l] <= hi) now = max(now, solve(l+1, r-1, lo, arr[l]) + 1);
        if(arr[r] >= lo && arr[l] <= hi && arr[r] <= arr[l]) now = max(now, solve(l+1, r-1, arr[r], arr[l]) + 2);
        // case skip l
        now = max(now, solve(l+1, r, lo, hi));
        if(arr[l] >= lo) now = max(now, solve(l+1, r, arr[l], hi) + 1);
        // case skip r
        now = max(now, solve(l, r-1, lo, hi));
        if(arr[r] <= hi) now = max(now, solve(l, r-1, lo, arr[r]) + 1);
        return now;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        cout << solve(0, n-1, 0, 50) << endl;
    }
};