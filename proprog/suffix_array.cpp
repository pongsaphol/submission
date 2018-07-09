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

const int MAXN = 5e4+5;

char A[MAXN];
int n, ord[MAXN], cache[MAXN];
vector<pair<P, int> > V;

void reidx() {
	sort(all(V));
	int idx = cache[0] = 1;
	for(int i = 1; i < n; ++i) cache[i] += idx+(V[i].x != V[i-1].x);
	for(int i = 0; i < n; ++i) ord[V[i].y] = V[i].x.x = cache[i];
}

int f(int x) {
	if(x > n) return n;
	return x;
}

int main() {
	red();
	scanf("%s", A);
	n = strlen(A);
	for(int i = 0; i < n; ++i) V.emplace_back(make_pair(0, A[i]), i);
	reidx();
	for(int i = 1; i < n; i<<=1) {
		for(int j = 0; j < n; ++j) V[j].x.y = ord[f(V[j].y+i)];
		reidx();
	}
	for(int i = 0; i < n; ++i) printf("%d\n", ord[i]);
}