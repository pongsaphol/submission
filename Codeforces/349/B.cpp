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

int A[10], ans[1000005];

int main() {
	red();
	int n = input(), mn = 1e9, idx;
	for(int i = 1; i < 10; ++i) {
		A[i] = input();
		if(A[i] <= mn) {
			mn = A[i];
			idx = i;
		}
	}
	int len = n/mn;
	n = n-(len*mn);
	if(len == 0) return puts("-1")&0;
	for(int i = 0; i < len; ++i) {
		ans[i] = idx;
		for(int j = 9; j > 0; --j) {
			if(j <= ans[i]) break;
			if(n + A[ans[i]] - A[j] >= 0) {
				n = n + A[ans[i]] - A[j];
				ans[i] = j;
			}
		}
		printf("%d", ans[i]);
	}

}