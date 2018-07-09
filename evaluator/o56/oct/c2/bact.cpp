#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
#include <iterator>
#include <cstring>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

int n, m, k, cnt[905], dp[35][35][35][35], arr[35][35];
map<int, int> M;
int recur(int x1, int y1, int x2, int y2) {
	int &now = dp[x1][y1][x2][y2];
	if(now != -1) return now;
	now = 0;
	if(y2-y1 == 0 || x2-x1 == 0) {
		map<int, int> M;
		for(int i = x1; i <= x2; ++i) {
			for(int j = y1; j <= y2; ++j) {
				M[arr[i][j]]++;
			}
		}
		for(auto &x:M) if(cnt[x.x] == x.y) now++;
		return now;
	}
	now = max(now, recur(x1, y1, x1, y2) + recur(x1+1, y1, x2, y2));
	now = max(now, recur(x1, y1, x2, y1) + recur(x1, y1+1, x2, y2));
	now = max(now, recur(x2, y1, x2, y2) + recur(x1, y1, x2-1, y2));
	now = max(now, recur(x1, y2, x2, y2) + recur(x1, y1, x2, y2-1));
	return now;
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	memset(dp, -1, sizeof dp);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			arr[i][j] = input();
			cnt[arr[i][j]]++;
		}
	}
	printf("%d\n", recur(1, 1, n, m));
}