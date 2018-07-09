#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define mem(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
#ifdef INPUT
#define dbg(x) cout << "debug : " <<  x << endl
#define dbg2(x, xx) cout << "debug : " << x << " : " << xx << endl 
#else
#define dbg(x)
#define dbg2(x, xx)
#endif
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.tie(0);
	cin.sync_with_stdio(false);
}

int main() {
	red();
	int n, a, b;
	cin >> n >> a >> b;
	int mx = 0;
	for(int i = 1; i < n; ++i) {
		int a1 = a/i, a2 = b/(n-i);
		mx = max(mx, min(a1, a2));
	}
	cout << mx;
}