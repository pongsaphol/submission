#include <iostream>
#include <cstring>
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

int idx, ans[1005];

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	int n = input();
	char A[1005];
	for(int i = 0; i <= 200; ++i) {
		int now = n - i;
		if(now <= 0) break;
		sprintf(A, "%d", now);
		int len = strlen(A), sum = 0;
		for(int j = 0; j < len; ++j) {
			sum += A[j] - '0';
		} 
		if(sum == i) ans[idx++] = now;
	}
	printf("%d\n", idx);
	sort(ans, ans+idx);
	for(int i = 0; i < idx; ++i) {
		printf("%d\n", ans[i]);
	}
}