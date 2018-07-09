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

const int MAXN = 2e5+5;

int A[MAXN];

int main() {
	red();
	int n = input(), m = input();
	for(int i = 1; i <= n; ++i) A[i] = input();
	sort(A+1, A+n+1);
	A[0] = -1e9-1;
	while(m--) {
		int k = input(), p = 0;
		for(int i = (1<<18); i > 0; i >>= 1) if(p+i <= n && A[p+i] <= k) p += i;
		printf("%d ", p);
	}
	printf("\n");
}