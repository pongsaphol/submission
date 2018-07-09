#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define P pair<int,bool>
#define x first
#define y second
using namespace std;

const int MAXN = 1<<17;

int n, m;
P t[MAXN<<1];

void build() {
	for(int i = n-1; i >= 1; --i) {
		t[i].x = t[i<<1].x + t[(i<<1)|1].x;
		t[i].y = t[i<<1].y | t[(i<<1)|1].y;
	}
}

void update(int idx, int val) {
	if(val < 0) t[idx+n] = {1, false};
	else if(val == 0)t[idx+n] = {0, true};
	else t[idx+n] = {0, false};
	for(int i = idx+n; i > 1; i>>=1) {
		t[i>>1].x = t[i].x + t[i^1].x;
		t[i>>1].y = t[i].y | t[i^1].y;
	}
}

void query(int l, int r) {
	P ans = {0, false};
	for(l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if(l&1) ans.x += t[l].x, ans.y |= t[l++].y;
		if(r&1) ans.x += t[--r].x, ans.y |= t[r].y;
	}
	if(ans.y) printf("0");
	else if(ans.x%2) printf("-");
	else printf("+");
}
int main{
	// freopen("r", "r", stdin);
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i = 0; i < (MAXN<<1); ++i) t[i] = {0, false};
		for(int i = 0; i < n; ++i) {
			int now; scanf("%d", &now);
			if(now < 0) t[i+n].x = 1;
			if(now == 0)t[i+n].y = true;
		}
		build();
		while(m--) {
			char x;
			int a, b;
			scanf(" %c %d %d", &x, &a, &b);
			if(x == 'C') update(a-1, b);
			else query(a-1, b);
		}
		printf("\n");
	}
}