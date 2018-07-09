#include <bits/stdc++.h>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e5 + 5;

int n, m, A[MAXN], ans[MAXN], t[MAXN<<1];
P pv[MAXN];
vector<P> ret[MAXN];
queue<int> Q[MAXN];

void update(int i, int v) {
	for(t[i += n+1] = v; i != 1; i >>= 1) t[i>>1] = t[i] + t[i^1];
}

int query(int l, int r) {
	int sum = 0;
	for(l += n+1, r += n+2; l < r; l >>= 1, r >>= 1) {
		if(l&1) sum += t[l++];
		if(r&1) sum += t[--r];
	}
	return sum;
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A + i);
		if(A[i] > 100000) A[i] = 100001;
	}
	for(int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ret[b].emplace_back(a, i);
	}
	for(int i = 1; i <= n; ++i) {
		Q[A[i]].push(i);
		if(Q[A[i]].size() == A[i]) {
			update(pv[A[i]].y, 0);
			pv[A[i]].y = pv[A[i]].x;
			pv[A[i]].x = Q[A[i]].front();
			Q[A[i]].pop();
			update(pv[A[i]].x, 1);
			update(pv[A[i]].y, -1);
		}
		for(auto x : ret[i]) ans[x.y] = query(x.x, i);
	}
	for(int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
}