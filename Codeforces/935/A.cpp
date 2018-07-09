#include <bits/stdc++.h>
using namespace std;


int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	int cnt = -1;
	for(int i = 1; i * i <= n; ++i) {
		if(i * i == n) cnt++;
		else if (n % i == 0) cnt += 2;
	}
	printf("%d\n", cnt);
}