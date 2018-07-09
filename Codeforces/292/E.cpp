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

const int MAXN = 1<<17;

int n, m, A[MAXN], B[MAXN], t[MAXN<<1], lz[MAXN<<1];

void update(int x, int y, int v, int p = 1, int l = 1, int r = n) {
	if(lz[p]) {
		t[p] = lz[p];
		if(l != r) {
			lz[p<<1] = lz[p];
			lz[p<<1|1] = lz[p];
		}
		lz[p] = 0;
	}
	if(x <= l && r <= y) {
		t[p] = v;
		if(l != r) {
			lz[p<<1] = v;
			lz[p<<1|1] = v;
		}
		return;
	}
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	update(x, y, v, p<<1, l, m), update(x, y, v, p<<1|1, m+1, r);
}

int query(int x, int p = 1, int l = 1, int r = n) {
	if(lz[p]) {
		t[p] = lz[p];
		if(l != r) {
			lz[p<<1] = lz[p];
			lz[p<<1|1] = lz[p];
		}
		lz[p] = 0;
	}
	if(l == r) return t[p];
	int m = (l + r) >> 1;
	if(x <= m) return query(x, p<<1, l, m);
	return query(x, p<<1|1, m+1, r);
}

vector<P> V;

int f(int x, int ver) {
	if(ver == 0) return B[x];
	return A[V[ver].x + x-V[ver].y];
}

int main() {
	V.emplace_back(0, 0);
	red();
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	for(int i = 1; i <= n; ++i) scanf("%d", B+i);	
	while(m--) {
		int met; scanf("%d", &met);
		if(met == 2) {
			int x;
			scanf("%d", &x);
			printf("%d\n", f(x, query(x)));
		} else {
			int x, y, k;
			scanf("%d %d %d", &x, &y, &k);
			update(y, y+k-1, V.size());
			V.emplace_back(x, y);
		}
	}
}