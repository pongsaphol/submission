#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define mem(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
#ifdef INPUT
#define dbg(x) cout << "debug : " << x << endl
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

struct matrix {
	int A[4][4];
	friend inline matrix operator*(const matrix &a, const matrix &b) {
		matrix ret;
		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j < 4; ++j) {
				int sum = 0;
				for(int k = 0; k < 4; ++k) {
					sum = (int)((sum+(long)a.A[i][k]*b.A[k][j])%MOD);
				}
				ret.A[i][j] = sum;
			}
		}
		return ret;
	}
};

matrix ans = {{{1, 0, 0, 0},
				{0, 1, 0, 0},
				{0, 0, 1, 0},
				{0, 0, 0, 1}}};

matrix path = {{{0, 1, 1, 1},
				{1, 0, 1, 1},
				{1, 1, 0, 1},
				{1, 1, 1, 0}}};


int main() {
	red();
	int n = input();
	for(int i = 1; i <= n; i<<=1) {
		if(n&i) ans = ans*path;
		path = path*path;
	}
	return !printf("%d\n", ans.A[0][0]);
}