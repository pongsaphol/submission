#include <bits/stdc++.h>
using namespace std;

char A[2005];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%s", A);
	int n = strlen(A);
	printf("%s", A);
	for(int i = n-1; i >= 0; --i) printf("%c", A[i]);
}