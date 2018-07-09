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
	red();
	int T = input();
	while(T--) {
		int n = input();
		int lg = log2(n);
		long ans = ((long)n*(n+1))/2;
		ans -= ((1<<(lg+1)) - 1)<<1;
		cout << ans << endl;
	}
}