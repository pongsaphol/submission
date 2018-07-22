#include <bits/stdc++.h>
using namespace std;

int n;

int get(int x) {
	int sum = 0;
	while(x) { sum += x % 10; x /= 10; }
	return sum;
}

int main() {
	scanf("%d", &n);
	int mn = 1e9;
	for(int i = 1; i < n; ++i) mn = min(mn, get(i) + get(n-i));
	printf("%d\n", mn);
}
