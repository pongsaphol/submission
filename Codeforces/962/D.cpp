#include <bits/stdc++.h>
#define long long long
#define x first
#define y second
using namespace std;

int n;
set<long> vaid;
map<long, set<int> > pos;

int main() {
	scanf("%d", &n);
	for(int i = 1, a; i <= n; ++i) {
		scanf("%d", &a);
		pos[a].emplace(i);
		if(pos[a].size() > 1) vaid.emplace(a);
	}
	while(!vaid.empty()) {
		long num = *vaid.begin();
		pos[num].erase(pos[num].begin());
		int idx = *pos[num].begin();
		pos[num].erase(pos[num].begin());
		if((int)pos[num].size() < 2) vaid.erase(num);
		pos[num<<1].emplace(idx);
		if(pos[num<<1].size() > 1) vaid.emplace(num<<1);	
	}
	vector<pair<int, long>> V;
	for(auto &x : pos) for(auto &y : x.y) V.emplace_back(y, x.x);
	sort(V.begin(), V.end());
	printf("%d\n", V.size());
	for(auto &x : V) printf("%lld ", x.y);

}