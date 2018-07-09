#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	vector<int> V;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int now; scanf("%d", &now);
		V.emplace_back(now);
	}
	double mn = -1;
	sort(V.begin(), V.end());
	for(int i = 0; i < V.size() - 2; ++i) {
		if(V[i+2] - V[i] > m) continue;
		int l = i + 2, r = V.size()-1;
		while(l < r) {
			int _m = (l + r + 1) >> 1;
			if(V[_m] - V[i] <= m) l = _m;
			else r = _m - 1;
		}
		double y = V[l] - V[i+1];
		double x = V[l] - V[i];
		mn = max(mn, y/x); 
	}
	printf("%.10f", mn);
}