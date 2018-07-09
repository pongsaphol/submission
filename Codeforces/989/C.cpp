#include <bits/stdc++.h>
using namespace std;

char A[55][55];

int main() {
	int a, b, c, d; cin >> a >> b >> c >> d;
	a--, b--, c--, d--;
	printf("40 50\n");
	for(int i = 1; i <= 10; ++i) for(int j = 1; j <= 50; ++j) A[i][j] = 'A';
	for(int i = 11; i <= 20; ++i) for(int j = 1; j <= 50; ++j) A[i][j] = 'B';
	for(int i = 21; i <= 30; ++i) for(int j = 1; j <= 50; ++j) A[i][j] = 'C';
	for(int i = 31; i <= 40; ++i) for(int j = 1; j <= 50; ++j) A[i][j] = 'D';
	for(int j = 1; j <= 10; j += 2) for(int i = 1; i <= 50; i += 2) {
		if(b) {
			b--;
			A[j][i] = 'B';
		}
	}
	for(int j = 11; j <= 20; j += 2) for(int i = 1; i <= 50; i += 2) {
		if(c) {
			c--;
			A[j][i] = 'C';
		}
	}
	for(int j = 21; j <= 30; j += 2) for(int i = 1; i <= 50; i += 2) {
		if(d) {
			d--;
			A[j][i] = 'D';
		}
	}
	for(int j =31; j <= 40; j += 2) for(int i = 1; i <= 50; i += 2) {
		if(a) {
			a--;
			A[j][i] = 'A';
		}
	}
	for(int i = 1; i <= 40; ++i) puts(A[i]+1);
}