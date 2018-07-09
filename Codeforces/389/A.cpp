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
	int n = input();
	int x = n;
	int gcd = input();
	while(--n) {
		gcd = __gcd(gcd, input());
	}
	cout << x*gcd << endl;
}