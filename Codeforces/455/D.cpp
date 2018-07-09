#include <bits/stdc++.h>
using namespace std;

int n, m;
deque<int> block[400];
int mark[400][100005];

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	int sz = sqrt(n);
	for(int i = 0; i < n; ++i) {
		int now;
		scanf("%d", &now);
		block[i/sz].push_back(now);
		mark[i/sz][now]++;
	}
	int last = 0, l, r, k;
	scanf("%d", &m);
	while(m--) {
		int met; scanf("%d %d %d", &met, &l, &r);
		l = (l + last - 1) % n, r = (r + last - 1) % n;
		if(l > r) swap(l, r);
		int b1 = l / sz, b2 = r / sz;
		if(met == 1) {
			int inr = r%sz, inl = l%sz;
			int val = block[b2][inr];
			block[b1].insert(block[b1].begin()+inl, val), mark[b1][val]++;
			if(b1 == b2) inr++;
			block[b2].erase(block[b2].begin()+inr), mark[b2][val]--;
			for(int i = b1; i < b2; ++i) {
				int val = block[i].back();
				block[i].pop_back(), block[i+1].push_front(val);
				mark[i][val]--, mark[i+1][val]++;
			}
		} else {
			scanf("%d", &k);
			k = ((k + last - 1) %n) + 1;
			int sum = 0;
			if(b1 == b2) 
			for(int i = l%sz; i <= r%sz; ++i) sum += (block[b1][i] == k);
			else {
				for(int i = l%sz; i < block[b1].size(); ++i) sum += (block[b1][i] == k);
				for(int i = 0; i <= r%sz; ++i) sum += (block[b2][i] == k);
				for(int i = b1 + 1; i < b2; ++i) sum += mark[i][k];	
			}
			last = sum;
			printf("%d\n", sum);
		}
	}
}