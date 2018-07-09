#include <cstdio>
#include <algorithm>
#define x first
#define y second
using namespace std;

int n, m, arr[105][105], in[5][1005], cnt[5];
int di[4][2] = {{ 0, 1},
				{ 0,-1}, 
				{ 1, 0}, 
				{-1, 0}};

int f(char x) {
	if(x == 'E') return 0;
	if(x == 'W') return 1;
	if(x == 'S') return 2;
	if(x == 'N') return 3;
}
pair<int, int> pos[5];

void upd(int idx) {
	arr[pos[idx].x][pos[idx].y] = idx;
}

bool check(pair<int, int> x) {
	if(x.x > n || x.x < 1 || x.y > n || x.y < 1) return false;
	if(x == pos[1] || x == pos[2] || x == pos[3] || x == pos[4]) return false;
	return true;
}
int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	pos[1] = {1, n};
	pos[2] = {n, n};
	pos[3] = {n, 1};
	pos[4] = {1, 1};
	for(int i = 1; i <= 4; ++i) {
		upd(i);
		for(int j = 1; j <= m; ++j) {
			char x;
			scanf(" %c", &x);
			in[i][j] = f(x);
		}
	}
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= 4; ++j) {
			pair<int, int> newpos = {pos[j].x + di[in[j][i]][0], pos[j].y + di[in[j][i]][1]};
			if(check(newpos)) pos[j] = newpos;
			upd(j);
			// printf("%d::%d %d\n", j, pos[j].x, pos[j].y);
			// for(int i = 1; i <= n; ++i) {
			// 	for(int j = 1; j <= n; ++j) {
			// 		cnt[arr[i][j]]++;
			// 		printf("%d ", arr[i][j]);
			// 	}
			// 	printf("\n");
			// }
			// printf("----------\n");
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cnt[arr[i][j]]++;
			// printf("%d ", arr[i][j]);
		}
		// printf("\n");
	}
	vector<int> ans;
	int mx = 0;
	for(int i = 1; i <= 4; ++i) mx = max(mx, cnt[i]);
	for(int i = 1; i <= 4; ++i) if(cnt[i] == mx) ans.push_back(i);
	if(cnt[0] != 0) {
		printf("No\n");
		return 0;
	}
	printf("%d %d\n", ans.size(), mx);
	for(auto x:ans) printf("%d\n", x);
	return 0;
}