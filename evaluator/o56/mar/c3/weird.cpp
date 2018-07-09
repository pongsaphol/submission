#include <bits/stdc++.h>
#define P pair<int, int>
#define x first
#define y second
#define long long long
using namespace std;

int n;
vector<P> pt;

int f(int x) {
	return (x + n) % n;
}

int cross(P p1, P p2, P p3) {
	return (long)(p2.x - p1.x) * (p3.y - p1.y) - (long)(p3.x - p1.x) * (p2.y - p1.y);
}

int find(int x) {
	for(int i = 0; i < n; ++i) {
		if(f(i+1) == x || f(i-1) == x || i == x) continue;
		if(cross(pt[f(i-1)], pt[i], pt[x]) > 0 && cross(pt[i], pt[x], pt[f(x+1)]) > 0)
		if(cross(pt[f(x-1)], pt[x], pt[i]) > 0 && cross(pt[x], pt[i], pt[f(i+1)]) > 0)
		return i;
	}
	return -1;
}

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		pt.emplace_back(a, b);
	}
	vector<int> cw;
	for(int i = 0; i < n; ++i) {
		if(cross(pt[f(i-1)], pt[f(i)], pt[f(i+1)]) < 0) {
			cw.emplace_back(i);
		}
	}
	assert(cw.size() <= 2);
	if(cw.size() == 2) return !printf("%d %d\n", cw[0]+1, cw[1]+1);
	if(cw.size() == 1) {
		int x = cw[0];
		int y = find(cw[0]);
		if(x > y) swap(x, y);
		return !printf("%d %d\n", x+1, y+1);		
	}
	for(int i = 0; i < n; ++i) {
		int ret = find(i);
		if(ret != -1) {
			if(i > ret) swap(i, ret);
			return !printf("%d %d\n", i+1, ret+1);
		}
	}
}