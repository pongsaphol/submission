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

const int MAXN = 1e3+5;

int n, m, A[MAXN][MAXN], d[4][MAXN][MAXN];

void read() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= m; ++j)
			scanf("%d", &A[i][j]);
}

int f(int x, int y) {
	int sum = -3;
	for(int i = 0; i < 4; ++i) sum += d[i][x][y];
	return sum;
}

void solve() {
	read();
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		if(A[i][j] >= A[i-1][j]) d[0][i][j] = d[0][i-1][j]+1;
		else d[0][i][j] = 1;
		if(A[i][j] >= A[i][j-1]) d[1][i][j] = d[1][i][j-1]+1;
		else d[1][i][j] = 1;	
	}
	for(int i = n; i >= 1; --i) for(int j = m; j >= 1; --j) {
		if(A[i][j] >= A[i+1][j]) d[2][i][j] = d[2][i+1][j]+1;
		else d[2][i][j] = 1;
		if(A[i][j] >= A[i][j+1]) d[3][i][j] = d[3][i][j+1]+1;
		else d[3][i][j] = 1;
	}
	int mx = 0, x, y;
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
		if(mx < f(i, j)) {
			mx = f(i, j);
			x = i, y = j;
		}
	}
	printf("%d\n%d %d\n", mx, x, y);
}

int main() {
	red();
	int T;
	scanf("%d", &T);
	while(T--) solve();
}