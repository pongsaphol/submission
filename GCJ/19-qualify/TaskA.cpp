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


class TaskA {
private:
    string str;
    pair<string, string> solve() {
        string a, b;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] == '4') {
                a.push_back('2'), b.push_back('2');
            } else {
                a.push_back(str[i]);
                if(b.size()) b.push_back('0');
            }
        }
        return make_pair(a, b);
    }
public:
    void solve(istream& cin, ostream& cout) {
        int T; cin >> T;
        for(int tc = 1; tc <= T; ++tc) {
            cin >> str;
            pair<string, string> z = solve();
            cout << "Case #" << tc << ": " << z.x << ' ' << z.y << endl;
        }
    }
};