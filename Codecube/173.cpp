#include <bits/stdc++.h>
#define long long long
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
int n, m, par[MAXN], A[MAXN], deg[MAXN];
bool chk[MAXN];

int find(int u) {
	if(par[u] == u) return u;
	return par[u] = find(par[u]);
}

bool uni(int a, int b) {
	a = find(a), b = find(b);
	if(a == b) return false;
	par[a] = b;
	return true;
}

struct data {
	int u, v, w;
	data(int a, int b, int c) {u = a, v = b, w = c;}
	friend inline bool operator<(const data &a, const data &b) {
		return a.w > b.w;
	}
};

int main() {
	// freopen("r", "r", stdin);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		par[i] = i;
		scanf("%d", A+i);
	}
	vector<data> V;
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		V.emplace_back(a, b, A[a] + A[b]);
	}
	sort(all(V));
	long sum = 0;
	for(auto x : V) if(uni(x.u, x.v)) sum += x.w;
	printf("%lld\n", sum);
}