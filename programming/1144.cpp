#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, k, score[1005];
vector<int> X[1005], Y[1005], t[1005];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < k; ++k) {
			int now;
			scanf("%d", &now);
			X[i].push_back(now);
		}
		for(int j = 0; j < k; ++k) {
			int now;
			scanf("%d", &now);
			Y[i].push_back(now);
		}
	}
	for(int i = 1; i <= m; ++i) {
		for(int j = 0; j < k; ++j) {
			int now;
			scanf("%d", &now);
			t[i].push_back(now);
		}
	}
	// I will count score;
	for(int i = 1; i <= n; ++i) {
		bool st = true;
		
	}
}