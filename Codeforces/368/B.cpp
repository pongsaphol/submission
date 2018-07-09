#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
}

const int MAXN = 1e5+5;

int n, m, A[MAXN], ans[MAXN];
vector<int> X[MAXN];

int main() {
	red();
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) A[i] = input();
	for(int i = 1; i <= m; ++i) X[input()].emplace_back(i);	
	set<int> S;
	for(int i = n; i >= 1; --i) {
		S.emplace(A[i]);
		for(auto v:X[i]) ans[v] = S.size();
	}
	for(int i = 1; i <= m; ++i) cout << ans[i] << endl;
}