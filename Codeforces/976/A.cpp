#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
char A[N];
int c1, c2;

int main() {
	scanf("%d %s", &n, A);
	for(int i = 0; i < n; ++i) {
		if(A[i] == '0') c1++;
		else c2++;
	}
	if(c2) printf("1");
	while(c1--) printf("0");
}