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

const int MAXN = 2e5+5;

int n, m, ep[MAXN];

int main() {
	red();
	n = input(), m = input();
	vector<int> V;
	V.reserve(n+5);
	for(int i = 0; i < n; ++i) V.emplace_back(input());
	sort(all(V));
	while(m--) ep[input()]++, ep[input()+1]--;
	vector<int> v;
	for(int i = 1; i <= n; ++i) v.emplace_back(ep[i] += ep[i-1]);
	sort(all(v));
	long sum = 0;
	for(int i = 0; i < n; ++i) sum += (long)v[i] * V[i];
	printf("%I64d\n", sum);
}