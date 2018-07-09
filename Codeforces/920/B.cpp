#include <bits/stdc++.h>
using namespace std;

void ref() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
}

struct data{
	int x, y, z;
};

void solve() {
	vector<pair<int, int> > V[5005];
	int ans[5005] = {};
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		V[a].emplace_back(b, i);
	}
	queue<pair<int, int> > Q;
	for(int i = 1; i <= 5000q; ++i) {
		for(auto x:V[i]) Q.push(x);
		while(!Q.empty() && Q.front().first < i) Q.pop();
		if(!Q.empty()) {
			ans[Q.front().second] = i;
			Q.pop();
		}
	}
	for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
	puts("");
}

int main() {
	ref();
	int T;
	scanf("%d", &T);
	while(T--) solve();
}