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


class topovi {
private:
    int n, k, p;
    long sum = 0;
    map<int, int> fx, fy, vx, vy;
    map<pii, int> data;
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> k >> p;
        fx[0] = fy[0] = n;
        for(int i = 0, x, y, v; i < k; ++i) {
            cin >> x >> y >> v;
            sum -= n - fy[vx[x]] + n - fx[vy[y]];
            fx[vx[x]]--, fy[vy[y]]--;
            data[pii(x, y)] = v;
            fx[vx[x] ^= v]++, fy[vy[y] ^= v]++;
            sum += n - fy[vx[x]] + n - fx[vy[y]];
        }
        for(int i = 0, x, y; i < p; ++i) {
            cin >> x >> y;
            sum -= n - fy[vx[x]] + n - fx[vy[y]];
            fx[vx[x]]--, fy[vy[y]]--;
            int v = data[pii(x, y)];
            fx[vx[x] ^= v]++, fy[vy[y] ^= v]++;
            sum += n - fy[vx[x]] + n - fx[vy[y]];
            cin >> x >> y;
            sum -= n - fy[vx[x]] + n - fx[vy[y]];
            fx[vx[x]]--, fy[vy[y]]--;
            data[pii(x, y)] = v;
            fx[vx[x] ^= v]++, fy[vy[y] ^= v]++;
            sum += n - fy[vx[x]] + n - fx[vy[y]];
            cout << sum << endl;
        }
    }
};