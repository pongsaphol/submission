#include <bits/stdc++.h>
#include "job.h"
#define long long long
#define all(x) (x).begin(), (x).end()
using namespace std;

struct pii {
	long u, d;
	int id;
	pii() : u(0), d(0), id(0) {}
	pii(long u, long d) : u(u), d(d) {}
	pii(long u, long d, int id) : u(u), d(d), id(id) {}
	friend inline bool operator<(const pii &a, const pii &b) {
		return a.d * b.u < b.d * a.u;
	}
	friend inline bool operator>(const pii &a, const pii &b) {
		return !(a < b);
	}
	friend inline pii operator+(const pii &a, const pii &b) {
		return pii(a.u + b.u, a.d + b.d, a.id);
	}
	friend inline pii operator-(const pii &a, const pii &b) {
		return pii(a.u - b.u, a.d - b.d, a.id);
	}
};

const int N = 2e5+5;

vector<int> g[N];
vector<pii> vec;
priority_queue<pii, vector<pii>, greater<pii> > Q[N];
long ans, sumd;

void dfs(int u) {
	for(int v : g[u]) {
		dfs(v);
		Q[u].emplace(vec[v]);
	}
	while(!Q[u].empty()) {
		if(Q[u].top() < vec[u]) {
			vec[u] = vec[u] + Q[u].top();
			int id = Q[u].top().id; Q[u].pop();
			if(Q[u].size() < Q[id].size()) swap(Q[u], Q[id]);
			while(!Q[id].empty()) {
				Q[u].emplace(Q[id].top());
				Q[id].pop();
			}
		} else break;
	}
}

long scheduling_cost(vector<int> p, vector<int> u, vector<int> d) {
	for(int i = 0; i < p.size(); ++i) vec.emplace_back(u[i], d[i], i);
	for(int i = 1; i < p.size(); ++i) g[p[i]].emplace_back(i);
	dfs(0);
	for(int i = 0; i < p.size(); ++i) vec[i].id = i;
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.emplace(vec[0]);
	vector<int> rr;
	while(!Q.empty()) {
		int id = Q.top().id; Q.pop();
		if(id) rr.emplace_back(id);
		ans += (sumd += d[id]) * u[id];
		for(int v : g[id]) Q.emplace(vec[v]);
	}
	// FILE* f = fopen("wrong.txt", "w");
    // for(auto x : rr) fprintf(f, "%d ", x);
	// fprintf(f, "\n");
	// for(int i = 1; i < p.size(); ++i) fprintf(f, "-> %d = %lld %lld\n", i, vec[i].u, vec[i].d);
    // fclose(f);
	return ans;
}

