#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

char A[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%s", A);
	int now = 'a';
	for(int i = 0; A[i] != 0; ++i) {
		if(A[i] <= now) {
			A[i] = now;
			now++;
		}
		if(now == ('z' + 1)) break;
	}

	if(now == ('z' + 1)) printf("%s\n", A);
	else puts("-1");
}