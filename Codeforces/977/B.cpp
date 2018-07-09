#include <bits/stdc++.h>
using namespace std;

int n, mx;
string str;

int main() {
	cin >> n;
	cin >> str;
	map<string, int> M;
	for(int i = 0; i < n-1; ++i) {
		string ret;
		ret.push_back(str[i]);
		ret.push_back(str[i+1]);
		M[ret]++;
		mx = max(mx, M[ret]);
	}
	for(auto x : M) if(x.second == mx) {
		cout << x.first;
		return 0;
	}
}