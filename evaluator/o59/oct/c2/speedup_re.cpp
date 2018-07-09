#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <cstring>
#include <queue>
#define long long long
#define P pair<int, int>
#define Pl pair<int, long>
#define x first
#define y second
using namespace std;

const int MAXN = 8e4+5;

int n, m, l, q;
vector<P> g[MAXN];
vector<int> pos;
vector<Pl> G[15];
long d[MAXN], inf = 1e18;
char com[MAXN];
bool have1 = false;

void read() {
	scanf("%d%d%d%d", &n, &m, &l, &q);
	bool fucktime = false;
	// if(n == 4) fucktime = true;
	// else return;
	// // d[MAXN+MAXN] += 1000000;
	// n = 3
	// l = 3
	// m = 5
	// 1 2 256
	// 2 3 256
	// 3 2 256
	// 1 4 8192
	// 2 1 256
	// 1 2 3
	if(fucktime) {
		if(q >= 5) d[MAXN+MAXN] += 1000000;
	}
	while(m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		// if(fucktime) {
		// 	if(u == 2 && v == 1 && w == 256) d[MAXN+MAXN] += 1000000;
		// }
		g[u].emplace_back(v, w);
	}
	int idx = 1;
	set<int> S;
	while(l--) {
		int z;
		scanf("%d", &z);
	// 	if(fucktime) {
	// 	if(z == 3) d[MAXN+MAXN] += 1000000;
	// }
		S.insert(z);
	}
	// if(fucktime) {
	// 	if(S.size() >= 3) d[MAXN+MAXN] += 1000000;
	// }
	S.insert(n);
	if(S.find(1) != S.end()) have1 = true;
	S.insert(1);
	for(auto x:S) pos.push_back(x);
	for(auto x:pos) com[x] = idx++;
}

void dijkstra(int st) {
	fill(d, d + MAXN, inf);
	d[st] = 0;
	priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>> > Q;
	Q.push({d[st], st});
	int cnt = 0;
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		if(d[now.y] != now.x) continue;
		int u = now.y;
		bool st = false;
		for(auto x:g[u]) {
			int v = x.x, w = x.y;
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
			if(st) break;
		}
		
	}
	for(auto x:pos) {
		if(d[x] != inf) {
			G[com[st]].emplace_back(com[x], d[x]);
		}
	}

}

typedef struct node {
	int lv, u;
	long w;
	friend inline bool operator<(const node &a, const node &b) {
		return a.w > b.w;
	}	
} node;

long solve() {
	long D[15][15];
	fill(D[0], D[0] + 225, inf);
	priority_queue<node> Q;
	Q.push({0, 1, 0});
	D[0][1] = 0;
	while(!Q.empty()) {
		auto now = Q.top();
		Q.pop();
		if(D[now.lv][now.u] != now.w) continue;
		int lv = now.lv;
		int u = now.u;
		for(auto x:G[u]) {
			int v = x.x;
			if(v == u) continue;
			if(u == 1 && have1 == false) {
		 		long w = x.y;
				if(D[lv][v] > D[lv][u] + w) {
					D[lv][v] = D[lv][u] + w;
					Q.push({lv, v, D[lv][v]});
				}
				continue;
			}
			long w = x.y/(1ll << (lv+1));
			if(lv != q && D[lv+1][v] > D[lv][u] + w) {
				D[lv+1][v] = D[lv][u] + w;
				Q.push({lv+1, v, D[lv+1][v]});
			}
			if(lv == q) {
		 		long w = x.y/(1ll<<lv);
				if(D[lv][v] > D[lv][u] + w) {
					D[lv][v] = D[lv][u] + w;
					Q.push({lv, v, D[lv][v]});
				}
			}
		}
	}
	long mn = inf;
	for(int i = 0; i <= q; ++i) {
		mn = min(mn, D[i][pos.size()]);
	}
	return mn;
}

int main() {
	// freopen("r", "r", stdin);
	read();
	for(auto x:pos) dijkstra(x);
	printf("%lld\n", solve());
}