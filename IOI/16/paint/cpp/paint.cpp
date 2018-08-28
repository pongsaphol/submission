#include "paint.h"
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

int n, pf_[N], cnt[N], pref[N][105], cc[N][2];
char ret[N], ans[N];
bool z[N][105], pf[N][105], vaid[N][105];

string solve_puzzle(string s, vector<int> C) {
	vector<int> c; c.emplace_back(0);
	for(int x : C) c.emplace_back(x);
	for(int i = 0; i < s.size(); ++i) ret[i+1] = s[i];
	n = s.size();
	for(int i = 1; i <= n; ++i) pf_[i] = pf_[i-1] + (ret[i] == '_');
	pf[0][0] = 1;
	for(int i = 0; i <= n; ++i) if(ret[i] != 'X') pf[i][0] |= pf[i-1][0];
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < c.size(); ++j) {
			if(i < c[j]) continue;
			if(pf_[i] - pf_[i-c[j]] == 0) 
				if(z[i][j] = pf[i-c[j]][j-1]) pref[i+1][j]--, pref[i-c[j]+1][j]++, cnt[j]++;
			if(ret[i] != 'X') pf[i][j] |= pf[i-1][j] | z[i-1][j];
		}
	}
	int p = n, id = C.size();
	while(p && id) {
		if(z[p][id]) {
			for(int j = p+1; j <= n; ++j) if(z[j][id]) cnt[id]--, z[j][id] = 0, pref[j+1][id]++, pref[j-c[id]+1][id]--;
			p -= c[id--];
		}
		p--;
	}
	
	for(int j = 1; j < c.size(); ++j) {
		for(int i = 1; i <= n; ++i) {
			pref[i][j] += pref[i-1][j];
			if(pref[i][j] == cnt[j]) cc[i][0]++;
			else if(pref[i][j]) cc[i][1]++;
		}
	}
	string ans;
	for(int i = 1; i <= n; ++i) {
		if(cc[i][0]) ans.push_back('X');
		else if(cc[i][1]) ans.push_back('?');
		else ans.push_back('_');
	}
	return ans;
}
