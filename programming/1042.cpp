#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 5005;

int x[MAXN], y[MAXN];

int r, c;

int main() {
	// freopen("r", "r", stdin);
	int T;
	scanf("%d%d%d", &r, &c, &T);
	while(T--) {
		int X, Y, R;
		scanf("%d%d%d", &X, &Y, &R);
		for(int i = X-R; i <= X+R; ++i) {
			if(i >= 0 && i <= r) x[i]++;
		}
		for(int j = Y-R; j <= Y+R; ++j) {
			if(j >= 0 && j <= c) y[j]++;
		}
	}
	int mx = 0;
	for(int i = 0; i <= r; ++i) mx = max(mx, x[i]);
	for(int i = 0; i <= c; ++i) mx = max(mx, y[i]);
	printf("%d\n", mx);
}