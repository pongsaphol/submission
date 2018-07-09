#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

const int N = 1e5+5;

int n, m, A[N];
multiset<int> d[N];
set<int> pos[N];
vector<int> coor;
vector<pii> Q;

void del(int x) {
	int v = A[x];
	pos[v].erase(x);
	if(pos[v].empty()) return;
	auto R = pos[v].upper_bound(x);
	auto L = R;
	if(R != pos[v].end()) d[v].erase(d[v].find(*R - x));
	if(L != pos[v].begin()) {
		L--;
		d[v].erase(d[v].find(x - *L));
	}
	if(R != pos[v].end() and R != pos[v].begin()) {
		d[v].emplace(*R - *L);
	}
}

void ins(int x, int v) {
	A[x] = v;
	auto R = pos[v].upper_bound(x);
	auto L = R;
	if(R != pos[v].end()) d[v].emplace(*R - x);
	if(L != pos[v].begin()) {
		L--;
		d[v].emplace(x - *L);
	}
	if(R != pos[v].end() and R != pos[v].begin()) {
		d[v].erase(d[v].find((*R) - (*L)));
	}
	pos[v].emplace(x);
}

void update(int x, int v) {
	del(x);
	ins(x, v);
}

int query(int v) {
	return d[v].empty() ? 0 : *d[v].begin();
}

int idx(int x) { return lower_bound(all(coor), x) - coor.begin();}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	coor.emplace_back(0);
	while(m--) {
		int a, b; scanf("%d %d", &a, &b);
		Q.emplace_back(a, b);
		coor.emplace_back(b);
	}
	sort(all(coor));
	coor.resize(unique(all(coor)) - coor.begin());
	for(int i = 1; i <= n; ++i) {
		pos[0].emplace(i);
		if(i != n) d[0].emplace(1);
	}
	long sum = 0;
	for(auto x : Q) {
		update(x.x, idx(x.y));
		sum += query(idx(x.y));
	}
	printf("%lld\n", sum);
}