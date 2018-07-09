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

vector<int> data;

const int MAXN = 2e5+5;

int n, A[MAXN], cnt;
bool st[MAXN]; // true is square

long solve2() {
	int rur = n/2 - cnt;
	vector<int> ans;
	for(int i = 1; i <= n; ++i) if(st[i]) {
		auto it = lower_bound(all(data), A[i]);
		int a1 = *it - A[i];
		if(it != data.begin()) {
			it--;
			a1 = min(a1, A[i] - *it);
		}
		ans.emplace_back(a1);
	}
	long sum = 0;
	sort(all(ans));
	for(int i = 0; i < rur; ++i) sum += ans[i];
	return sum;
}

long solve1() {
	int todel = cnt - n/2;
	vector<int> ans;
	for(int i = 1; i <= n; ++i) if(!st[i]) {
		if(A[i] == 0) ans.emplace_back(2);
		else ans.emplace_back(1);
	}
	long sum = 0;
	sort(all(ans));
	for(int i = 0; i < todel; ++i) sum += ans[i];
	return sum;
}

int main() {
	red();
	for(int i = 0; i*i <= 1100000000; ++i) data.emplace_back(i*i);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", A+i);
		auto it = lower_bound(all(data), A[i]);
		if(*it == A[i]) cnt++;
		else st[i] = true;
	}
	if(cnt > n/2) printf("%I64d\n", solve1());
	else printf("%I64d\n", solve2());
}