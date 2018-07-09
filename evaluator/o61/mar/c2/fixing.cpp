#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &m, &k);
	vector<int> V;
	int pv; scanf("%d", &pv);
	for(int i = 1; i < m; ++i) {
		int now; scanf("%d", &now);
		if(now - pv != 1) {
			V.emplace_back(now - pv - 1);
		}
		pv = now;
	}
	sort(V.begin(), V.end());
	int sum = 0;
	for(int i = 0; i < (int)V.size() - k + 1; ++i) sum += V[i];
	printf("%d\n", sum);
}