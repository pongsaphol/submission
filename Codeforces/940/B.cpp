#include <bits/stdc++.h>
#define long long long
#define P pair<long, int>
#define x first
#define y second
using namespace std;

long n, k, a, b;

long work(long x) {
  if (x == 1) return 0;
  if (x < k) return (x-1)*a;
  return min(x%k*a+work(x/k)+b, (x-1)*a);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin >> n >> k >> a >> b;
	if(k == 1) return !printf("%lld\n", a * (n-1));
	cout << work(n);
}