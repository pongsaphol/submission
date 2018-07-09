#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define mem(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
#ifdef INPUT
#define dbg(x) cout << "debug : " <<  x << endl
#define dbg2(x, xx) cout << "debug : " << x << " : " << xx << endl 
#else
#define dbg(x)
#define dbg2(x, xx)
#endif
using namespace __gnu_pbds;
using namespace std;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.tie(0);
	cin.sync_with_stdio(false);
}

struct data {
	int u, v, d, t;
	friend inline bool operator<(const data &a, const data &b) {
		return a.d < b.d;
	}
};

struct edge {
	int v, w, idx;
};

const int MAXN = 1e5+5, inf = 1e9+1;

int n, m, k, t, d[MAXN];
vector<data> V;
vector<edge> g[MAXN];

bool dijk(int M) {
	fill(d, d+MAXN, inf);
	d[1] = 0;
	priority_queue<P, vector<P>, greater<P> > Q;
	Q.push({d[1], 1});
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		if(now.x != d[now.y]) continue;
		int u = now.y;
		for(auto x:g[u]) if(x.idx <= M) {
			if(d[x.v] > d[u] + x.w) {
				d[x.v] = d[u] + x.w;
				Q.push({d[x.v], x.v});
			}
		}
	}
	return d[n] <= t;
}

int main() {
	red();
	scanf("%d%d%d%d", &n, &m, &k, &t);
	for(int i = 1; i <= m; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		V.push_back({a, b, c, d});
	}
	sort(all(V));
	for(int i = 0; i < V.size(); ++i) {
		auto &x = V[i];
		g[x.u].push_back({x.v, x.t, i});
		g[x.v].push_back({x.u, x.t, i});
	}
	int L = 0, R = m-1;
	while(L < R) {
		int mid = (L+R)/2;
		if(dijk(mid)) R = mid;
		else L = mid+1;
	}
	if(!dijk(R)) return !printf("-1\n");
	int now = V[R].d;
	int mn = inf;
	vector<P> ret;
	while(k--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(b >= now) mn = min(mn, a);
	}
	if(mn == inf) return !printf("-1\n");
	printf("%d\n", mn);
}