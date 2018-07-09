#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct P {
	int x, y, z;
}P;

const int MAXN = 1e5;

P mx[MAXN+5];
int n, m, idx[MAXN+5];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	int mxidx = 1;
	while(n--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		idx[b]++;
		if(mx[idx[b]].x == c && mx[idx[b]].z > b) mx[idx[b]] = {c, a, b};
		if(mx[idx[b]].x < c) mx[idx[b]] = {c, a, b};
		mxidx = max(mxidx, idx[b]);
	}
	for(int i = 1; i <= mxidx; ++i) printf("%d\n", mx[i].y);
}