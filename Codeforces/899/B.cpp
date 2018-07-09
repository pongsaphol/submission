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

int A[105] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
			 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
			 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
			 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
			 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
			 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int n, I[40];

int main() {
	red();
	n = input();
	for(int i = 0; i < n; ++i) I[i] = input();
	for(int i = 0; i < 48; ++i) {
		bool st = true;
		for(int j = 0; j < n; ++j) {
			if(A[i+j] != I[j]) st = false;
		}
		if(st) return puts("YES")&0;
	}
	puts("NO");
}