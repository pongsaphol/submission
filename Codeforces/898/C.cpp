#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
}

map<string, vector<string> > M;

int main() {
	red();
	int n = input();
	while(n--) {
		string name;
		cin >> name;
		int T = input();
		while(T--) {
			string now;
			cin >> now;
			M[name].emplace_back(now);
		}
	}
	map<string, set<string> > ans;
	for(auto &x:M) {
		auto &now = x.y;
		for(int i = 0; i < now.size(); ++i) {
			if(now[i] == "-1") continue;
			 for(int j = 0; j < now.size(); ++j){
				if(now[j] == "-1") continue;
				if(now[i].rfind(now[j]) != -1) {
					if(now[i].size() == now[j].size()) continue;
					if(now[i].rfind(now[j]) + now[j].size() == now[i].size()) {
						now[j] = "-1";
					}
				}
			}
		}
		int cnt = 0;
		for(int i = 0; i < now.size(); ++i) {
			if(now[i] != "-1") cnt++;
		}
		if(cnt != 0) {
			for(int i = 0; i < now.size(); ++i) {
				if(now[i] != "-1") ans[x.x].emplace(now[i]);
			}
		}
	}
	cout << ans.size() << endl;
	for(auto x:ans) {
		cout << x.x << " " << x.y.size();
		for(auto y:x.y) cout << " " << y;
		cout << endl;
	}
}