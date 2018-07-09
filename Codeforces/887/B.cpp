#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
#include <functional>
#include <iterator>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

int n;
char A[4][10];
bool chk[1005];
int pr[10];
int cache[10];
void f() {
	int now = 0;
	for(int i = 0; i < n; ++i) {
		// printf("%d ", pr[i]);
		if(pr[i] != -'0') now = now*10 + pr[i];
	}
	// printf("\n");
	chk[now] = true;
	// printf("%d\n", now);
}

void rec(int lv) {
	if(lv == n) {
		for(int i = 0; i < lv; ++i) {
			pr[i] = cache[i];
		}
		f();
		swap(pr[1], pr[2]);// 132
		f();
		swap(pr[0], pr[1]);//312
		f();
		swap(pr[0], pr[2]);//213
		f();
		swap(pr[1], pr[2]);//231
		f();
		swap(pr[1], pr[0]);//231
		f();
		return;
	}
	for(int i = 0; i <= 6; ++i) {
		cache[lv] = A[lv][i]-'0';
		rec(lv+1);
	}
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
	n = input();
	for(int i = 0; i < n; ++i) {
		for(int j = 1; j <= 6; ++j) {
			int now = input();
			A[i][j] = now+'0';
		}
	}
	rec(0);
	for(int i = 1; i <= 1000; ++i) {
		if(!chk[i]) return !printf("%d\n", i-1);
	}
}