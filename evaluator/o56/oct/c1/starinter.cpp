/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author win11905
 */

#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
#define mem(x) memset(x, 0, sizeof x)
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
const long LINF = 1e18 + 1e16;
const int MOD = 1e9+7;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};


class starinter {
private:
	int n, k;
	long ans = 0;
	vector<vector<pii> > g;
	vector<int> t;
	vector<int> coor;
	void update(int x, int v = 1) {
		for(int i = x+1; i <= coor.size(); i += i & -i) t[i-1] += v;
	}
	int query(int x, int v = 0) {
		for(int i = x+1; i > 0; i -= i & -i) v += t[i-1];
		return v;
	}
	void dfs_fill(int u, int p, int dis, int state) {
       	if(state == 0) coor.emplace_back(dis);
       	if(state == 1) ans += query(upper_bound(all(coor), k - dis) - coor.begin() - 1);
       	if(state == 2) update(lower_bound(all(coor), dis) - coor.begin());
       	if(state == 3) {
			ans += query(coor.size()-1) - query(lower_bound(all(coor), dis - k) - coor.begin() - 1);
			update(lower_bound(all(coor), dis) - coor.begin());
       	}
       	if(state == 4) update(lower_bound(all(coor), dis) - coor.begin(), -1);
       	for(pii v : g[u]) if(v.x != p) dfs_fill(v.x, u, dis + v.y, state);
	}
public:
	void solve(istream& cin, ostream& cout) {
		cin >> n >> k;
		g.resize(n+1);
		for(int i = 1, u, v, w; i < n; ++i) {
			cin >> u >> v >> w;
			g[u].emplace_back(v, w);
			g[v].emplace_back(u, w);
		}
		int start = 1;
		coor.emplace_back(0);
		for(int i = 1; i <= n; ++i) if(g[i].size() > 2) start = i;
		for(pii v : g[start]) dfs_fill(v.x, start, v.y, 0);
		sort(all(coor)), coor.resize(unique(all(coor)) - coor.begin());
		t.resize(coor.size()), update(0);
		for(pii v : g[start]) {
			dfs_fill(v.x, start, v.y, 1);
			dfs_fill(v.x, start, v.y, 2);
		}
		t.clear(), t.resize(coor.size());
		for(pii v : g[start]) {
			dfs_fill(v.x, start, v.y, 3);
			dfs_fill(v.x, start, v.y, 4);
		}
		cout << ans << endl;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	starinter solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}