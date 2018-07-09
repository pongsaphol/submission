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

int A[1005];

int main() {
	red();
	int n = input();
	set<int> S;
	int num = -1;
	for(int i = 1; i <= n; ++i) {
		A[i] = input();
		if(num == -1) num = A[i];
		else num = __gcd(A[i], num);
		S.insert(A[i]);
	}
	if(S.find(num) != S.end()) {
		printf("%d\n", n);
		for(int i = 1; i <= n; ++i) printf("%d ", A[i]);
	} else puts("-1");

}