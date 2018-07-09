#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

int n, m, A[2][100005];

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	set<int> S;
	A[0][0] = 1e9+7;
	A[1][n+1] = 1e9+7;
	for(int i = 1; i <= n; ++i) {
		int x = input();
		A[0][i] = x;
		A[0][i] = min(A[0][i], A[0][i-1]);
		A[1][i] = x;
		S.insert(x);
	}
	int mn = -1e9-7;
	for(int i = n; i >= 1; --i) {
		A[1][i] = min(A[1][i], A[1][i+1]);
		if(i != 1)mn = max(mn, max(A[1][i], A[0][i-1]));
	}
	if(m  == 1) return !printf("%d\n", *S.begin());
	else if(m > 2) return !printf("%d\n", *S.rbegin());
	else return !printf("%d\n", mn);
}