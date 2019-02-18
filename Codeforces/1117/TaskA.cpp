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

class TaskA {
private:
    int n;
    int A[N];
    int dp[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> A[i];
        int mx = *max_element(A+1, A+n+1);
        for(int i = 1; i <= n; ++i) dp[i] = (A[i] == mx ? (dp[i-1] + 1) : 0);
        cout << *max_element(dp+1, dp+n+1);
    }
};