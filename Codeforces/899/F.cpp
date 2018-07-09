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

const int MAXN = 2e5+5;

char A[MAXN];
int n, m, t[MAXN];
set<int> S[128];

int query(int x) {
	int sum = 0;
	while(x >= 1) {
		sum += t[x];
		x -= x&-x;
	}
	return sum;
}

void update(int x) {
	while(x <= n) {
		t[x]--;
		x += x&-x;
	}
}

int main() {
	red();
	scanf("%d%d", &n, &m);
	scanf("%s", A+1);
	for(int i = 1; i <= n; ++i) {
		S[A[i]].insert(i);
		t[i] = i&-i;
	}
	while(m--) {
		int l, r;
		char c;
		scanf("%d%d %c", &l, &r, &c);
		int L = 1, R = n;
		while(L < R) {
			int mid = (L + R) / 2;
			if(query(mid) >= l) R = mid;
			else L = mid+1;
		}
		l = R;
		L = 1, R = n;
		while(L < R) {
			int mid = (L + R+1) / 2;
			if(query(mid) <= r) L = mid;
			else R = mid-1;
		}
		r = L;
		auto it = S[c].lower_bound(l);
		auto it2 = S[c].upper_bound(r);
		while(it != it2) {
			update(*it);
			auto now = it;
			it++;
			S[c].erase(now);
		}
	}
	int pv = 0;
	for(int i = 1; i <= n; ++i) {
		if(query(i) != pv) {
			pv++;
			printf("%c", A[i]);
		}
	}
}