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

class TaskC {
private:
    int n, sx, sy, tx, ty;
    int px[N], py[N];
    char inp[N];
public:
    void solve(istream& cin, ostream& cout) {
        cin >> sx >> sy >> tx >> ty;
        int x = sx - tx, y = sy - ty;
        cin >> n; cin >> inp+1;
        for(int i = 1; i <= n; ++i) {
            px[i] = px[i-1], py[i] = py[i-1];
            if(inp[i] == 'U') py[i]++;
            if(inp[i] == 'D') py[i]--;
            if(inp[i] == 'L') px[i]--;
            if(inp[i] == 'R') px[i]++;
        }
        int l = 0, r = INF;
        while(l < r) {
            long m = l + r >> 1;
            bool st = false;
            if(n * m >= abs(x + px[n] * m) + abs(y + py[n] * m)) st = true;
            for(int i = 1; i <= n; ++i) {
                if(n * m + i >= abs(x + px[n] * m + px[i]) + abs(y + py[n] * m + py[i])) st = true;
            }
            if(st) r = m;
            else l = m + 1;
        }
        if(r == INF) cout << "-1" << endl;
        else {
            long m = r;
            if(n * m >= abs(x + px[n] * m) + abs(y + py[n] * m)) cout << n * m;
            else for(int i = 1; i <= n; ++i) {
                if(n * m + i >= abs(x + px[n] * m + px[i]) + abs(y + py[n] * m + py[i])) {
                    cout << n * m + i << endl;
                    break;
                }
            }
        }
    }
};