#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Rec {
	int x1, y1, x2, y2;
}Rec;

bool isin(Rec a, Rec b) {
	if(a.x1 >= b.x2 || b.x1 >= a.x2 || a.y2 >= b.y1 || b.y2 >= a.y1) return false;
	return true;
}

int n, m;

Rec arr[1005];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		arr[i] = {a, b, c, d};
	}
	while(m--) {
		int cnt = 0;
		Rec now;
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		now = {a, b, c, d};
		for(int i = 1; i <= n; ++i) {
			if(isin(arr[i], now)) cnt++;
		}
		printf("%d\n", cnt);
	}
}