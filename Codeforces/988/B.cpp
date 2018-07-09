#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<string> V;
	while(n--) {
		string ret; cin >> ret;
		V.emplace_back(ret);
	}
	sort(V.begin(), V.end(), [&](const string &a, const string &b) {
		return a.size() < b.size();
	});
	for(int i = 0; i < V.size() - 1; ++i) {
		if(V[i+1].find(V[i]) == string::npos) return !printf("NO");
	}
	puts("YES");
	for(auto &x : V) cout << x << endl;
}