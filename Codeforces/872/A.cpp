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

int n, m;
bool is[10], is2[10];

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	int mna = 10, mnb = 10;
	for(int i = 0; i < n; ++i) {
		int now = input();
		mna = min(mna, now);
		is[now] = true;
	}
	for(int i = 0; i < m; ++i) {
		int now = input();
		mnb = min(mnb, now);
		is2[now] = true;
	}
	for(int i = 0; i < 10; ++i) {
		if(is[i] && is2[i]) return !printf("%d\n", i);
	}
	if(mna > mnb) swap(mna, mnb);
	return !printf("%d%d\n", mna, mnb);
}