#include <bits/stdc++.h>
using namespace std;


int A[100005];
char out[100005];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	// 210
	int n;
	scanf("%d", &n);
	if(n < 3) return !printf("-1\n");
	if(n == 3) return !printf("210\n");
	int now = 1000 % 210;
	for(int i = 0; i < n-4; ++i) {
		now *= 10;
		now %= 210;
	}
	if(now != 0) now = 210 - now;
	sprintf(out, "%d", now);
	int len = strlen(out);
	reverse(out, out + len);
	for(int i = 0; i < n; ++i) {
		if(out[i] == 0) out[i] = '0';
		if(i == n-1) out[i] = '1';
	}
	reverse(out, out + n);
	printf("%s", out);
}