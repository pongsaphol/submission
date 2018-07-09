#include <bits/stdc++.h>
#define long long long
using namespace std;

void ref() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
}

long f_(long x) { return x * x; }

int main() {
	ref();
	long a, b, c, d, e, f;
	scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
	if(f_(a - c) + f_(b - d) == f_(c - e) + f_(d - f) && (b-d)*(a-e) != (b-f)*(a-c)) puts("Yes");
	else puts("No");
}