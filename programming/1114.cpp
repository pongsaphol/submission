#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

const int MAXN = 305;
vector<P> g[MAXN<<1];
int n, d[MAXN<<1];

void read() {
	scanf("%d", &n);
	for(int i = 1; i <= 2*n; ++i) {
		for(int j = 1; j <= 2*n; ++j) {
			int now;
			scanf("%d", &now);
			if(j == 1 || i-j <= 0) continue;
			g[i].push_back({j, now});
		}
	}
}

void dijkstra() {
	d[2*n] = 0;
 	priority_queue<P, vector<P>, greater<P> > Q;
 	Q.push({0, 2*n});
 	while(!Q.empty()) {
 		auto now = Q.top();
 		Q.pop();
 		if(now.x != d[now.y]) continue;
 		int u = now.y;
 		for(auto x:g[u]) {
 			int v = x.x, w = x.y;
 			if(d[v] > d[u] + w) {
 				d[v] = d[u] + w;
 				Q.push({d[v], v});
 			}
 		}
 	}
}

int solve() {
	fill(d, d+(MAXN<<1), 1e9);
	dijkstra();
	return d[2];
}

int main() {
	// freopen("r", "r", stdin);
	read();	
	printf("%d\n", solve());
}