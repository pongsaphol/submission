#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

int n, A[505];
long k;

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	cin >> n >> k;
	queue<int> Q;
	int mx =0;
	int sz = n;
	for(int i = 1; i <= n; ++i){
		int a = input();
		mx = max(mx, a);
		A[i] = a;
	}
	if(k >= n-1) return !printf("%d\n", mx);
	for(int i = 1; i <= n; ++i) {
		bool st = true;
		for(int j = i+1; j <= i+k; ++j) {
			int now = j;
			if(now > n) now = now-n;
			if(A[now] > A[i]) st = false;
		}
		if(st) return !printf("%d\n", A[i]);
	}
}