#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define mem(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
#ifdef INPUT
#define dbg(x) cout << x << endl
#define dbg2(x, xx) cout << x << " : " << xx << endl 
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

int cnt[5];

int main() {
	red();
	int n = input();
	while(n--) {
		cnt[input()]++;
	}
	if(cnt[2] >= cnt[1]) {
		printf("%d\n", cnt[1]);
	} else {
		int sum = cnt[2];
		cnt[1] -= cnt[2];
		sum += cnt[1]/3;
		cout << sum;
	}
	// printf("%d\n", max(min(cnt[1], cnt[2]), cnt[1]/3));
}