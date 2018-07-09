#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int now;
		scanf("%d", &now);
		m -= 86400 - now;
		if(m <= 0) return !printf("%d\n", i);
	}
}