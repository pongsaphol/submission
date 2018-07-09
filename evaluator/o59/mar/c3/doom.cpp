#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int X[] = {0, 0, 1, -1}, Y[] = {-1, 1, 0, 0};
int n, m, k, md[33][33], d[105][105], dp[35][1<<15];
char A[105][105];

struct data {
	int w, u, p;
	data(int w, int u, int p) : w(w), u(u), p(p) { }
	friend inline bool operator<(const data &a, const data &b) {
		return a.w > b.w;
	}
};

int idx(int x) {
	if(x == '.') return -1;
	if(x == 'z') return 0;
	if(x == 'Z') return 1;
	if(x >= 'a') return x-'a'+2;
	return x-'A'+2+k;
}

void bfs(int x, int y) {
	queue<pii> Q;
	Q.emplace(x, y);
	int z = idx(A[x][y]);
	md[z][z] = 0;
	int d[105][105];
	fill(d[0], d[101] + 101, 1000000);
	::d[z][z] = 0;
	d[x][y] = 0;
	while(!Q.empty()) {
		auto u = Q.front(); Q.pop();
		for(int i = 0; i < 4; ++i) {
			int x = u.x + X[i], y = u.y + Y[i];
			if(x < 1 || x > n || y < 1 || y > m || A[x][y] == '#') continue; 
			if(d[x][y] > d[u.x][u.y] + 1) {
				d[x][y] = d[u.x][u.y] + 1;
				if(idx(A[x][y]) != -1) ::d[z][idx(A[x][y])] = d[x][y];
				else Q.emplace(x, y);
			}
		}
	}
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	fill(d[0], d[32]+32, 1000000);
	fill(dp[0], dp[33] + (1<<15), 1000000);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) scanf("%s", A[i] + 1);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) 
		if(A[i][j] != '.' and A[i][j] != '#') bfs(i, j);
	priority_queue<data> Q; int pth = 2*k + 2;
	dp[0][0] = 0;
	Q.emplace(dp[0][0], 0, 0);
	while(!Q.empty()) {
		auto u = Q.top(); Q.pop();
		if(u.u == 1) return !printf("%d\n", u.w); 
		if(u.w != dp[u.u][u.p]) continue;
		for(int i = 0; i < pth; ++i) {
			int v = i, p = u.p, w = u.w + d[u.u][i];
			if(i > 1) {
				if(i <= k+1) p |= (1 << (i-2));
				if(i > k+1) {
					if(!(p&(1<<(i-k-2)))) continue;
				}
				if(dp[v][p] > w) {
					dp[v][p] = w;
					Q.emplace(dp[v][p], v, p);
				}
			} else {
				if(dp[v][p] > w) {
					dp[v][p] = w;
					Q.emplace(dp[v][p], v, p);
				}
			}
		}
	}
	puts("-1");
}