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

int n, m, k;
vector<int> A[100005];
int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> m >> k;
	while(n--) {
		int a = input();
		A[a%k].emplace_back(a);
	}
	for(int i = 0; i < k; ++i) {
		if(A[i].size() >= m) {
			puts("Yes");
			for(int j = 0; j < m; ++j) printf("%d ", A[i][j]); 
			printf("\n");
			return 0;
		}
	}
	return puts("No");
}