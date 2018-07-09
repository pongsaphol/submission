#include <bits/stdc++.h>
using namespace std;

void ref() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
}

const int MAXN = 2e5+5;

int P[MAXN], cc[MAXN], cs[MAXN];
set<int> S[MAXN];

vector<pair<int, int> > V;

int find(int u) {
	if(P[u] == u) return u;
	return P[u] = find(P[u]);
}

int main() {
	ref();
	fill(cc, cc+MAXN, 1);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) P[i] = i;
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		V.emplace_back(a, b);
		V.emplace_back(b, a);
	}
	sort(V.begin(), V.end());
	for(auto x:V) {
		if(cc[x.first] == x.second) cc[x.first]++;
		S[x.first].emplace(x.second);
	}
	for(int i = 1; i <= n; ++i) {
		if(cc[i] == i || cc[cc[i]] == i) while(S[i].find(++cc[i]) != S[i].end())
		if(cc[i] > n) continue;
		P[i] = find(cc[i]);
	}
	map<int, int> M;
	for(int i = 1; i <= n; ++i) M[find(i)]++;
	printf("%d\n", M.size());
	vector<int> V;
	for(auto x:M) V.emplace_back(x.second);
	sort(V.begin(), V.end());
	for(auto x:V) printf("%d ", x);
}