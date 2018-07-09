#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define long long long
using namespace std;

const int N = 1e5+5;

int n, m;
long ans;
vector<vector<int> > g(N);
vector<vector<pii> > hsh(N);
pii add(pii a, pii b) { return pii(a.x + b.x, a.y + b.y); }
pii mul(pii a, pii b) { return pii(a.x * b.x, a.y * b.y); }
pii sub(pii a, pii b) { return pii(a.x - b.x, a.y - b.y); }
pii pwith[N], iden(131, 133); // I wll use hsh 131, 133

int main() {
	scanf("%d %d", &n, &m);
	pwith[0] = pii(1, 1);
	for(int i = 1; i <= n; ++i) pwith[i] = mul(pwith[i-1], iden), g[i].emplace_back(0), hsh[i].emplace_back(0, 0);
	while(m--) {
		int a, b; scanf("%d %d", &a, &b);
		g[a].emplace_back(b), g[b].emplace_back(a);
	}
	for(int i = 1; i <= n; ++i) sort(all(g[i]));
	map<pii, int> type1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < g[i].size(); ++j) {
			hsh[i].emplace_back(g[i][j], g[i][j]);
			hsh[i][j] = add(hsh[i][j], mul(hsh[i][j-1], iden));
		}
		type1[hsh[i].back()]++;
	}
	for(auto x : type1) ans += (1ll * x.y * x.y - x.y) >> 1;
	for(int i = 1; i <= n; ++i) {
		for(auto x : g[i]) if(x > i) {
			int p1 = lower_bound(all(g[i]), x) - g[i].begin();
			pii lhs = add(sub(hsh[i].back(), mul(hsh[i][p1], pwith[hsh[i].size()-p1-1])), mul(hsh[i][p1-1], pwith[hsh[i].size()-p1-1]));
			int p2 = lower_bound(all(g[x]), i) - g[x].begin();
			pii rhs = add(sub(hsh[x].back(), mul(hsh[x][p2], pwith[hsh[x].size()-p2-1])), mul(hsh[x][p2-1], pwith[hsh[x].size()-p2-1]));
			if(lhs == rhs) ans++;
		}
	}
	printf("%lld\n", ans);
}