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

int A[3];

int main() {
	red();
	int n = input();
	while(n--) for(int i = 0; i < 3; ++i) A[i] += input();
	if(A[0] == 0 && A[1] == 0 && A[2] == 0) return puts("YES")&0;
	return puts("NO")&0;
}