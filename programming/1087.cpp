#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 300;

int n, m, d, arr[MAXN+5][MAXN+5];

void read_input() {
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", &arr[i][j]);
		}
	}
}

int f(int x, int y) {
	// printf("-----------\n%d %d\n", x, y);
	int sum = 0;
	sum += arr[x][y];
	for(int i = y + 1; i <= y + d; ++i) {
		if(i > m) break;
		int now = arr[x][i];
		if((i-y)%2) now *= -1;
		//printf("%d\n", now);
		sum += now;
	}
	for(int j = y - 1; j >= y - d; --j) {
		if(j < 1) break;
		int now = arr[x][j];
		if((y-j)%2) now *= -1;
		//printf("%d\n", now);
		sum += now;
	}
	for(int i = x + 1; i <= x + d; ++i) {
		if(i > n) break;
		int now = arr[i][y];
		if((i-x)%2) now *= -1;
		//printf("%d\n", now);
		sum += now;
	}
	for(int j = x - 1; j >= x - d; --j) {
		if(j < 1) break;
		int now = arr[j][y];
		if((x-j)%2) now *= -1;
		//printf("%d\n", now);
		sum += now;
	}
	return sum;
}

int solve() {
	int mx = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			mx = max(mx, f(i, j));
		}
	}
	return mx;
}

int main() {
	//freopen("r", "r", stdin);
	read_input();
	printf("%d\n", solve());
}