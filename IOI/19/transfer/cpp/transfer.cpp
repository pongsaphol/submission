#include <bits/stdc++.h>
#include "transfer.h"
using namespace std;

vector<int> get_attachment(vector<int> source) {
	vector<int> pos;
	int step = 0;
	for(int i = 1;; ++i) {
		if(i >> step & 1) step++;
		else pos.emplace_back(i);
		if(pos.size() == source.size()) break;
	}
	vector<int> ret(step);
	for(int j = 0; j < step; ++j) {
		for(int i = 0; i < pos.size(); ++i) if(pos[i] >> j & 1) ret[j] ^= source[i];
	}
	return ret;
}

vector<int> retrieve(vector<int> data) {
	int n, t;
	if(data.size() < 255) n = 63, t = 7;
	else n = 255, t = 9;
	assert(data.size() == n+t);
	vector<int> pos;
	int step = 0;
	for(int i = 1;; ++i) {
		if(i >> step & 1) step++;
		else pos.emplace_back(i);
		if(pos.size() == n) break;
	}
	vector<vector<int> > ans;
	vector<int> ret(step);
	for(int j = 0; j < t; ++j) {
		for(int i = 0; i < n; ++i) if(pos[i] >> j & 1) ret[j] ^= data[i];
	}	
	vector<int> zz;
	for(int j = n; j < n + t; ++j) if(data[j] != ret[j-n]) zz.emplace_back(j-n);
	if(zz.size() <= 1) return vector<int>(data.begin(), data.end()-t);
	vector<int> kk = pos;
	for(auto z : zz) {
		vector<int> re;
		for(auto v : kk) if(v >> z & 1) re.emplace_back(v);
		kk = re;
	}
	data[lower_bound(pos.begin(), pos.end(), kk[0]) - pos.begin()] ^= 1;
	return vector<int>(data.begin(), data.end()-t);
}
