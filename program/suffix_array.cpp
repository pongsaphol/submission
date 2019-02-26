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

const int N = 5e4+5;

class suffix_array {
private:
    int n, pos[N], ret[N], idx;
    char A[N];
    vector<pair<pii, int>> vec;
    void cmpidx() {
        sort(all(vec));
        idx = ret[0] = 1;
        for(int i = 1; i < n; ++i) ret[i] = idx += (vec[i].x != vec[i-1].x);
        for(int i = 0; i < n; ++i) pos[vec[i].y] = vec[i].x.x = ret[i];
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> A;
        n = strlen(A);
        for(int i = 0; i < n; ++i) vec.emplace_back(pii(A[i], 0), i);
        cmpidx();
        for(int i = 1; i < n; i <<= 1) {
            for(int j = 0; j < n; ++j) vec[j].x.y = pos[vec[j].y+i >= n ? n : vec[j].y+i];
            cmpidx();
        }
        for(int i = 0; i < n; ++i) cout << pos[i] << endl;
    }
};