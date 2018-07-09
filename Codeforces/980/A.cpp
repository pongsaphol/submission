#include <bits/stdc++.h>
using namespace std;

const int N = 305;

char A[N];

int main() {
	scanf("%s", A);
	int c1 = 0, c2 = 0;
	for(int i = 0; A[i] != 0; ++i) {
		if(A[i] == '-') c1++;
		else c2++;
	}
	if(c2 == 0) puts("YES");
	else puts(c1 % c2 ? "NO" : "YES");
}