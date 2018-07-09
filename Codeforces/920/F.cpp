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

int n, m, A[MAXN], S[MAXN<<1];
long t[MAXN<<1];
bool chk[MAXN<<1];

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p] = A[l];
		return;
	}
	int m = (l + r) >> 1;
	build(p<<1, l, m), build(p<<1|1, m+1, r);
	t[p] = t[p<<1] + t[p<<1|1];
}

void update(int x, int y, int p = 1, int l = 1, int r = n) {
	if(x > r || l > y) return;
	if(x <= l && r <= y && chk[p]) return;
	if(l == r) {
		t[p] = S[t[p]];
		if(t[p] <= 2) chk[p] = true;
		return;
	}
	int m = (l + r) >> 1;
	update(x, y, p<<1, l, m), update(x, y, p<<1|1, m+1, r);
	t[p] = t[p<<1] + t[p<<1|1];
	chk[p] = chk[p<<1] && chk[p<<1|1];
}

long query(int x, int y, int p = 1, int l = 1, int r = n) {
	if(x <= l && r <= y) return t[p];
	if(x > r || l > y) return 0;
	int m = (l + r) >> 1;
	return query(x, y, p<<1, l, m) + query(x, y, p<<1|1, m+1, r);
}

int main() {
	red();
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= 1000000; ++i) for(int j = i; j <= 1000000; j += i) S[j]++;
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	build();
	while(m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a == 1) update(b, c);
		else printf("%lld\n", query(b, c));
	}
}