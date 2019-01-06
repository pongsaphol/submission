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

const int N = 1e6+5;

class collectmushrooms {
private:
    vector<vi> qs;
    vector<pii> vec;
    int n, m, d, k, ans;
    char inp[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m >> d >> k;
        qs = vector<vi>(n+5, vi(m+5));
        for(int i = 1; i <= n; ++i) {
            cin >> inp+1;
            auto fx = [&](int v) {
                if(v > n) v = n+1;
                if(v < 1) v = 1;
                return v;
            };
            auto fy = [&](int v) {
                if(v > m) v = m+1;
                if(v < 1) v = 1;
                return v;
            };
            for(int j = 1; j <= m; ++j) {
                if(inp[j] == 'S') {
                    qs[fx(i-d)][fy(j-d)]++;
                    qs[fx(i+d+1)][fy(j-d)]--;
                    qs[fx(i-d)][fy(j+d+1)]--;
                    qs[fx(i+d+1)][fy(j+d+1)]++;
                }
                if(inp[j] == 'M') vec.emplace_back(i, j);
            }
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
            }
        }
        for(auto v : vec) {
            int x, y; tie(x, y) = v;
            if(qs[x][y] >= k) ans++;
        }
        cout << ans << endl;
    }
};