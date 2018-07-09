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
map<int, int> X, Y;
map<P, int> coor;
int main() {
	red();
	int n = input();
	long ans = 0;
	while(n--) {
		int a = input(), b = input();
		ans += X[a] + Y[b] - coor[{a, b}];
		X[a]++, Y[b]++;
		coor[{a, b}]++;
	}
	cout << ans << endl;
}