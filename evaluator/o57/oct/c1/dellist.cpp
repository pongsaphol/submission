#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <set>
#include <vector>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1e5+5;

int n, m, son[MAXN], par[MAXN], back[MAXN];
vector<int> V[MAXN];
set<int> S[MAXN];

void upd(set<int> &s, int x) {
	if(x == 0) return;
	int idx = 0;
	for(auto now:V[x]) {
		if(s.find(now) == s.end()) {
			V[x][idx++] = now;
		}
	}
	V[x].resize(idx);
	upd(s, son[x]);
}

void print(int x) {
	if(x == 0) return;
	for(auto now:V[x]) printf("%d\n", now);
	print(son[x]);
}

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	n = input(), m = input();
	for(int i = 1; i <= n; ++i) {
		son[i] = 0;
		par[i] = i;
		back[i] = i;
		int len = input();
		while(len--) {
			int now = input();
			V[i].emplace_back(now);
		}
	}
	while(m--) {
		int met = input(), a = input(), b = input();
		if(met == 1) if(par[a] != 0) S[par[a]].emplace(b);
		else {
			upd(S[par[a]], par[a]);
			upd(S[par[b]], par[b]);
			if(par[a] == 0 && par[b] == 0) continue;
			if(par[a] == 0 && par[b] != 0) {
				par[a] = par[b];
				back[a] = back[b];
				par[b] = 0;
				back[b] = 0;
			}
			if(par[a] != 0 && par[b] == 0) continue;
			if(par[a] != 0 && par[b] != 0) {
				son[back[a]] = par[b];
				back[a] = back[b];
				par[b] = 0;
				back[b] = 0;
			}
		}
	}
	for(int a = 1; a <= n; ++a) {
		upd(S[par[a]], par[a]);
		print(par[a]);
	}
	return 0;
}
