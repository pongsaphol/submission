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

int memo[10005];

void find(int x) {
	int now = 0;
	int cnt = 0;
	do {
		now = (now<<1) + (now<<3) + 1;
		now %= x;
		cnt++;
	} while(now != 0);
	memo[x] = cnt;
}

int main() {
	red();
	for(int i = 1; i <= 10000; ++i) {
		if(i%2 != 0 && i%5 != 0) find(i);
	}
	int n;
	while(scanf("%d", &n) != EOF) printf("%d\n", memo[n]);
}