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

int main() {
	red();
	int n = input();
	if(n%2) return puts("-1")&0;
	int A[105];
	for(int i = 1; i <= n; ++i) if(i%2 == 0) printf("%d %d ", i, i-1);
	return 0;
}