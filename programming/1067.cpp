#include <cstdio>
#include <cstring>
#include <algorithm>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

P g[] = {{0,0}, {-1,0}, {0,1}, {1,0}, {0,-1}};
int n, m, k, arr[105][105];
bool chk[105][105];
char toP[] = "_NESW";
void read() {
	scanf("%d%d%d", &m, &n, &k);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scanf("%d", arr[i] + j);
		}
	}
}

void solve() {
	memset(chk, false, sizeof chk);
	int a, b;
	scanf("%d%d", &b, &a);
	while(1) {
		if(chk[a][b]) {
			printf("NO\n");
			return;
		}
		chk[a][b] = true;
		int na = a + g[arr[a][b]].x;
		int nb = b + g[arr[a][b]].y;
		if(na < 1 || na > n || nb < 1 || nb > m) {
			printf("%c\n", toP[arr[a][b]]);
			return;
		}
		a = na, b = nb;
	}
}

int main() {
	// freopen("r", "r", stdin);
	read();
	while(k--) solve();
}