#include <bits/stdc++.h>
using namespace std;

char A[2005];
int main() {
	int n, k; cin >> n >> k;
	scanf("%s", A+1);
	bool st = true;
	for(int i = 1; i <= n-k; ++i) {
		if(A[i] == A[i+k] and A[i] == '.') {
			A[i] = '1', A[i+k] = '0';
			st = false;
		} else if(A[i] != A[i+k] and A[i] != '.' and A[i+k] != '.') st = false;
		else if(A[i] != A[i+k]) {
			if(A[i] == '.') A[i] = A[i+k] == '0' ? '1' : '0';
			else if(A[i+k] == '.') A[i+k] = A[i] == '0' ? '1' : '0';
			st = false;
		}
	}	
	for(int j = n-k+1; j <= n; ++j) if(A[j] == '.') A[j] = '0';
	if(st) return !printf("No");
	puts(A+1);
}