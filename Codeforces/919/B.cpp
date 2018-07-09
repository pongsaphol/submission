#include <bits/stdc++.h>
using namespace std;

vector<int> V;
char cc[20];

void dfs(int lv, int sum) {
	if(sum > 10) return;
	if(lv == 8 && sum != 10) return;
 	if(lv == 8) {
 		int now;
 		sscanf(cc, "%d", &now);
 		V.emplace_back(now);
		return;
	}
	for(int i = 0; i < 10; ++i) {
		cc[lv] = i + '0';
		dfs(lv + 1, sum + i);
	}
}

int main() {
	// freopen("r", "r", stdin);
	int n;
	scanf("%d", &n);
	V.reserve(100000);
	dfs(0, 0);
	printf("%d\n", V[n-1]);
}