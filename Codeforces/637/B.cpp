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

const int MAXN = 2e5 + 5;

char A[MAXN][15];
long H[MAXN];
set<long> S;

void fh(int idx) {
	int len = strlen(A[idx]);
	for(int i = 0; i < len; ++i) H[idx] = H[idx]*26 + A[idx][i] - '0';
}

int main() {
	red();
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", A[i]);
		fh(i);
	}
	for(int i = n; i >= 1; --i) {
		if(S.find(H[i]) == S.end()) {
			printf("%s\n", A[i]);
			S.insert(H[i]);
		}
	}
	return 0;
}