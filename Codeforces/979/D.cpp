#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int t[300*N][2], st[N], cnt, mnv[300*N];
vector<int> V[N];
bool chk[N];

void upd(int p, int v) {
	for(int i = 16; ~i; --i) {
		if(!t[p][v>>i&1]) t[p][v>>i&1] = ++cnt;
		p = t[p][v>>i&1];
		if(!mnv[p]) mnv[p] = v;
		mnv[p] = min(mnv[p], v);
	}
}

int que(int p, int l, int v) {
	int sum = 0;
	for(int i = 16; ~i; --i) {
		bool is = v >> i & 1;
		if(is) {
			if(t[p][is ^ 1]) p = t[p][is ^ 1];
			else if(mnv[t[p][is]] <= l and t[p][is]) sum |= 1<<i, p = t[p][is];
			else return -1;
		} else {
			if(t[p][is ^ 1] and mnv[t[p][is^1]] <= l) sum |= 1<<i, p = t[p][is ^ 1];
			else if(t[p][is]) p = t[p][is];
			else return -1;
		}
	}
	return sum;
}


int main() {
	int q; scanf("%d", &q);
	for(int i = 1; i <= 100000; ++i) {
		st[i] = ++cnt;
		for(int j = i; j <= 100000; j +=i) V[j].emplace_back(i);
	}
	while(q--) {
		int met, a, b, c;
		scanf("%d", &met);
		if(met == 1) {
			scanf("%d", &a);
			if(chk[a]) continue;
			chk[a] = true;
			for(auto x : V[a]) upd(st[x], a);
		} else {
			scanf("%d %d %d", &a, &b, &c);
			if(a % b) {
				printf("-1\n");
				continue;
			}
			printf("%d\n", que(st[b], c-a, a));
		}
	}
	printf("%d\n", cnt);
}