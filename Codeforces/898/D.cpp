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

const int MAXN = 1e6+5;

int t[MAXN], ep[MAXN];

int main() {
	red();
	int n, m, k;
	cin >> n >> m >> k;
	while(n--) t[input()]++;
	int sum = 0;
	for(int i = 1; i <= m; ++i) sum += t[i];
	vector<P> V;
	if(sum >= k) V.emplace_back(m, 1);
	for(int i = m+1; i < MAXN; ++i) {
		sum += t[i] - t[i-m];
		if(sum >= k) V.emplace_back(i, i-m+1);
	}
	sort(all(V));
	int last = 0, cnt = 0;
	for(auto x:V) {
		printf("%d %d\n", x.x, x.y);
		if(last >= x.y) continue;
		cnt++;
		last = x.x;
	}
	// cout << cnt;
}