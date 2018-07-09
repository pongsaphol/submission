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

const int lp = 17;
const int MAXN = 1 << lp;

int n, m, sz, ver[MAXN], A[MAXN], rA[MAXN], ptr;

struct T{ int d, l, r; } t[MAXN + lp*MAXN];

int build(int p, int l = 1, int r = sz) {
	if(l == r) return p;
	int m = (l + r) >> 1;
	t[p].l = build(++ptr, l, m);
	t[p].r = build(++ptr, m+1, r);
	return p;
}

int update(int x, int p, int l = 1, int r = sz) {
	t[++ptr] = t[p];
	p = ptr;
	if(l == r) {
		t[p].d++;
	} else {
		int m = (l + r) >> 1;
		if(x <= m) t[p].l = update(x, t[p].l, l, m);
		else t[p].r = update(x, t[p].r, m+1, r);
		t[p].d = t[t[p].l].d + t[t[p].r].d;
	}
	return p;
}

int qn(int x, int p, int l = 1, int r = sz) {
	if(l == r) return t[p].d;
	int m = (l + r) >> 1;
	if(x <= m) return qn(x, t[p].l, l, m);
	return qn(x, t[p].r, m+1, r);
}

int query(int p1, int p2, int k, int l = 1, int r = sz) {
	if(l == r) return l;
	int m = (l + r) >> 1;
	int v = t[t[p2].r].d - t[t[p1].r].d;
	if(v >= k) return query(t[p1].r, t[p2].r, k, m+1, r);
	else return query(t[p1].l, t[p2].l, k-v, l, m); 
}

int main() {
	red();
	scanf("%d %d", &n, &m);
	set<int> S;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A + i);
		S.emplace(A[i]);
	}
	map<int, int> M;
	int idx = 0;
	for(auto x:S) M[x] = ++idx, rA[idx] = x;
	sz = S.size();
	ver[0] = build(++ptr);
	for(int i = 1; i <= n; ++i) ver[i] = update(M[A[i]], ver[i-1]);
	while(m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", rA[query(ver[a-1], ver[b], c)]);
	}
}