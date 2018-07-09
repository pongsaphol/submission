#include <bits/stdc++.h>
#define long long long
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		long gcd = __gcd(a, b);
		a /= gcd, b /= gcd;
		gcd = __gcd(b, c);
		while(gcd > 1) {
			while(b % gcd == 0) b /= gcd;
			gcd = __gcd(b, c);
		}
		puts(b == 1 ? "Finite" : "Infinite");
	}
}