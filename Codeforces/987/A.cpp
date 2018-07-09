#include <bits/stdc++.h>
using namespace std;

map<string, string> M;

int main() {
	M["Power"] = "purple";
	M["Time"] = "green";
	M["Space"] = "blue";
	M["Soul"] = "orange";
	M["Reality"] = "red";
	M["Mind"] = "yellow";
	int n; cin >> n;
	while(n--) {
		string z; cin >> z;
		for(auto it = M.begin(); it != M.end(); ++it) {
			if(it->second == z) {
				M.erase(it);
				break;
			}
		}
	}
	printf("%d\n", M.size());
	for(auto x : M) cout << x.first << endl;
}