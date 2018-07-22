#include <bits/stdc++.h>
#define long long long 
using namespace std;

int n, m;
vector<string> V;
long dp[25][2];

int main() {
	V.emplace_back("");
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		string ret; cin >> ret;
		V.emplace_back(ret);
	}
	map<string, string> zz;
	map<string, int> M[2];
	cin >> m;
	for(int i = 0; i < m; ++i) {
		string a, b, c;
		cin >> a >> b >> c;
		bool st = c == "correct";
		zz[a] = b;
		M[st][a]++;
	}
	dp[0][1] = 1;
	for(int i = 1; i <= n; ++i) {
		dp[i][0] = (M[1][V[i]] + M[0][V[i]]) * dp[i-1][0] + M[0][V[i]] * dp[i-1][1];
		dp[i][1] = M[1][V[i]] * dp[i-1][1];
	}
	if(dp[n][0] == 1 || dp[n][1] == 1) {
		for(int i = 1; i <= n; ++i) cout << zz[V[i]] << ' ';
		cout << (dp[n][0] ? "incorrect" : "correct");
	} else {
		cout << dp[n][1] << " correct" << endl << dp[n][0] << " incorrect" << endl;
	}
}
