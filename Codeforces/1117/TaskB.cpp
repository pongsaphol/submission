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

class TaskB {
private:
    int n, m, k;
    int A[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m >> k;
        for(int i = 0; i < n; ++i) cin >> A[i];
        sort(A, A+n, greater<int>());
        long cyc = 1ll * A[0] * k + A[1];
        long sum = cyc * (m / (k+1));
        m %= (k+1);
        sum += 1ll * A[0] * m;
        cout << sum << endl;
    }
};