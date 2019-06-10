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


class TaskB {
private:
    int n, k;
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n >> k;
        int div = (n-k)/2;
        int z = div+1;
        cerr << z << endl;
        for(int i = 0; i < n; ++i) {
            if(i % z == div) cout << 1;
            else cout << 0;
        }
    }
};