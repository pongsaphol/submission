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

const int MAXN = 5e5+5;

long pf[MAXN], sf[MAXN];
int n, A[MAXN];

int main() {
	red();
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		pf[i] = pf[i-1] + A[i];
	}
	map<long, int> M;
	for(int i = n; i >= 1; --i) {
		sf[i] = sf[i+1] + A[i];
		M[sf[i]]++;
	}
	long cnt = 0;
	M[sf[1]]--;
	for(int i = 1; i <= n-2; ++i) {
		M[sf[i+1]]--;
		if(pf[n] == 3ll*pf[i]) cnt += M[pf[i]];
	}
	cout << cnt;
}