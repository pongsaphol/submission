#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define long long long
using namespace std;

const int N = 1e5+5;

int n, sz, t[N << 1];
long pref[N], k;
vector<long> coor;

int get(long x) { return lower_bound(all(coor), x) - coor.begin(); }
void update(int x) { for(t[x += sz]++; x != 1; x >>= 1) t[x >> 1] = t[x] + t[x^1]; }
int query(int l, int r) {
	int sum = 0;
	for(l += sz, r += sz+1; l < r; l >>= 1, r >>= 1) {
		if(l & 1) sum += t[l++];
		if(r & 1) sum += t[--r];
	}
	return sum;
}

long f(long m) {
	long sum = 0;
	memset(t, 0, sizeof t);
	for(int i = 1; i <= n; ++i) {
		update(get(-pref[i-1]));
		sum += query(get(m - pref[i]), sz);
	}
	return sum;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %lld", &n, &k);
	for(int i = 1; i <= n; ++i) scanf("%lld", pref+i), pref[i] += pref[i-1];
	for(int i = 0; i <= n; ++i) coor.emplace_back(-pref[i]);
	sort(all(coor));
	coor.resize(unique(all(coor)) - coor.begin());
	sz = coor.size();
	long l = -1e11, r = 1e11;
	while(l < r) {
		long m = (l + r + 1) / 2;
		if(f(m) >= k) l = m;
		else r = m-1;
	}
	printf("%lld\n", l);
}