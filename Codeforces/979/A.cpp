#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n; scanf("%lld", &n);
	n++;
	if(n == 1) puts("0");
	else if(n & 1) printf("%lld\n", n);
	else printf("%lld\n", n >> 1);
}