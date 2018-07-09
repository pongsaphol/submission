/*
TASK: o59_oct_c2_pointsoncircle
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, arr[1005][1005], ans[1005];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= m; ++j) {
			int now;
			scanf("%d", &now);
			if(now*2 > n) now = n - now;
			arr[i][j] = now;
		}
	}
	ans[1] = 0, ans[2] = arr[2][1];
	for(int i = 3; i <= m; ++i) {
		int ans1 = (ans[i-1] + arr[i-1][i]) % n;
		int ans2 = (ans[i-1] - arr[i-1][i] + n) % n;
		bool t1 = true;
		for(int j = 1; j <= i-2; ++j) {
			int num1 = (ans1 - ans[j] + n)%n;
			int num2 = (ans2 - ans[j] + n)%n;
			if(num1*2 > n) num1 = n - num1;
			if(num2*2 > n) num2 = n - num2;
			if(arr[j][i] != num1) t1 = false;
		}
		if(t1) ans[i] = ans1;
		else ans[i] = ans2;
	}
	for(int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
} 