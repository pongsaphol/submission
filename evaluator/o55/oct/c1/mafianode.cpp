#include <iostream>
#include <set>
#include <algorithm>
#include <functional>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define input(T) (*istream_iterator<T>(cin))
using namespace std;

const int MAXN = 1e6+5;

int n, l, r, A[MAXN];
set<P> S;

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> l >> r;
	l += r;
	for(int i = 1; i <= n; ++i) S.emplace(0, i);
	while(l--) {
		char c = input(char);
		if(c == 'L') {
			int a = input(int), b = input(int);
			S.erase({A[b], b});
			A[b]++;
			S.emplace(A[b], b);
		} else if (c == 'C') {
			int a = input(int), b = input(int);
			S.erase({A[b], b});
			A[b] += 3;
			S.emplace(A[b], b);
		} else if(c == 'R') {
			printf("%d\n", S.rbegin()->y);
		} else {
			r--;
			S.erase(--S.end());
		}
		// while(S.size() > r) S.erase(S.begin());
	}
}