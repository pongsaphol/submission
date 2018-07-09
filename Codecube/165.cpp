#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 5e4+5;

vector<int> x[MAXN];
vector<t> E;
int n, m, k, P[MAXN];

typedef struct t {
	int u, v, w;
	friend inline bool operator<(const t &a,const t &b) {
		return a.w < b.w;
	}
}t;


int find(int u) {
	if(P[u] == u) return u;
	return P[u] = find(P[u]);
}

void read_input() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) {
		int now;
		scanf("%d", &now);
		x[now].push_back(i);
	}
	while(m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E.push_back({u, v, w});
	}
}

int solve() {
	sort(E.begin(), E.end());
	int L = 0, R = 1e9, mid;
	while(L < R) {
		mid = (L + R + 1)/2;
		for(int i = 1; i <+ n; ++i) P[i] = i;
		for(auto i:E) {
			if(i.w <= mid) continue;
			int u = find(i.u), v = find(i.v);
			P[u] = v;
		}
		bool status = true;
		for(int i = 1; i <= k; ++i) {
			if(x[i].empty()) continue;
			int st = find(x[i][0]);
			for(auto now:x[i]) {
				if(st != find(now)) status = false;
			}
		}
		if(status) L = mid;
		else R = mid - 1;
	}
	int cnt = 0;
	for(auto i:E) if(i.w <= L) {
		cnt++;
	}
	return cnt;
}

int main() {
	//freopen("r", "r", stdin);
	read_input();
	printf("%d\n", solve());
}