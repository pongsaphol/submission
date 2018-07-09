#include <bits/stdc++.h>
using namespace std;

bool st = false;

struct data{
	char a, b, c;
	void in() {
		c++;
		if(c == 100) c = 0, b++;
		if(b == 100) b = 0, a++;
	}
	data operator+(const data &rhs) {
		int _a = (int)a + rhs.a;
		int _b = (int)b + rhs.b;
		int _c = (int)c + rhs.c;
		if(_c >= 100) {
			_b += _c / 100;
			_c %= 100;
		}
		if(_b >= 100) {
			_a += _b / 100;
			_b %= 100;
		}
		return {(char)_a, (char)_b, (char)_c};
	}
	data operator-(const data &rhs) {
		int _a = (int)a - rhs.a;
		int _b = (int)b - rhs.b;
		int _c = (int)c - rhs.c;
		while(_c < 0) _c += 100, _b--;
		while(_b < 0) _b += 100, _a--;
		return {(char)_a, (char)_b, (char)_c};
	}
	int get() {
		int _a = a, _b = b, _c = c;
		return _a * 10000 + _b*100 + _c;
	}
};

int n, m, a, b, c, d;
data dp[4][3005][3005];

int area(int c, int x1, int y1, int x2, int y2) {
	int ret = dp[c][x2][y2].get() - dp[c][x1-1][y2].get() - dp[c][x2][y1-1].get() + dp[c][x1-1][y1-1].get();
	return ret;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		dp[0][a][b].in();
		dp[1][a][d].in();
		dp[2][c][b].in();
		dp[3][c][d].in();
	}
	for(int k = 0; k < 4; ++k) for(int i = 1; i <= 3000; ++i) for(int j = 1; j <= 3000; ++j) {
		dp[k][i][j] = dp[k][i][j] + dp[k][i-1][j] + dp[k][i][j-1] - dp[k][i-1][j-1];
	}
	while(m--) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int ret = area(0, c+1, 1, 3000, d) + area(1, 1, 1, c, b-1)
				 + area(2, a, d+1, 3000, 3000) + area(3, 1, b, a-1, 3000);
		printf("%d\n", n - ret);
	}
}
