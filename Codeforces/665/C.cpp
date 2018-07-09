#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

char A[MAXN];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%s", A);
	int n = strlen(A);
	for(int i = 0; i < n; ++i) {
		if(A[i] == A[i+1]) {
			if(A[i] != 'a' && A[i+2] != 'a') A[i+1] = 'a';
			else if(A[i] == 'a' && A[i+2] == 'a') A[i+1] = 'b';
			else if(A[i] == 'a' && A[i+2] != 'a') 
				if(A[i+2] == 'b') A[i+1] = 'c';
				else A[i+1] = 'b';
			else if(A[i] != 'a' && A[i+2] == 'a')
				if(A[i] == 'b') A[i+1] = 'c';
				else A[i+1] = 'b';
		}
	}
	printf("%s", A);
}