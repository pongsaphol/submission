#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
#include <iterator>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;
using namespace __gnu_pbds;

typedef tree<P, null_type, less<P>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int idx = 1, A[200005];

int main() {
	freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	int m = input();
	ordered_set S;
	while(m--) {
		int c = input();
		if(c == 1) {
			A[idx] = input();
			S.insert({A[idx], idx});
			idx++;
		} else if (c == 2) {
			if(S.empty()) {
				printf("0\n");
				continue;
			}
			printf("%d\n", S.begin()->y);
			S.erase(S.begin());
		} else {
			int x = input();
			printf("%d\n", S.order_of_key({A[x], x}));
		}
	}
}