#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

const int MAXN = 2e6;

int n, m, A[MAXN+5];

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	vector<P> X;
	while(n--) {
		int a = input(), b = input();
		X.emplace_back(a, b);
	}
	while(m--) {
		int mn = 2e9;
		int a = input(), b = input();
		for(auto z:X) mn = min(mn, abs(a-z.x) + abs(b-z.y));
		A[mn] ++;
	}
	int mx = *max_element(A+1, A+MAXN+1);
	printf("%d\n", mx);
}