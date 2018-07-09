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

const int MAXN = 1e5+5;

char A[MAXN];

int main() {
	red();
	scanf("%s", A);
	int len = strlen(A);
	bool st = false;
	for(int i = 0; i < len; ++i) {
		if(!st && A[i] == '0') st = true;
		else if(!st && i == len-1) continue;
		else printf("%c", A[i]);
	}
	return puts("")&0;
}