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

int n, m, A[MAXN];
long t[MAXN<<1], lz[MAXN<<1];

void build(int p = 1, int l = 1, int r = n) {
	if(l == r) {
		t[p] = A[l];
		return;
	}
	int m = (l + r) >> 1;
	build(p<<1, l, m), build(p<<1|1, m+1, r);
	t[p] = t[p<<1] + t[p<<1|1];
}

template<typename T>
void travel(int x, int y, const T &f, int p = 1, int l = 1, int r = n) {
	if(lz[p]) {
		t[p] ^= lz[p];
		if(l != r) {
			lz[p<<1] ^= lz[p];
			lz[p<<1|1] ^= lz[p];
		}
		lz[p] = 0;
	}
	if(x <= l && r <= y) return f(p, l, r);
	if(x > r || l > y) return;
	int m = (l + r) >> 1;
	travel(x, y, f, p<<1, l, m), travel(x, y, f, p<<1|1, m+1, r);
	t[p] = t[p<<1] + t[p<<1|1];
}

void update(int x,int y, int v) {
	travel(x, y, [&](int p, int l, int r) {
		t[p] ^= v;
		if(l != r) {
			lz[p<<1] ^= v;
			lz[p<<1|1] ^= v;
		}
	});
}

long query(int x, int y) {
	long sum = 0;
	travel(x, y, [&](int p, int l, int r){
		sum += t[p];
	});
	return sum;
}

int main() {
	red();
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i);
	build();
	scanf("%d", &m);
	while(m--) {
		int met;
		scanf("%d", &met);
		if(met == 1) {
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%lld\n", query(a, b));
		} else {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			update(a, b, c);
		}
	}
}