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

const int MOD = 1e9+7;
long dp[2][5];
int main() {
	red();
	int n = input();
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		dp[i%2][0] = (dp[(i-1)%2][1]+dp[(i-1)%2][2]+dp[(i-1)%2][3])%MOD;
		dp[i%2][1] = (dp[(i-1)%2][0]+dp[(i-1)%2][2]+dp[(i-1)%2][3])%MOD;
		dp[i%2][2] = (dp[(i-1)%2][0]+dp[(i-1)%2][1]+dp[(i-1)%2][3])%MOD;
		dp[i%2][3] = (dp[(i-1)%2][0]+dp[(i-1)%2][1]+dp[(i-1)%2][2])%MOD;
	}
	printf("%d\n", dp[n%2][0]);
}