#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

struct data {
	int A[10];
};

data plu(const data &a, const data &b) {
	data ret;
	for(int i = 0; i < 10; ++i) ret.A[i] = b.A[a.A[i]];
	return ret;
}

const int MAXN = 1<<17;

data t[MAXN<<2];
pair<int, data> V[MAXN];
vector<int> coor;
int n, m, sz, pos[MAXN];

data iden;
void update(int x, data v, int p = 1, int l = 0, int r = sz) {
	if(l == r) {
		t[p] = v;
		return;
	}
	int m = (l + r) >> 1;
	if(x <= m) update(x, v, p << 1, l, m);
	else update(x, v, p << 1 | 1, m + 1, r);
	t[p] = plu(t[p<<1], t[p<<1|1]);
}  
data query(int x, int p = 1, int l = 0, int r = sz) {
	if(l == r) return t[p];
	int m = (l + r) >> 1;
	if(x <= m) return query(x, p << 1, l, m);
	else return query(x, p << 1 | 1, m+1, r);
}
int idx(int x) { return lower_bound(all(coor), x) - coor.begin(); }
int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	vector<pii> que;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < 10; ++i) iden.A[i] = i;
	for(int i = 1; i <= n; ++i) {
		data ret; int now;
		scanf("%d", &now);
		for(int i = 0; i < 10; ++i) scanf("%d", &ret.A[i]);
		V[i] = make_pair(now, ret);
		coor.emplace_back(now);
	}
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		que.emplace_back(a, b);
		coor.emplace_back(b);
	}
	sort(all(coor)); coor.resize(unique(all(coor)) - coor.begin());
	sz = coor.size();
	for(int i = 4*MAXN-1; i != 0; --i) t[i] = iden;
	for(int i = 1; i <= n; ++i) {
		pos[i] = idx(V[i].x);
		update(pos[i], V[i].y);
	}
	for(auto x : que) {
		data now = query(pos[x.x]);
		update(pos[x.x], iden);
		pos[x.x] = idx(x.y);
		update(pos[x.x], now);
		printf("%d\n", t[1].A[0]);
	}
}