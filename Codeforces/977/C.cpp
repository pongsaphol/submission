#include <bits/stdc++.h>
using namespace std;

int n, i;
vector<int> V;

int main() {
	scanf("%d %d", &n, &i);
	for(int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		V.emplace_back(x);
	}
	if(n == 1 and i == 1) return !printf("%d\n", V[0]);
	V.emplace_back(-1);
	sort(V.begin(), V.end());
	V.emplace_back(1000000001);
	if(i == 0) {
		if(V[1] == 1) return !printf("-1");
		else return !printf("1");
	}
	if(V[i] != V[i+1]) {
		return !printf("%d\n", V[i]);
	} else return !printf("-1");
}