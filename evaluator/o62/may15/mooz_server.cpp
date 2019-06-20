#include "mooz_server.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 305;

vector<int> g[N];
vector<pii> ans;

int low[N], pre[N];

void tarjan(int u, int p) {
	static int idx = 0;
	low[u] = pre[u] = ++idx;
	for(int v : g[u]) if(!pre[v]) {
		tarjan(v, u);
		low[u] = min(low[u], low[v]);	
		if(low[v] > pre[u]) ans.emplace_back(u, v);
	} else if(v != p) low[u] = min(low[u], pre[v]);
}

int n;
bool st[N];

bool isap(int u) {
	vector<int> vec;
	for(int i = 1; i <= n; ++i) if(i != u) vec.emplace_back(i);
	return get_component(vec) != 1;
}

vector<pii> find_bridge(int n) {
	::n = n;
	if(n <= 100) {
		for(int i = 1; i <= n; ++i) for(int j = i+1; j <= n; ++j) {
			vector<int> z;
			z.emplace_back(i), z.emplace_back(j);
			int val = get_component(z);
			if(val == 1) g[i].emplace_back(j), g[j].emplace_back(i);
		}
		tarjan(1, 0);
		return ans;
	}
	for(int i = 2; i < n-1; ++i) {
		if(isap(i) && isap(i+1)) ans.emplace_back(i, i+1);
	}	
	bool st = true;
	for(int i = 3; i <= n; ++i) {
		vector<int> vec;
		vec.emplace_back(1), vec.emplace_back(i);
		if(get_component(vec) == 1) st = false;
	}
	if(st) ans.emplace_back(1, 2);
	st = true;
	for(int i = 1; i <= n-2; ++i) {
		vector<int> vec;
		vec.emplace_back(n), vec.emplace_back(i);
		if(get_component(vec) == 1) st = false;
	}
	if(st) ans.emplace_back(n-1, n);
	return ans;
	
}
