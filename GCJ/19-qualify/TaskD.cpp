#include <bits/stdc++.h>
using namespace std;

const int N = 1<<11;

int n, b, f;
vector<int> l, r;

char output[N];
char input[N];
bool ans[N];

void init() {
	memset(output, 0, sizeof output), memset(input, 0, sizeof input), memset(ans, 0, sizeof ans);
	n, b, f = 0;
	l.clear(), r.clear();
}

int solve() {
	init();
	cin >> n >> b >> f;
	l = vector<int>(n, -1), r = vector<int>(n, -1);
	for(int i = 0; i < n; ++i) output[i] = (i >> 4 & 1) + '0';
	cout << output << endl;
	cin >> input;
	for(int i = 0, s = 0, x = 0, y = 15; i < n-b; ++i) if(input[i] != input[i+1]) {
		for(int j = x; j <= min(y, n-1); ++j) l[j] = s, r[j] = i;
		x += 16, y += 16, s = i+1;	
	}
	for(int i = 0; i < n; ++i) if(l[i] == -1) ans[i] = true;
	for(int bt = 3; ~bt; --bt) {
		for(int i = 0; i < n; ++i) output[i] = (i >> bt & 1) + '0';	
		cout << output << endl;
		cin >> input;
		for(int i = 0; i < n; ++i) if(!ans[i]) {
			int ft = -1, se;
			for(int j = l[i]; j <= r[i]; ++j) if(input[j] == output[i]) {
				se = j;
				if(ft == -1) ft = j;
			}
			if(ft == -1) ans[i] = true;
			else l[i] = ft, r[i] = se;
		}
	}
	for(int i = 0; i < n; ++i) if(ans[i]) cout << i << ' ';
	cout << endl;
	int status; cin >> status;
	return status;
}

int main() {
	int T; cin >> T;
	for(int i = 0; i < T; ++i) {
		if(solve() == -1) return 0;
	}
}
