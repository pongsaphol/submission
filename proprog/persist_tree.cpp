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

const int MAXN = 1e5+5;

int n, m, q, A[MAXN];

struct segT {
	struct T { int d, l, r; };	
	T t[MAXN<<2];
	int ptr = 0, ver[MAXN] = {}, cc = 0;

	void build(int p, int l = 1, int r = n) {
		if(l == r) {
			t[p].d = A[l];
			return;
		}
		int m = (l + r) >> 1;
		t[p].l = ++ptr, t[p].r = ++ptr;
		build(t[p].l, l, m), build(t[p].r, m+1, r);
		t[p].d = t[t[p].l].d + t[t[p].r].d;
	}

	void init() {
		ver[0] = ++ptr;
		build(ptr);
	}

	void update(int x, int v, int p, int l = 1, int r = n) {
		if(l == r) {
			t[p].d += v;
			return;
		}
		int m = (l + r) >> 1;
		if(x <= m) {
			t[++ptr] = t[t[p].l], t[p].l = ptr;
			update(x, v, ptr, l, m);
		} else {
			t[++ptr] = t[t[p].r], t[p].r = ptr;
			update(x, v, ptr, m+1, r);
		}
		t[p].d = t[t[p].l].d + t[t[p].r].d;
	}

	int query(int x, int y, int p, int l = 1, int r = n) {
		if(x <= l && r <= y) return t[p].d;
		if(x > r || l > y) return 0;
		int m = (l + r) >> 1;
		return query(x, y, t[p].l, l, m) + query(x, y, t[p].r, m+1, r);
	} 

	void upd(int x, int v) {
		t[++ptr] = t[ver[cc]];
		ver[++cc] = ptr;
		update(x, v, ptr);
	}

	int que(int x, int y, int v) {
		return query(x, y, ver[v]);
	}
} t;


int main() {
	red();
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++i) A[i] = input();
	t.init();
	for(int i = 0; i < m; ++i) {
		int a = input(), b = input();
		t.upd(a, b);
	}
	int k = 0;
	m++;
	while(q--) {
		int a = input(), b = input();
		int ret = t.que(a, b, k);
		k = ((ret%m)+m)%m;
		cout << ret << endl;
	}
}