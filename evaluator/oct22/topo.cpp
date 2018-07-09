#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <iterator>
#include <queue>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1e5+5;

int n, m, deg[MAXN], chk[MAXN];
vector<int> g[MAXN];

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	while(m--) {
		int a = input(), b = input();
		g[a].emplace_back(b);
		deg[b]++;
	}
	queue<int> Q;
	for(int i = 1; i <= n; ++i) if(deg[i] == 0) Q.push(i);
	vector<int> ans;
	while(!Q.empty()) {
		int now = Q.front();
		Q.pop();
		if(chk[now]) return puts("no");
		chk[now] = true;
		ans.emplace_back(now);
		for(auto x:g[now]) if(--deg[x] == 0) Q.push(x);
	}
	for(auto x: ans) printf("%d\n", x);
	return 1-1;
}
