#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

const int MAXN = 1e5+5;
int n, m, A[MAXN];
void read() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
	}
}

bool f(int mid) {
	priority_queue<int, vector<int>, greater<int> > Q;
	priority_queue<P, vector<P>, greater<P> > L; 
	for(int i = 1; i <= n; ++i) Q.push(A[i]);
	int now_k = m;
	for(int i = 1; i <= mid; ++i) {
		while(!L.empty() && L.top().x == i) {
			Q.push(L.top().y);
			L.pop();
		}
		if(Q.empty()) return false;
		int x = Q.top();
		Q.pop();
		if(now_k > 0) {
			L.push({i+x+1, x});
			now_k--;
		}
	}
	return true;
}

int solve() {
	int L = n, R = 2e5;
	while(L < R) {
		int mid = (L+R+1)/2;
		if(f(mid)) L = mid;
		else R = mid-1;
	}
	return L;
}

int main() {
	//freopen("r", "r", stdin);
	read();
	printf("%d\n", solve());
}