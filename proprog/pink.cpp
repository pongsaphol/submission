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

unordered_map<long, int> M;
char A[] = "pinkhare", f[256], now[60];
int main() {
	red();
	for(int i = 0; i < 8; ++i) f[A[i]] = i;
	int T;
	scanf("%d", &T);
	while(T--) {
		M.clear();
		int q;
		scanf("%d", &q);
		while(q--) {
			scanf("%s", now);
			int sz = strlen(now);
			long hash = 0, del = 1;
			for(int i = 0; i < 10; ++i) {
				hash = (hash << 3) + f[now[i]];
				del <<= 3;
			}
			if(sz == 44) {
				if(M[hash] == 0) M[hash] = q;
				if(M[hash] != q) M[hash] = -1;
				for(int i = 10; i < 44; ++i) {
					hash = (hash << 3) + f[now[i]] - del*f[now[i-10]];
					if(M[hash] == 0) M[hash] = q;
					if(M[hash] != q) M[hash] = -1;
				}
			} else {
				if(M[hash] == 0) puts("not exist");
				else if(M[hash] == -1) puts("duplicate");
				else puts("unique");
			}
		}
	}

		return 0;
}