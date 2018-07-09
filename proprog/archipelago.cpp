#include <cstdio>
#include <algorithm>
using namespace std;

bool arr[15][15], ans[15][15];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			char now;
			scanf(" %c", &now);
			if(now == 'X') arr[i][j] = 1;
		}
	}
	int x1 = n, y1 = m, x2 = 1, y2 = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			int sum = arr[i-1][j] + arr[i][j-1] + arr[i+1][j] + arr[i][j+1];
			if(arr[i][j] && sum > 1) {
				ans[i][j] = 1; 
				x1 = min(x1, i);
				x2 = max(x2, i);
				y1 = min(y1, j);
				y2 = max(y2, j);
			}
		}
	}
	for(int i = x1; i <= x2; ++i) {
		for(int j = y1; j <= y2; ++j) {
			printf("%c",ans[i][j]?'X':'.');
		}
		printf("\n");
	}

}