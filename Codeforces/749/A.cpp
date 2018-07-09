#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", n/2);
	if(n%2) {
		printf("3 ");
		n -= 3;
	}
	for(int i = 0; (i<<1) != n; ++i) printf("2 ");
	printf("\n");
}