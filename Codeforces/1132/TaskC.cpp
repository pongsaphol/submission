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

const int N = 5e3+5;

class TaskC {
private:
    int n, m, ans;
    int d[N];
    int z1[N];
    int z2[N];
    vector<pii> vec;
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> m;
        for(int i = 0, a, b; i < m; ++i) {
            cin >> a >> b;
            vec.emplace_back(a, b);
            d[a]++, d[b+1]--;
        }
        for(int i = 1; i <= n; ++i) d[i] += d[i-1];
        sort(all(vec));
        for(int i = 1; i <= n; ++i) z1[i] = z1[i-1] + (d[i] == 1);
        for(int i = 1; i <= n; ++i) z2[i] = z2[i-1] + (d[i] == 2);
        int sum = 0;
        for(int i = 1; i <= n; ++i) sum += (d[i] ? 1 : 0);
        for(int i = 0; i < m; ++i) for(int j = i+1; j < m; ++j) {
            int del = z1[vec[i].y] - z1[vec[i].x-1] + z1[vec[j].y] - z1[vec[j].x-1];
            if(vec[i].y >= vec[j].x) del += z2[vec[i].y] - z2[vec[j].x-1];
            ans = max(ans, sum - del);
        }
        cout << ans << endl;
    }
};