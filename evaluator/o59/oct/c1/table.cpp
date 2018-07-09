/*
TASK: o59_oct_c1_table
*/
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

int r, c, m, inf = 1e9 + 1;
multiset<int> S[305];
multiset<int>::iterator it;
P s[305], arr[305][5005];// x is val, y is time

void setv(int t) {
	int x, y, val;
	scanf("%d%d%d", &x, &y, &val);
	if(arr[x][y].y > s[x].y) {
		S[x].erase(S[x].find(arr[x][y].x));
	}
	arr[x][y] = {val,t};
	S[x].insert(val);
}

void setrv(int t) {
	int x, val;
	scanf("%d%d", &x, &val);
	s[x] = {val,t};
	S[x].clear();
}

int getv() {
	int x, y;
	scanf("%d%d", &x, &y);
	if(arr[x][y].y < s[x].y) return s[x].x;
	return arr[x][y].x;
}

int getm() {
	int ret = inf;
	// while(1) printf("1\n");
	for(int i = 1; i <= r; ++i) {
		if(S[i].size() == c) ret = min(ret, *(S[i].begin()));
		else if(S[i].size() == 0) ret = min(ret, s[i].x);
		else ret = min(ret, min(s[i].x,*(S[i].begin())));
	}
	if(ret == inf) return 0;
	return ret;
}
int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d%d", &r, &c, &m);
	for(int i = 1; i <= m; ++i) {
		int met;
		scanf("%d", &met);
		if(met == 1) setv(i);
		if(met == 2) setrv(i);
		if(met == 3) printf("%d\n", getv());
		if(met == 4) printf("%d\n", getm());
	}
}