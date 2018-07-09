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

struct { int d, l, r; } t[50*MAXN];
int n, ver[MAXN], A[MAXN], pv[MAXN], cv, ptr; 

int build(int p, int l = 1, int r = n) {
	if(l == r) return p;
	int m = (l + r) >> 1;
	t[p].l = build(++ptr, l, m);
	t[p].r = build(++ptr, m+1, r);
}

int update(int x, int v, int p, int l = 1, int r = n) {
	t[++ptr] = t[p];
	p = ptr;
	if(l == r) t[p].d = v;
	else {
		int m = (l + r) >> 1;
		if(x <= m) t[p].l = update(x, v, t[p].l, l, m);
		else t[p].r = update(x, v, t[p].r, m+1, r);
		t[p].d = t[t[p].l].d + t[t[p].r].d;
	}
	return p;
}

int query(int v, int p, int l = 1, int r = n) {
	// printf("%d %d %d\n", l, r, v);
	if(l == r) 
		if(v - t[p].d == 0) return l;
		else return 0;
	int m = (l + r) >> 1;
	int zz = (t[t[p].r].d);
	if(zz < v) return query(v-zz, t[p].l, l, m);
	return query(v, t[p].r, m+1, r);
}

int main() {
	red();
	scanf("%d", &n);
	int pf = build(++ptr);
	for(int i = 1; i <= n; ++i) {
		int now;
		scanf("%d", &now);
		if(pv[now] != 0) pf = update(pv[now], 0, pf);
		pv[now] = i;
		A[i] = pf = update(pv[now], 1, pf);
	}
	for(int i = 1; i <= n; ++i) {
		int cc = 0, p = n;
		while(p != 0) {
			p = query(i+1, A[p]);
			cc++;
		}
		printf("%d ", cc);
	}
}