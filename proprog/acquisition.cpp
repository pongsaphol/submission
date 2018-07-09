#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> Q;
int n, a, b, arr[105];

int f(int x) {
	if(x < a || x > b) return 0;
	int mn = 1e9;
	for(int i = 1; i <= n; ++i) {
		mn = min(mn, abs(arr[i] - x));
	}
	return mn;
}

int main() {
	freopen("r", "r", stdin);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", arr+i);
	}
	sort(arr+1, arr+n+1);
	for(int i = 1; i <= n; ++i) {
		if(i >= 2) {
			int d = (arr[i] + arr[i-1])/2;
			if(d%2) Q.push(d);
			else Q.push(d-1), Q.push(d+1);
		}
	}
	scanf("%d%d", &a, &b);
	if(a%2) Q.push(a);
	else Q.push(a+1);
	if(b%2) Q.push(b);
	else Q.push(b-1);
	int ans = 0, mxidx = 0;// 
	while(!Q.empty()) {
		int now = Q.front();
		Q.pop();
		int ret = f(now);
		if(ret > ans) {
			ans = ret;
			mxidx = now;
		}
	}
	printf("%d\n", mxidx);
}