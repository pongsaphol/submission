#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

int n, k;

int main() {
	vector<pii> V;
	scanf("%d %d", &n, &k);
	for(int i = 1, ret; i <= n; ++i) {
		scanf("%d", &ret);
		V.emplace_back(ret, i);
	}
	sort(V.begin(), V.end(), greater<pii>());
	vector<int> z;
	int sum = 0;
	for(int i = 0; i < k; ++i) z.emplace_back(V[i].y), sum += V[i].x;
	printf("%d\n", sum);
	sort(z.begin(), z.end());
	int pv = 0;
	for(int i = 0; i < z.size(); ++i) {
		int x = z[i];
		if(i == z.size() - 1) x = n;
		printf("%d ", x - pv);
		pv = x;
	}	
}
