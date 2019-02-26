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

const int N = 3e5+5;

class Stogovi {
private:
    int n, step;
    int pos[N], val[N], par[N][18], dep[N];
    int get_lca(int a, int b) {
        if(dep[a] < dep[b]) swap(a, b);
        for(int i = 17; ~i; --i) if(dep[par[a][i]] >= dep[b]) a = par[a][i];
        if(a == b) return a;
        for(int i = 17; ~i; --i) if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
        return par[a][0];
    }
public:
    void solve(istream& cin, ostream& cout) {
        cin >> n;
        for(int i = 1, a, b; i <= n; ++i) {
            char c; cin >> c >> a;
            if(c == 'a') {
                val[pos[i] = ++step] = i;
                dep[pos[i]] = dep[pos[a]]+1;
                par[pos[i]][0] = pos[a];
                for(int j = 1; j < 18; ++j) par[pos[i]][j] = par[par[pos[i]][j-1]][j-1];
            } else if(c == 'b') {
                cout << val[pos[a]] << endl;
                pos[i] = par[pos[a]][0];
            } else {
                cin >> b;
                pos[i] = pos[a];
                cout << dep[get_lca(pos[a], pos[b])] << endl;
            }
        }
    }
};