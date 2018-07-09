#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int main() {
	int k; scanf("%d", &k);
	map<int, pii> M;
	for(int i = 1; i <= k; ++i) {
		vector<int> V;
		int n, sum = 0; scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			int ret; scanf("%d", &ret);
			sum += ret;
			V.emplace_back(ret);
		}
		for(int j = 0; j < n; ++j) {
			auto it = M.find(sum - V[j]);
			if(it != M.end()) {
				puts("YES");
				return !printf("%d %d\n%d %d\n", it->y.x, it->y.y, i, j+1);
			}
		}
		for(int j = 0; j < n; ++j) {
			M[sum - V[j]] = pii(i, j+1);
		}
	}
	puts("NO");
}