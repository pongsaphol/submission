#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define mem(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
#ifdef INPUT
#define dbg(x) cout << "debug : " <<  x << endl
#define dbg2(x, xx) cout << "debug : " << x << " : " << xx << endl 
#else
#define dbg(x)
#define dbg2(x, xx)
#endif
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.tie(0);
	cin.sync_with_stdio(false);
}

int A[105];

int main() {
	red();
	int n = input(), m = input();	
	while(n--) {
		int a, b;
		cin >> a >> b;
		A[a]++;
		A[b]--;
	}
	bool st = A[0] == 0;
	for(int i = 1; i < m; ++i) {
		A[i] += A[i-1];
		if(A[i] == 0) st = true;
	}
	if(st) puts("NO");
	else puts("YES");
}