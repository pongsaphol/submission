#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

struct data {
	int x, y;
	data(int x, int y) : x(x), y(y) { } 
	friend inline bool operator<(const data &a, const data &b) {
		if(a.x == b.x) return a.y > b.y;
		return a.x < b.x;
	}
}

const int N = 2e5+5;

int n, m, A[N];
vector<vector<pii> > g(N);
vector<pii> ans(N); // ans[i].x is maximum size of ice and ans[i].y is minimum number of making ice

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", A+i), ans[i] = pii(A[i], i);
	while(m--) {
			
		g[a].emplace_back(b), g[b].emplace_back(a);
	}
	priority_queue<data> Q;
	for(int i = 1; i <= n; ++i) Q.emplace(A[i], i);
	while(!Q.empty()) {
		auto ret = Q.top();
		Q.pop();
		for(auto v : g[ret.y]) if(ans[v].x < ret.x - 1) {
			ans[v] = pii(ret.x - 1, ans[ret.y].y);
			Q.emplace(ans[v].x, v);	                                
		}
	}
	for(int i = 1; i <= n; ++i) printf("%d %d\n", ans[i].x, ans[i].y);
}