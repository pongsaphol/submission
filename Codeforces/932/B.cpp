#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int val[MAXN];

int g(int x) {
	if(x < 10) return x;
	char num[10];
	sprintf(num, "%d", x);
	int prod = 1;
	for(int i = 0; num[i] != 0; ++i) {
		if(num[i] != '0') prod *= (num[i] - '0');
	}
	return val[prod];
}

int pf[10][MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	for(int i = 1; i <= 1000000; ++i) {
		val[i] = g(i);
		pf[val[i]][i]++;
	}
	for(int i = 1; i < 10; ++i) {
		for(int j = 1; j <= 1000000; ++j) pf[i][j] += pf[i][j-1];
	}
	int n;
	scanf("%d", &n);
	while(n--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", pf[c][b] - pf[c][a-1]);
	}
}