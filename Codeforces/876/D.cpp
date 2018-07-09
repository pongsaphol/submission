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

bool chk[300005];

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	int n = input();
	printf("1 ");
	int sum = 1, idx = n;
	for(int i = 1; i <= n; ++i) {
		sum++;
		int now = input();
		chk[now] = true;
		while(chk[idx]) {
			sum--;
			idx--;
		}
		printf("%d ", sum);
	}
	return 0;
}