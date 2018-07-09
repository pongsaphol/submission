#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 205;

int n, c[N];

int solve(int l, int r) {
	int freq[N];
	for(int i = l; i <= r; ++i) freq[i]++;
	vector<pii> V;
	for(int i = 1; i <= n; ++i) V.emplace_back(freq[i], i);
	sort(V.begin(), V.end(), greater<pii>());
	int ret = V[0].x*V[0].x*V[0].x, col = V[0].y;
	int pv = 1;
	for(int i = l; l <= r; ++i) if(c[i] != c[i+1]) {
		if(c[i] != col) ret += solve(pv, i);
		pv = i+1;
	}
	return ret;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", c+i);
	printf("%d\n", solve(1, n));
}
