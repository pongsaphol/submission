#include <bits/stdc++.h>
#define P pair<int, int>
#define x first
#define y second
using namespace std;

char inp[10], cmp[3][10] = {"insert", "getMin", "removeMin"};

int T, n;
vector<P> ans;
priority_queue<int, vector<int>, greater<int> > Q;

int main() {
	// freopen("r", "r", stdin);
	scanf("%d", &T);
	while(T--) {
		scanf("%s", inp);
		if(!strcmp(cmp[0], inp)) {
			scanf("%d", &n);
			Q.push(n);
			ans.emplace_back(0, n);
		} else if(!strcmp(cmp[1], inp)) {
			scanf("%d", &n);
			while(!Q.empty() && Q.top() < n) {
				Q.pop();
				ans.emplace_back(2, 0);
			}
			if(!Q.empty() && Q.top() == n) ans.emplace_back(1, n);
			else {
				Q.push(n);
				ans.emplace_back(0, n), ans.emplace_back(1, n);
			}
		} else {
			if(Q.empty()) ans.emplace_back(0, -1000000000), ans.emplace_back(2, 0);
			else {
				ans.emplace_back(2, 0);
				Q.pop();
			}
		}
	}
	printf("%d\n", ans.size());
	for(auto x:ans) {
		printf("%s", cmp[x.x]);
		if(x.x != 2) printf(" %d", x.y);
		puts("");
	}
}