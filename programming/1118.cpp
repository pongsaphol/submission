#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#define P pair<int,int> 
#define x first
#define y second
using namespace std;

int n;
bool arr[20][20], _copy[20][20];
bool wgen[20];

void solve() {
	queue<P> Q;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			_copy[i][j] = arr[i][j];
		}
	}
	for(int j = 1; j <= n; ++j) {
		if(wgen[j]){
			_copy[1][j] = !_copy[1][j];
			_copy[2][j] = !_copy[2][j];
			_copy[1][j-1] = !_copy[1][j-1];
			_copy[1][j+1] = !_copy[1][j+1];
			Q.push({1,j});
		} 
	}
	for(int i = 2; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(_copy[i-1][j]) {
				_copy[i][j] = !_copy[i][j];
				_copy[i-1][j] = !_copy[i-1][j];
				_copy[i+1][j] = !_copy[i+1][j];
				_copy[i][j-1] = !_copy[i][j-1];
				_copy[i][j+1] = !_copy[i][j+1];
				Q.push({i,j});
			}
		}
	}
	bool st = false;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			st |= _copy[i][j];
		}
	}
	if(!st) {
		printf("%d\n", Q.size());
		while(!Q.empty()) {
			printf("%d %d\n", Q.front().x, Q.front().y);
			Q.pop();
		}
	}
}

void gen(int lv){
	if(lv > n) {
		//do something;
		solve();
		return;
	}
	wgen[lv] = 0;
	gen(lv + 1);
	wgen[lv] = 1;
	gen(lv + 1);
}

int main() {
	// freopen("r", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			int now;
			scanf("%d", &now);
			if(now == 1) arr[i][j] = true;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			int now;
			scanf("%d", &now);
			if(now == 1) arr[i][j] = !arr[i][j];
		}
	}
	// for(int i = 1; i <= n; ++i) {
	// 	for(int j = 1; j <= n; ++j) {
	// 		arr[i][j] = arr[i][j];
	// 	}
	// }
	gen(1);
}