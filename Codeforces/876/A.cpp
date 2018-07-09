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

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int mn = min(a, b);
	if(n == 1) return puts("0");
	if(c < mn) return !printf("%d\n", mn + (n-2)*c);
	else return !printf("%d\n", (n-1)*mn);
}