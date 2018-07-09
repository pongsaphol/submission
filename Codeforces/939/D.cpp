#include <bits/stdc++.h>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e5 + 5;

int n, par[128];
char A[MAXN], B[MAXN];

int find(int u) {
	if(par[u] == 0) return u;
	return par[u] = find(par[u]);
}

bool u(int a, int b) {
	a = find(a), b = find(b);
	if(a == b) return false;
	par[a] = b;
	return true;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	scanf("%s %s", A, B);
	vector<P> ans;
	for(int i = 0; i < n; ++i) if(u(A[i], B[i])) ans.emplace_back(A[i], B[i]);
	printf("%d\n", ans.size());
	for(auto x : ans) printf("%c %c\n", x.x, x.y);
}