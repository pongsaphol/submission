#include <bits/stdc++.h>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e6 + 5;

int n, m, A[MAXN], pref[MAXN], t[MAXN];
vector<P> ret[MAXN];

void update(int x, int v) {
	for(int i = x; i != 0; i -= i&-i) t[i] ^= v;
}

int query(int x) {
	if(!x) return 0;
	int v = 0;
	for(int i = x; i <= n; i += i&-i) v ^= t[i];
	return v;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", A + i), pref[i] = pref[i-1] ^ A[i];
	scanf("%d", &m);
	vector<int> ans(m);
	for(int i = 0; i < m; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		ret[b].emplace_back(a, i);
	}
	map<int, int> M;
	for(int i = 1; i <= n; ++i) {
		if(M[A[i]]) update(M[A[i]], A[i]);
		update(i, A[i]);
		M[A[i]] = i;
		for(auto x : ret[i]) ans[x.y] = pref[i] ^ pref[x.x-1] ^ query(x.x);
	}
	for(auto x : ans) printf("%d\n", x);
}