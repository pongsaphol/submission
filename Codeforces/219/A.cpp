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
	int n;
	scanf("%d", &n);
	scanf("%s", A+1);
	int len = strlen(A+1);
	map<char,int> M;
	for(int i = 1; i <= len; ++i) M[A[i]]++;
	for(auto x:M) if(x.y % n != 0) return puts("-1")&0;
	for(int i = 0; i < n; ++i) for(auto x:M) for(int j = 0; j < x.y/n; ++j) printf("%c", x.x);
}