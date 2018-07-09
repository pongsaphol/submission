#include <cstdio>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
#define x first
#define y second
#define long long long
using namespace std;

typedef struct node {
	int x, y, c;
	friend inline bool operator<(const node &a, const node &b) {
		return a.x < b.x;
	}
	friend inline bool operator>(const node &a, const node &b) {
		return a.y < b.y;
	}
} node;

int n, cnt;
long sumx, sumy, ans;
vector<node> V;

int main() {
	freopen("r", "r", stdin);
	scanf("%d", &n);
	V.reserve(n);
	while(n--) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		V.push_back({x, y, c});
		cnt += c;
	}
	sort(V.begin(), V.end());
	int x, y;
	if(cnt%2) {
		int now = (cnt+1)/2;
		for(auto z:V) {
			now -= z.c;
			if(now <= 0) {
				x = z.x;
				break;
			}
		}
	} else {
		bool want = false;
		int now = cnt/2;
		for(auto z:V) {
			now -= z.c;
			if(want) {
				x += z.x;
				x /= 2;
				break;
			}
			if(now <= 0) {
				x = z.x;
				break;
			}
			if(now == 0) want = true;
		}
	}
	sort(V.begin(), V.end(), greater<node>());
	if(cnt%2) {
		int now = (cnt+1)/2;
		for(auto z:V) {
			now -= z.c;
			if(now <= 0) {
				y = z.y;
				break;
			}
		}
	} else {
		bool want = false;
		int now = cnt/2;
		for(auto z:V) {
			now -= z.c;
			if(want) {
				y += z.y;
				y /= 2;
				break;
			}
			if(now <= 0) {
				y = z.y;
				break;
			}
			if(now == 0) want = true;
		}
	}
	for(auto z:V) {
		ans += (abs(z.x-x) + abs(z.y-y))*(long)z.c;
	}
	printf("%lld\n", ans);
	return 0;	
}