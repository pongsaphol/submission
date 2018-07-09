#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

const int MAXN = 1e4 + 5;

int n, m, d[MAXN], low[MAXN], com[MAXN], idx, tick;
bool chk[MAXN];
char A[MAXN];
vector<int> g[MAXN];
set<int> G[MAXN];
stack<int> S;

void scc(int u) {
	d[u] = low[u] = ++tick;
	S.push(u);
	chk[u] = true;
	for(int v : g[u]) {
		if(!d[v]) {
			scc(v);
			low[u] = min(low[u], low[v]);
		}
		else if(chk[v]) low[u] = min(low[u], low[v]);
	}
	if(d[u] == low[u]) {
		++idx;
		int v;
		do {
			v = S.top();
			S.pop();
			chk[v] = false;
			com[v] = idx;
		} while(u != v);
	}
}

string str[MAXN], dp[MAXN];
bool wasdone[MAXN];

string find(int u) {
	if(com[n] == u) {
		chk[u] = true;
		return str[u];
	}
	if(wasdone[u]) return dp[u];
	string now = "";
	for(auto v : G[u]) {
		string cat = find(v);
		if(chk[v]) {
			chk[u] = true;
			if(now.size() < cat.size()) now = cat;
			if(now.size() == cat.size())
				if(cat < now) now = cat;
		}
	}
	wasdone[u] = true;
	return dp[u] = str[u] + now;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	scanf("%s", A + 1);
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].emplace_back(b);
	}
	for(int i = 1; i <= n; ++i) if(!d[i]) scc(i);
	for(int i = 1; i <= n; ++i) {
		str[com[i]].push_back(A[i]);
		for(int v : g[i]) if(com[v] != com[i]) G[com[i]].emplace(com[v]);
	}
	memset(chk, 0, sizeof chk);
	for(int i = 1; i <= idx; ++i) sort(all(str[i]));
	cout << find(com[1]) << endl;
}
