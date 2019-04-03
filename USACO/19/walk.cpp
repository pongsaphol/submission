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


class walk {
private:
public:
    void solve(istream& cin, ostream& cout) {
        long a = 2019201913, b = 2019201949, c = 2019201997;
        long x, y; cin >> x >> y;
        long ans = ((y-1) * a + x * b) % c;
        cout << ans << endl;
    }
};