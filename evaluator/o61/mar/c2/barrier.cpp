#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pii pair<int, int>
using namespace std;

int n;
vector<pii> V;

int cross(pii a, pii b, pii c) {
	return (int)(b.x - a.x)*(c.y - a.y) - (int)(c.x - a.x)*(b.y - a.y);
}

int pw(int z) { return z * z; }

double d(pii a, pii b) {
	return sqrt(pw(a.x - b.x) + pw(a.y - b.y));
}

double ch() {
	pii mn(0, 1e9);
	for(auto x : V) if(x.y < mn.y) mn = x;
	sort(V.begin(), V.end(), [&](const pii &a, const pii &b) {
		if(a.x == mn.x) return false;
		if(b.x == mn.x) return false;
		double x = (a.y - mn.y) / (a.x - mn.x);
		double y = (b.y - mn.y) / (b.x - mn.x);
		return atan(x) < atan(y);
	});
	vector<pii> S;
	S.emplace_back(mn);
	for(auto x : V) {
		if(x == mn) continue;
		while(S.size() >= 2 && cross(S[S.size()-2], S[S.size()-1], x) < 0) S.pop_back();
		S.emplace_back(x); 
	}
	double sum = 0.0;
	for(int i = 0; i < S.size(); ++i) {
		sum += d(S[i], S[(i+1) % (int)S.size()]);
	}
	return sum;
}

int32_t main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%lld", &n);
	while(n--) {
		int a, b;
		scanf("%lld %lld", &a, &b);
		V.emplace_back(a, b);
		printf("%.6f\n", ch());
	}
}