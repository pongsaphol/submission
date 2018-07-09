#include <bits/stdc++.h>
using namespace std;

char in[105], A[] = "aeiouy";
bool chk[300];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	for(int i = 0; i < 6; ++i) chk[A[i]] = true;
	int n;
	scanf("%d", &n);
	scanf("%s", in);
	for(int i = 0; i < n; ++i) {
		if(chk[in[i]]) {
			printf("%c", in[i]);
			while(chk[in[++i]]);
			i--;
		} else {
			printf("%c", in[i]);
		}
	}
}