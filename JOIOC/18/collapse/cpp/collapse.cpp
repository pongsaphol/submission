#include "collapse.h"
#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

vector<int> P;

int find(int x) { return P[x] = P[x] == x ? x : find(P[x]); }

vector<int> simulateCollapse(int N, vector<int> T, vector<int> X, vector<int> Y, vector<int> W, vector<int> P) {
	assert(N <= 5000);
	int m = (int)W.size();
	vector<int> V;
	for(int i = 0; i < (int)X.size(); ++i) if(X[i] > Y[i]) swap(X[i], Y[i]);
	for(int i = 0; i < m; ++i) {
		::P.clear();
		::P.resize(N+1);
		for(int j = 0; j < N; ++j) ::P[j] = j;
		set<pii> S;
		for(int j = 0; j <= W[i]; ++j) {
			if(X[j] <= P[i] && Y[j] >= P[i]+1) continue;
			if(T[j]) S.erase(pii(X[j], Y[j]));
			else S.emplace(pii(X[j], Y[j])); 	
		}
		
		for(auto x : S) {
			int u = find(x.x), v = find(x.y);
			if(u != v) ::P[u] = v;
		}
		set<int> z;
		for(int i = 0; i < N; ++i) z.emplace(find(i));
		V.emplace_back((int)z.size());
	}
	return V;
}
