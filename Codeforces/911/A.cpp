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
const int MAXN = 2e5+5;
int A[MAXN];
int main() {
	red();
	int mn = 1e9;
	int n = input();
	for(int i = 1; i <= n; ++i) {
		A[i] = input();
		mn = min(mn, A[i]);
	}
	int st = -1, ed;
	int ans = 1e9;
	for(int i = 1; i <= n; ++i) {
		if(A[i] == mn) {
			if(st == -1) {
				st = i;
				continue;
			}
			ans = min(ans, i-st);
			st = i;
		}
	}
	cout << ans;
}