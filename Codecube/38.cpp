#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct node {
	int x, y, p; // 0 is up, 1 is right, 2 is down, 3 is left
} node;

const int MAXN = 1005;

int n, arr[MAXN][MAXN], dp[MAXN][MAXN][4];
void read_input() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == 0) arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
}
queue<node> Q;

void push(int x, int y, int p, int d) {
	if(dp[x][y][p] > d) {
		dp[x][y][p] = d;
		Q.push({x, y, p});
	}
}
int solve() {
	fill(dp[0][0], dp[0][0] + sizeof(dp)/sizeof(int), 1e9);
	dp[1][1][2] = 0;
	dp[1][1][1] = 0;
	Q.push({1, 1, 2});
	Q.push({1, 1, 1});
	while(!Q.empty()) {
		auto now = Q.front();
		Q.pop();
		int x = now.x;
		int y = now.y;
		int p = now.p;
		int d = dp[x][y][p];
		// printf("%d %d\n", x, y);
		if(x == n && y == n) return d;
		// 0 is up, 1 is right, 2 is down, 3 is left
		if(p == 0) {
			if(arr[x-1][y])	push(x-1, y, 0, d+1);
			else {
				if(arr[x][y+1]) push(x, y+1, 1, d+1);
				if(arr[x][y-1]) push(x, y-1, 3, d+1);
			}
		}
		if(p == 1) {
			if(arr[x][y+1]) push(x, y+1, 1, d+1);
			else {
				if(arr[x-1][y]) push(x-1, y, 0, d+1);
				if(arr[x+1][y]) push(x+1, y, 2, d+1);
			}
		}
		if(p == 2) {
			if(arr[x+1][y])	push(x+1, y, 2, d+1);
			else {
				if(arr[x][y+1]) push(x, y+1, 1, d+1);
				if(arr[x][y-1]) push(x, y-1, 3, d+1);
			}
		}
		if(p == 3) {
			if(arr[x][y-1]) push(x, y-1, 3, d+1);
			else {
				if(arr[x-1][y]) push(x-1, y, 0, d+1);
				if(arr[x+1][y]) push(x+1, y, 2, d+1);
			}
		}
	}
	return -1;
}

int main() {
	// freopen("r", "r", stdin);
	read_input();
	printf("%d\n", solve());
}