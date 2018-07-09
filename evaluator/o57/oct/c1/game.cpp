#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
#include <stack>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 5005;

vector<int> g[MAXN], rg[MAXN];
int n, m, lv[MAXN], ans[MAXN];
bool chk[MAXN];
stack<int> S;

void dfs(int x) {
	if(chk[x]) return;
	chk[x] = true;
	for(auto v:g[x]) dfs(v);
	S.push(x);
}

int mx = 0;
stack<int> inp;
void scc(int x) {
	if(chk[x]) {
		mx = max(mx, lv[x]);
		return;
	}
	chk[x] = true;
	for(auto v:rg[x]) scc(v);
	inp.push(x);
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	n = input(), m = input();
	while(m--) {
		int u = input(), v = input();
		g[u].emplace_back(v);
		rg[v].emplace_back(u);
	}	
	for(int i = 0; i < n; ++i) dfs(i);
	memset(chk, 0, sizeof chk);
	while(!S.empty()) {
		mx = 0;
		int now = S.top();
		S.pop();
		if(chk[now]) continue;
		scc(now);
		mx++;
		while(!inp.empty()) {
			int x = inp.top();
			inp.pop();
			lv[x] = mx;
			ans[mx]++;
			n--;
		}
	}
	ans[1] += n;
	for(int i = 1; ans[i] != 0; ++i) printf("%d ", ans[i]);
}