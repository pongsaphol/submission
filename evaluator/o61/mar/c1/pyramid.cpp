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

const int N = 15005;

class pyramid {
private:
    int n;
    short t[N][N];
    void update(int x, int y, int v) {
        for(int i = x; i <= N; i += i & -i) {
            for(int j = y; j <= N; j += j & -j) t[i][j] += v;
        }
    }
    int query(int x, int y, int v = 0) {
        for(int i = x; i; i -= i & -i) {
            for(int j = y; j; j -= j & -j) v += t[i][j];
        }
        return v;
    }
public:
    void solve(istream& cin, ostream& cout) {
        for(int i = 1; i <= N; ++i) t[i].resize(i+2);
        cin >> n;
        for(int i = 0, x, y; i < n; ++i) {
            cin >> x >> y;
            int a = x-y+5001, b = x+y+5001;
            cout << query(a, b) << endl;
            update(a, a, 1), update(a, b+1, -1), update(b+1, a, -1), update(b+1, b+1, 1);
        }
    }
};