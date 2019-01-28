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


class lightningrod {
private:
    int n;
    stack<pii> stk;
    bool check_cover(pii a, pii b) {
        return abs(a.x - b.x) <= a.y - b.y;
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        vector<pii> vec;
        for(int i = 0, a, b; i < n; ++i) {
            cin >> a >> b;
            vec.emplace_back(a, b);
        }
        for(auto v : vec) {
            if(stk.empty()) {
                stk.emplace(v);
                continue;
            }
            if(check_cover(stk.top(), v)) continue;
            while(!stk.empty() && check_cover(v, stk.top())) stk.pop();
            stk.emplace(v);
        }
        cout << stk.size() << endl;
    }
};