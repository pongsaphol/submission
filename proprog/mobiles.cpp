#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1<<10;

int t[MAXN+5][MAXN+5];

void update(int x, int Y, int val) {
	while(x <= MAXN) {
		int y = Y;
		while(y <= MAXN) {
			t[x][y] += val;
			y += y&(-y);
		}
		x += x&(-x);
	}
}

int query(int x, int Y) {
	int val = 0;
	while(x > 0) {
		int y = Y;
		while(y > 0) {
			val += t[x][y];
			y -= y&(-y);
		}
		x -= x&(-x);
	}
	return val;
}

int main() {
	freopen("r", "r", stdin);
	int met;
	while(scanf("%d", &met) && met != 3) {
		int x, y, a, b, val;
		if(met == 0) {
			scanf("%d", &val);
			memset(t, 0, sizeof t);
		}else if(met == 1) {
			scanf("%d %d %d", &x, &y, &val);
			x++, y++;
			update(x, y, val);
		}else if(met == 2) {
			scanf("%d %d %d %d", &x, &y, &a, &b);
			x++, y++, a++, b++;
			printf("%d\n", query(a, b) - query(x-1, b) - query(a, y-1) + query(x-1, y-1));
		}
	}
	return 0;
}