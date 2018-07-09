#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
using namespace std;

int n;
long m, t;
vector<int> V;
	
int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %lld", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int now;
		scanf("%d", &now);
		V.emplace_back(now);
	}
	sort(all(V));
	m--;
	int i;
	for(i = 0; i < n; i += t) {
		for(t = 1; V[i] == V[i+t]; ++t);
		if(t*n > m) break;
		m -= t*n;
	}
	printf("%d %d\n", V[i], V[m/t]);
}