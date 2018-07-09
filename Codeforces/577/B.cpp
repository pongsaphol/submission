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

bool chk[2][1005];

int main() {
	red();
	int n = input(), m = input();
	while(n--) {
		int now = input();
		chk[n&1][now%m] = true;
		for(int i = m-1; i >= 0; --i) {
			chk[n&1][i] |= chk[(n-1)&1][i];
			chk[n&1][(i+now)%m] |= chk[(n-1)&1][i];
		}
		if(chk[n&1][0]) return puts("YES")&0;
	}
	return puts("NO")&0;
}