#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
queue<int> Q;

void read() {
	scanf("%d%d", &n, &m);
	int T;
	scanf("%d", &T);
	while(T--) {
		int now;
		scanf("%d", &now);
		Q.push(now);
	}
}

int solve() {
	int st = 1, ed = m;
	int sum = 0;
	while(!Q.empty()) {
		int now = Q.front();
		Q.pop();
		if(now > ed) {
			int d = now-ed;
			ed += d;
			st += d;
			sum += d;
		}else if(now < st) {
			int d = st-now;
			ed -= d;
			st -= d;
			sum += d;
		}
	}
	return sum;
}

int main() {
	read();
	printf("%d\n", solve());
}