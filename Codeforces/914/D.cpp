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

const int MAXN = 1<<19;

int n, A[MAXN], t[MAXN<<1];

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p] = A[l];
		return;
	}
	int m = (l + r) >> 1;
	build(p<<1, l, m), build(p<<1|1, m+1, r);
	t[p] = __gcd(t[p<<1], t[p<<1|1]);
}

void update(int x, int v, int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p] = v;
		return;
	}
	int m = (l + r) >> 1;
	if(x <= m) update(x, v, p<<1, l, m);
	else update(x, v, p<<1|1, m+1, r);
	t[p] = __gcd(t[p<<1], t[p<<1|1]);
}

int query(int x, int y, int p = 1, int l = 1, int r = n) {
	if(x <= l && r <= y) return t[p];
	if(r < x || y < l) return -1;
	int m = (l + r) >> 1;
	int a = query(x, y, p<<1, l, m);
	int b = query(x, y, p<<1|1, m+1, r);
	if(a == -1) return b;
	if(b == -1) return a;
	return __gcd(a, b);
}

int gcd, d, dd;

bool bs(int x, int p = 1, int l = 1, int r = n) {
	// printf("->%d %d\n", l, r);
	if(x > r) return true;
	if(x <= l) {
		if(gcd == -1 && t[p]%d == 0) {
			gcd = t[p], dd = r;
			return true;
		} else if(__gcd(t[p], gcd)%d == 0) {
			gcd = __gcd(t[p], gcd), dd = r;
			return true;
		}
	}
	if(l == r) return false;
	int m = (l + r) >> 1;
	bool st = bs(x, p<<1, l, m);
	// printf("%d %d %d\n", st, l, r);
	if(st) st = bs(x, p<<1|1, m+1, r);
	return st;
}

int main() {
	red();
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	build();

	int m;
	scanf("%d", &m);
	while(m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		// cout << "->"<<query(1, 2) << endl;
		// cout << a <<b <<c<< endl;
		if(a == 1) {
			scanf("%d", &d);
			gcd = -1;
			dd = b-1;
			bs(b);
			// cout << dd << endl;

			if(dd + 1 >= c) puts("YES");
			else if(query(dd+2, c)%d == 0) puts("YES");
			else puts("NO");
		} else update(b, c);
	}
}	