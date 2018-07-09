#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

double ans;
vector<int> V;

void calc() {
	if(!V.size()) return;
	sort(all(V));
	double ret = ((double)V[0] + V.back()) / 2;
	ret = max(ret - V[0], V.back() - ret);
	ans = max(ans, ret);
	V.clear();
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	int mx = 0;
	while(n--) {
		int now;
		scanf("%d", &now);
		if(mx <= now) calc();
		mx = max(mx, now);
		V.emplace_back(now);
	}
	calc();
	printf("%.6f", ans);
}