#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
}

const int inf = 1e9;

int a, b, mn, A[205], mt[205][205];
vector<int> g[205];
vector<P> now;
bool chk[205];

void init() {
	mn = inf;
	memset(mt, 0, sizeof mt);
	now.clear();
	memset(chk, 0, sizeof chk);
	memset(A, 0, sizeof A);
	for(int i = 0; i < 205; ++i) g[i].clear();
}

bool dfs(int u) {
	if(u == a+b+1) return true;
	chk[u] = true;
	for(auto v:g[u]) if(mt[u][v] && !chk[v]) if(dfs(v)) {
		mn = min(mn, mt[u][v]);
		now.emplace_back(u, v);
		return true;
	}
	return false;
}

void solve() {
	init();
	scanf("%d", &a);
	for(int i = 1; i <= a; ++i) {
		scanf("%d", A+i);
		g[0].emplace_back(i);
		g[i].emplace_back(0);
		mt[0][i] = 1;
	}
	scanf("%d", &b);
	for(int j = a+1; j <= a+b; ++j) {
		scanf("%d", A+j);
		g[a+b+1].emplace_back(j);
		g[j].emplace_back(a+b+1);
		mt[j][a+b+1] = 1;
	}
	for(int i = 1; i <= a; ++i) for(int j = a+1; j <= a+b; ++j) {
		if((A[i] == 0 && A[j] == 0) || (A[i] != 0 && ((abs(A[j]) % abs(A[i])) == 0))) {
			g[i].emplace_back(j);
			g[j].emplace_back(i);
			mt[i][j] = 1;
		}
	}
	int sum = 0;
	while(dfs(0)) {
		sum += mn;
		for(auto E:now) mt[E.x][E.y] -= mn, mt[E.y][E.x] += mn;
		mn = inf;
		now.clear();
		memset(chk, 0, sizeof chk);
	}
	printf("%d\n", sum);
}

int main() {
	red();
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
		printf("Case %d: ", i);
		solve();
	}
}