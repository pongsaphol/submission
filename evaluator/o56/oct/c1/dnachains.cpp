#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, idx = 1;
struct node {
	bool is = false;
	int A[2] = {0, 0}; // 0 is prev, 1 is next;
};

node A[100005];

int main() {
	// freopen("r", "r", stdin);
	scanf("%d%d", &n, &m);
	A[0].is = true;
	while(n--) {
		int x;
		scanf("%d", &x);
		idx++;
		while(--x) {
			A[idx].A[0] = idx-1;
			A[idx-1].A[1] = idx;
			idx++;
		}
	}
	int now = 1;
	while(m--) {
		char c;
		scanf(" %c", &c);
		if(c == 'B') {
			bool met;
			if(A[A[now].A[0]].is) met = false;
			else met = true;
			if(A[now].A[met] == 0) {
				printf("%d\n", now);
				continue;
			}
			int pr = now;
			now = A[now].A[met];
			A[now].is = false;
			if(pr != A[now].A[met]) A[A[now].A[met]].is = true;
			else A[A[now].A[!met]].is = true;
			printf("%d\n", now);
		}else if(c == 'F') {
			bool met;
			if(A[A[now].A[0]].is) met = true;
			else met = false;
			if(A[now].A[met] == 0) {
				printf("%d\n", now);
				continue;
			}
			A[A[now].A[!met]].is = false;
			A[now].is = true;
			now = A[now].A[met];
			printf("%d\n", now);
		}else{
			int x;
			scanf("%d", &x);
			bool met;
			// find met
			if(A[A[now].A[0]].is) met = true;
			else met = false;
			if(now == A[A[now].A[met]].A[0]) A[A[now].A[met]].A[0] = 0;
			else A[A[now].A[met]].A[1] = 0;
			A[now].A[met] = x;
			if(A[x].A[0] == 0) A[x].A[0] = now;
			else A[x].A[1] = now;
			A[A[now].A[!met]].is = false;
			A[now].is = true;
			now = A[now].A[met];
			printf("%d\n", now);
		}
		// for(int i = 1; i <= 6; ++i) {
		// 	printf("%d :: %d %d\n", i, A[i].A[0], A[i].A[1]);
		// }
	}
	return 0;
}