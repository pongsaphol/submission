#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1e4+5;

int n, m, s, t, d[2][MAXN];
vector<P> g[MAXN];

struct data {
	int lv, u, w;
};

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m >> s >> t;
	while(m--) {
		int u = input(), v = input(), w = input();
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	fill_n(d, 2*MAXN, 1e9);
	
}