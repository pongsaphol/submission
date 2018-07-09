#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

char A[105];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
	scanf("%s", A+1);
	int len = strlen(A+1);
	int cntz = 0;
	for(int i = len; i >= 1; --i) {
		if(A[i] == '0') cntz++;
		if(cntz >= 6 && A[i] == '1') return !printf("yes\n");
	}
	return !printf("no\n");
}