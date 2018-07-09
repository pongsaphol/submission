#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	vector<int> V;
	for(int i = 0; i <= 100; ++i) {
		if(i % 2) V.emplace_back((i/2) * (i/2) + (i/2 + 1) * (i/2 + 1));
		else V.emplace_back((i/2) * (i/2));
	}
	int n;
	scanf("%d", &n);
	printf("%d\n", lower_bound(all(V), n) - V.begin());
}