#include <bits/stdc++.h>
#define long long long
using namespace std;

const int MAXN = 1e5 + 5;

long n, k, A[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%lld %lld", &n, &k);
	vector<pair<long, long> > V;
	for(int i = 1; i <= k; ++i) {
		long now;
		scanf("%lld", &A[i]);
		V.emplace_back(n%A[i], i);
	}
	sort(V.begin(), V.end());
	printf("%lld %lld\n", V[0].second, n / A[V[0].second]);
}