#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
}

int main() {
	// red()a;
	long n, a, b;
	cin >> n >> a >> b;
	for(long i = 0; i <= n; ++i) {
		if(n - a*i < 0) continue;
		if((n - a*i)%b == 0) {
			printf("YES\n%I64d %I64d\n", i, (n - a*i)/b);
			return 0;
		}
	}
	puts("NO");
}