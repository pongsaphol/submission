#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAXN = 1<<17, inf = 2e9;
int n, m;
multiset<int> t[MAXN<<1];
multiset<int>::iterator it;

void bulid() {
	for(int i = n; i > 0; --i) {
		for(auto x:t[i<<1]) t[i].insert(x);
		for(auto x:t[i<<1|1]) t[i].insert(x);
	}
}

void update(int i, int v) {
	int prev = *(t[i+=n].begin());
	t[i].erase(prev);
	t[i].insert(v);
	for(; i > 1; i>>=1) {
		it = t[i>>1].find(prev);
		t[i>>1].erase(it);
		t[i>>1].insert(v);
	}
}

void query(int l, int r, int v) {
	int mx = inf;
	for(l+=n, r+=n; l<r; l>>=1, r>>=1) {
		if(l&1) {
			it = t[l].upper_bound(v);
			if(it != t[l].end()) mx = min(mx, *it);
			l++;
		}
		if(r&1) {
			--r;
			it = t[r].upper_bound(v);
			if(it != t[r].end()) mx = min(mx, *it);
		}
	}
	if(mx == inf) printf("no\n");
	else printf("%d\n", mx);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		t[i+n].insert(x);
	}
	bulid();
	while(m--) {
		char z;
		scanf(" %c", &z);
		if(z == 'c') {
			int a, b;
			scanf("%d%d", &a, &b);
			update(a, b);
		}else {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			query(a, b+1, c);
		}
	}
}