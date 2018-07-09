#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n;
vector<vector<int> > g(N);

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].emplace_back(b), g[b].emplace_back(a);
	}
	int mx = 0, ret;
	int cc = 0;
	vector<int> z;
	for(int i = 1; i <= n; ++i) {
		if(g[i].size() > 2) cc++;
		if(g[i].size() > mx) {
			mx = g[i].size();
			ret = i;
		} 
		if(g[i].size() == 1) z.emplace_back(i);
	}
	if(cc > 1) return !printf("No");
	puts("Yes");
	if(mx <= 2) {
		printf("1\n");
		printf("%d %d\n", z[0], z[1]);
		return 0;
	}
	printf("%d\n", z.size());
	for(auto v : z) printf("%d %d\n", v, ret);
}