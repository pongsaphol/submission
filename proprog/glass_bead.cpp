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

const int MAXN = 1e4+5;

int n, ord[MAXN], cache[MAXN];
char A[MAXN];
pair<P, int> V[MAXN];

void cmpidx() {
	sort(V, V+n);
	int idx = cache[0] = 1;
	for(int i = 1; i < n; ++i) cache[i] = idx+=(V[i].x != V[i-1].x);
	for(int i = 0; i < n; ++i) V[i].x.x = ord[V[i].y] = cache[i];	
}

int solve() {
	scanf("%s", A);
	n = strlen(A);
	for(int i = 0; i < n; ++i) V[i] = {{0, A[i]}, i};
	cmpidx();
	for(int i = 1; i < n; i<<=1) {
		for(int j = 0; j < n; ++j) V[j].x.y = ord[(V[j].y+i)%n];
		cmpidx();
	}
	for(int i = 0; i < n; ++i) if(ord[i] == 1) return i+1;
}

int main() {
	red();
	int T;
	scanf("%d", &T);
	while(T--) printf("%d\n", solve());
}