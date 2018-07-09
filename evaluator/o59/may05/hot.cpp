#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int INF = 1e9+1, N = 1e5+5;

int n, m, k, f[N], d[N], idx[N], t1[N<<1], t2[N<<1];
vector<pii> coor;

void upd1(int x, int v) { for(t1[x += n] = v; x != 1; x >>= 1) t1[x >> 1] = max(t1[x], t1[x^1]);}
void upd2(int x, int v) { for(t2[x += n] = v; x != 1; x >>= 1) t2[x >> 1] = min(t2[x], t2[x^1]);}

int que1(int l, int r) {
	int mx = -1;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if(l & 1) mx = max(mx, t1[l++]);
		if(r & 1) mx = max(mx, t1[--r]);
	}
	return mx;
}

int que2(int l, int r) {
	int mn = INF;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if(l & 1) mn = min(mn, t2[l++]);
		if(r & 1) mn = min(mn, t2[--r]);
	}
	return mn;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) scanf("%d", d+i);
	sort(d, d+n);
	while(m--) {
		coor.clear();
		coor.reserve(n);
		memset(t1, -1, sizeof t1);
		scanf("%d", &k);
		vector<int> V;
		for(int i = 0; i < k; ++i) {
			int now; scanf("%d", &now);
			V.emplace_back(now);
		}
		sort(all(V));
		int mx = 0;
		int ptr = 0;
		for(int i = 0; i < n; ++i) {
			while(ptr < V.size() and V[ptr] <= d[i]) ptr++;
			int mn = 1e9;
			if(ptr) mn = min(mn, d[i] - V[ptr-1]);
			if(ptr != V.size()) mn = min(mn, V[ptr] - d[i]);
			f[i] = mn;
			coor.emplace_back(-f[i]-d[i], i);
		}
		sort(all(coor));
		for(int i = 0; i < n; ++i) idx[coor[i].y] = i;
		ptr = n;
		for(int i = 0; i < n; ++i) {
			while(ptr != 0 and coor[ptr-1].x >= f[i]-d[i]) ptr--;
			int x1 = que1(ptr, n-1);
			int x2 = que2(0, ptr-1);
			if(x1 != -1) mx = max(mx, f[i] + x1);
			if(x2 != INF) mx = max(mx, d[i] - x2);
			upd1(idx[i], f[i]);
			upd2(idx[i], d[i]);
		}
		printf("%d\n", mx);
	}
}
