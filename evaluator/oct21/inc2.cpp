#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	int n = input();
	vector<int> V;
	while(n--) {
		int now = input();
		auto it = lower_bound(all(V), now);
		if(it == V.end() V.emplace_back(now);
		else *it = now;
	}
	printf("%d\n", V.size());
}