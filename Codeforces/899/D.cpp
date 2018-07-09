#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define mem(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
#ifdef INPUT
#define dbg(x) cout << "debug : "<< x << endl
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
}

char to[20], to2[20];

int main() {
	red();
	long n = input();
	long ans = 0;
	for(int len = 0; len <= 9; ++len) {
		to[len] = '9';
		long sum = 0, z;
		for(int i = 0; i <= 8; ++i) {
			to[0] = i+'0';
			sscanf(to, "%I64d", &z);
			dbg(z);
			if(min(z-1ll, n) < max(1ll, z-n)) continue;
			long ret = min(z-1ll, n) - max(1ll, z-n) + 1ll;
			sum += ret/2;
		}
		if(sum == 0) break;
		else ans = sum;
	}
	cout << ans << endl;
}