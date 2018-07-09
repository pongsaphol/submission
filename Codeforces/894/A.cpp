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

char A[1005];
int main() {
	red();
	scanf("%s", A);
	int cnt = 0;
	int x = strlen(A);
	for(int i = 0; i < x; ++i) {
		for(int j = i+1; j < x; ++j) {
			for(int k = j+1; k < x; ++k) {
				if(A[i] == 'Q' && A[j] == 'A' && A[k] == 'Q') cnt++;
			}
		}
	}
	printf("%d\n", cnt);
}