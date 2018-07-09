#include <bits/stdc++.h>
using namespace std;


int main() {
	// freopen("r", r", stdin);
	int k;
	scanf("%d", &k);
	if(k >= 37) return !printf("-1\n");
	while(k > 1) {
		printf("8");
		k -= 2;
	}
	if(k) printf("4");
}