/*
For subtasks 1 to 3, I used the following greedy exchange argument:

Let C1 = d[1] * u[1] + (d[1] + d[2]) * u[2]
and C2 = d[2] * u[2] + (d[1] + d[2]) * u[1].
Suppose that C1 < C2. Then,
d[1] * u[1] + (d[1] + d[2]) * u[2] < d[2] * u[2] + (d[1] + d[2]) * u[1];
d[1] * u[2] < d[2] * u[1];
d[1] / u[1] < d[2] / u[2].
So I sorted the jobs by d[i] / u[i] in increasing order and solved  
these subtasks.

For subtasks 4 to 6, let the comparison function of node v be the  
minimum cost of any connected subgraph of the subtree of v that also  
contains v. For example, consider the following graph:
       0
     1   4
     2   5
     3   6
     4   7
cost[2] = min(d[2] / u[2],
               (d[2] + d[3]) / (u[2] + u[3]),
               (d[2] + d[3] + d[4]) / (u[2] + u[3] + u[4]))
and
cost[6] = min(d[6] / u[6],
               (d[6] + d[7]) / (u[6] + u[7])).

Then I used a method similar to Dijkstra's to schedule optimally.  
However, since the preprocess cost was O(n^2), I reduced the time to  
amortized linear by observing that if, for example, cost[2] = (d[2] +  
d[3]) / (u[2] + u[3]) and I want to compute cost[1], I will compute  
only for {1, 1..3, 1..4}, skipping 1..2 because the resulting cost  
would never be better than the cost for 1..3.

In case of general trees, I collected all children of each node in a  
priority queue and when merging queues (after scheduling that node), I  
always moved elements from a smaller set into a larger one.
*/
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
	while(!Q.empty()) {
		int id = Q.top().id; Q.pop();
		ans += (sumd += d[id]) * u[id];
		for(int v : g[id]) Q.emplace(vec[v]);
	}
	return ans;
}

