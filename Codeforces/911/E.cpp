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

const int MAXN = 2e5+5;

bool ins[MAXN];

int main() {
	red();
	int n, m;
	cin >> n >> m;
	stack<int> S;
	int ptr = 1;
	vector<int> ans;
	while(m--) {
		int now = input();
		ans.emplace_back(now);
		if(now == ptr) {
			ptr++;
		} else {
			S.push(now);
			ins[now] = true;
		}
	}
	while(ptr <= n) {
		while(!S.empty() && )
		if(ins[ptr]) break;
		
		ptr++;
	}
}