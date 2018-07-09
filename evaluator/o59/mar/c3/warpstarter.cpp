#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define long long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n, m;
vector<pii> inp;
set<pii> S;
map<int, long> M;
long sum = 0, mn = 1e18;

long d(pii a, pii b) {
	return (long)abs(a.x - b.x) + abs(a.y-b.y);
}

void add(pii x) {
	auto it = S.upper_bound(x);
	if(it == S.begin() and it == S.end()) {
		S.emplace(x);
		return;
	}
	else if(it == S.begin()) sum += M[it->x] = d(x, *it);
	else if(it == S.end()) { it--; sum += M[x.x] = d(*it, x); }
	else {
		sum -= M[it->x];
		sum += M[it->x] = d(x, *it);
		it--;
		sum += M[x.x] = d(*it, x);
	}
	S.emplace(x);
}

void del(pii x) {
	auto it = S.lower_bound(x);
	auto z = S.end(); --z;
	if(it == S.begin()) {
		auto it2 = it; it2++;
		sum -= M[it2->x];
		M[it2->x] = 0;
	} else if(it == z) {
		sum -= M[it->x];
	} else {
		sum -= M[it->x];
		auto it2 = it, it3 = it;
		it3++, it2--;
		sum -= M[it3->x];
		sum += M[it3->x] = d(*it2, *it3);
	}
	auto ii = M.find(x.x);
	if(ii != M.end()) M.erase(ii);
	S.erase(it);
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		inp.emplace_back(a, b);
	}
	sort(all(inp), [](const pii &a, const pii &b) { return a.y < b.y; });
	for(int i = 0; i < m; ++i) 	add(inp[i]);
	mn = min(mn, sum);
	for(int i = m; i < n; ++i) {
		del(inp[i-m]);
		add(inp[i]);
		mn = min(mn, sum);
	}
	printf("%lld\n", mn);
}