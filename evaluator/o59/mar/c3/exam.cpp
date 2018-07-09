#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 5e4 + 5;

int n, A[MAXN], m, t[MAXN<<1], ans[500005];
vector<pii> que[MAXN];
void upd(int x, int v) { for(t[x+=n] += v; x != 1; x >>= 1) t[x>>1] = t[x] + t[x^1]; }
int query(int l, int r) {
	int sum = 0;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if(l & 1) sum += t[l++];
		if(r & 1) sum += t[--r];
	}
	return sum;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", A+i);
	scanf("%d", &m);
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		que[b].emplace_back(a, i);
	}
	map<int, int> M;
	for(int i = 0; i < n; ++i) {
		if(M.find(A[i]) != M.end()) upd(M[A[i]], -1);
		M[A[i]] = i; upd(i, 1);
		for(auto x : que[i]) ans[x.y] = i - x.x + 1 - query(x.x, i);
	}
	for(int i = 0; i < m; ++i) printf("%d\n", ans[i]);
}