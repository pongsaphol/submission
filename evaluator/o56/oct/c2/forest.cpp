#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>
#include <queue>
#include <algorithm>
#define input() (*istream_iterator<int>(cin))
#define long long long
#define P pair<int, int>
#define x first
#define y second
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
}

const int inf = 1e9;

int n, p, k, A[25][25], d[25][25][25], X[] = {0, 0, -1, 1}, Y[] = {-1, 1, 0, 0};
vector<P> wrap[25][25];

struct data{
	int w, x, y, z;
	friend inline bool operator<(const data &a, const data &b) {
		return a.w > b.w;
	}
};

int main() {
	red();
	cin >> n >> p >> k;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			A[i][j] = input();
		}
	}
	while(p--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		wrap[x][y].emplace_back(a, b);
	}
	priority_queue<data> Q;
	fill(d[0][0], d[0][0] + 15620, inf);
	d[0][0][0] = 0;
	Q.push({0, 0, 0, 0});
	while(!Q.empty()) {
		auto f = Q.top();
		Q.pop();
		if(f.w != d[f.x][f.y][f.z]) continue;
		int x = f.x, y = f.y, z = f.z;
		if(x == n-1 && y == n-1) return !printf("%d\n", d[x][y][z]);
		for(int i = 0; i < 4; ++i) {
			int xn = x+X[i], yn = y+Y[i];
			if(xn < 0 || yn < 0 || xn >= n || yn >= n) continue;
			if(d[xn][yn][z] > d[x][y][z] + A[xn][yn]) {
				d[xn][yn][z] = d[x][y][z] + A[xn][yn];
				Q.push({d[xn][yn][z], xn, yn, z});
			}
		}
		if(z == k) continue;
		for(auto v:wrap[x][y]) {
			if(d[v.x][v.y][z+1] > d[x][y][z]) {
				d[v.x][v.y][z+1] = d[x][y][z];
				Q.push({d[v.x][v.y][z+1], v.x, v.y, z+1});
			}
		}
	}
}