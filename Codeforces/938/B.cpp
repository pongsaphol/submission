#include <bits/stdc++.h>
using namespace std;

bool chk[1000005];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int now;
		scanf("%d", &now);
		chk[now] = true;
	}
	int L = 1, R = 1000000, t = 0;
	while(n) {
		t++;
		L++;
		R--;
		if(chk[L]) {
			n--;
			chk[L] = false;
		}
		if(chk[R]) {
			n--;
			chk[R] = false;
		}
	}
	printf("%d\n", t);
}