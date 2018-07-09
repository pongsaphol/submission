#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

int n, m, inf = 1e6+5;
vector<P> V;

bool f(int M) {
	bool st = false;
	int l = 0, r = 0;
	multiset<int> S;
	while(1) {
		if(V[r].x - V[l].x <= M && r < V.size()) {
			S.insert(V[r].y);
			r++;
		} else {
			multiset<int>::iterator it = S.begin(), it2 = S.end();
			it2--;
			if(*it2 - *it >= m) st = true;
			S.erase(S.find(V[l].y));
			l++;
			if(r == V.size()) break;
		}
	}
	return st;
}

int bsearch() {
	int L = 1, R = inf, mid;
	while(L < R) {
		mid = (L+R)/2;
		if(f(mid)) R = mid;
		else L = mid+1;
	}
	return R;
}

void solve() {
	V.clear();
	scanf("%d%d", &n, &m);
	V.reserve(n);
	while(n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		V.emplace_back(a, b);
	}
	sort(V.begin(), V.end());
	int ans = bsearch();
	if(ans == inf) printf("-1\n");
	else printf("%d\n", ans);
}

int main() {
	// freopen("r", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) solve();
}