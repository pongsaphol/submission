#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d %d", &n, &a, &b);
	int na = 0, nb = 0;
	for(int i = 0; a*i <= n; ++i) {
		if((n - a*i)%b == 0) {
			na = i, nb = (n - a*i)/b;
			break;
		}
	}
	if(na == 0 && nb == 0) return !printf("-1\n");
	int cc = 1;
	while(na--) {
		int st = cc;
		for(int i = 1; i < a; ++i) printf("%d ", ++cc);
		printf("%d ", st);
		cc++;
	}
	while(nb--) {
		int st = cc;
		for(int i = 1; i < b; ++i) printf("%d ", ++cc);
		printf("%d ", st);
		cc++;
	}
}