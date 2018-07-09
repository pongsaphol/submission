#include <bits/stdc++.h>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e6+5;

int n, m, ans[MAXN], t[MAXN<<1];
char A[MAXN];
vector<P> ret[MAXN];

void update(int x) {
	for(t[x += n+1] = 2; x != 1; x >>= 1) t[x>>1] = t[x] + t[x^1];
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
	scanf("%s", A + 1);
	n = strlen(A + 1);
	stack<int> S;
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ret[b].emplace_back(a, i);
	}
	for(int i = 1; i <= n; ++i) {
		if(A[i] == '(') S.emplace(i);
		else if(!S.empty()) {
			update(S.top());
			S.pop();
		}
		for(auto x : ret[i]) ans[x.y] = query(x.x, i);
	}
	for(int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
}