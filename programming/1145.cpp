#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main() {
	// freopen("r", "r", stdin);
	int T = 4;
	while(T--) {
		string now;
		cin >> now;
		for(auto &x:now) {
			if(x >= 'A' && x <= 'Z') x = x-'A'+'a';
		}
		int sz = now.size();
		set<string> S;
		for(int i = 0; i < sz; ++i) {
			for(int j = i; j < sz; ++j) {
				string tp;
				for(int k = i; k <= j; ++k) tp.push_back(now[k]);
				S.insert(tp);
			}
		}
		for(auto &x:S) m[x]++;
	}
	vector<pair<int, string> > V;
	int mx = 0;
	for(auto x:m) if(x.second >a= 3) {
		mx = max(mx,(int)x.first.size());
		V.emplace_back(x.first.size(), x.first);
	}
	sort(V.begin(), V.end());
	for(auto x:V) {
		if(x.first == mx) {
			cout << x.second << endl;
			return 0;
		}
	}
}