#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <functional>
#include <iterator>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 1e5+5;

int n, A[MAXN], P[MAXN];

int find(int x) {
	if(P[x] == x) return x;
	return P[x] = find(P[x]);
}

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	n = input();
	for(int i = 1; i <= n; ++i) {
		A[i] = input();
		P[i] = i;
	}
	for(int i = 2; i < n; ++i) {
		int u = input(), v = input();
		u = find(u), v = find(v);
		P[u] = v;
	}
	set<int> S;
	vector<int> V;
	int prev = -1;
	for(int i = 1; i <= n; ++i) {
		int now = find(i);
		if(prev == -1) prev = now;
		if(prev == now) S.emplace(A[i]);
		else V.emplace_back(A[i]);
	}
	int mn = 1e9;
	for(auto x:V) {
		auto it = S.lower_bound(A[x]);
		if(it == S.begin()) mn = min(mn, abs(*it - A[x]));
		else if(it == S.end()) {
			it--;
			mn = min(mn, abs(*it - A[x]));
		} else {
			mn = min(mn, abs(*it - A[x]));
			it--;
			mn = min(mn, abs(*it - A[x]));
		}
	}
	printf("%d\n", mn);
}