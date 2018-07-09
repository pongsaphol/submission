#include <bits/stdc++.h>
using namespace std;
using iii = tuple<int, int, int>;
const int N = 1e3+5;

int n, dp[N][N];
vector<iii> V;
vector<int> coor;

int f(int x, int v) {
	int z = upper_bound(coor.begin(), coor.end(), x) - coor.begin()-1;
	return z == v ? --z : z;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	coor.emplace_back(-1), V.emplace_back(-1, -1, -1);
	for(int i = 1; i <= n; ++i) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		coor.emplace_back(b), V.emplace_back(a, b, c);
	}
	sort(coor.begin(), coor.end());
	sort(V.begin(), V.end(), [&](const iii &a, const iii &b) {
		if(get<1>(a) == get<1>(b)) return get<2>(a) > get<2>(b);
		return get<1>(a) < get<1>(b);
	});
	// for(int i = 1; i <= n; ++i) {
	// 	int a, b, c; tie(a, b, c) = V[i];
	// 	printf("%d %d %d\n", a, b, c);
	// }
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
		dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		if(i != j) dp[i][j] = max(dp[i][j], 
			dp[f(get<0>(V[i]), j)][f(get<0>(V[j]), i)] + get<2>(V[i]) + get<2>(V[j]));
		// printf("%d ", dp[i][j]);
		}
		// puts("");
	}
	printf("%d\n", dp[n][n]);
}