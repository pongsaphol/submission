#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define long long long
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 1005;

class TaskB {
private:
    int n;
    int a[N][2], b[N][2];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1];
        for(int i = 1; i <= n; ++i) cin >> b[i][0] >> b[i][1];
        map<pii, int> M;
        for(int j = 1; j <= n; ++j)
            for(int i = 1; i <= n; ++i) M[pii(a[j][0] + b[i][0], a[j][1] + b[i][1])]++;
        for(auto x : M) {
            if(x.y == n) {
                cout << x.x.x << ' ' << x.x.y << endl;
                return;
            }
        }
    }
};