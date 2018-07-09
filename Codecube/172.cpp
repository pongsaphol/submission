#include <bits/stdc++.h>
using namespace std;

const int MAXN = 21;

int n, m, g[MAXN], par[MAXN], d[MAXN];

int find(int x) {
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}

bool uni(int a, int b) {
	a = find(a), b = find(b);
	if(a == b) return true;
	par[a] = b, d[b] += d[a];
	return false;
}

int dp[1<<21], used[1<<21] = {}, testcase = 0;
int pre[1<<21][2];
void bfs() {
    queue<int> Q;
    int u, v;
    testcase++;
    dp[(1<<n)-1] = 0, used[(1<<n)-1] = testcase;
    Q.push((1<<n)-1);
    while (!Q.empty()) {
        u = Q.front(), Q.pop();
        for (int i = 0; (1<<i) <= u; i++) {
            if ((u>>i)&1) { // kill
                v = 0;
                for (int j = 0; (1<<j) <= u; j++) {
                    if ((u>>j)&1) {
                        if (j != i)
                            v |= g[j];
                    }
                }
                if (used[v] != testcase) {
                    used[v] = testcase;
                    pre[v][0] = u, pre[v][1] = i;
                    dp[v] = dp[u] + 1;
                    if (v == 0) {
                        printf("%d:", dp[v]);
                        stack<int> stk;
                        do {
                            stk.push(pre[v][1]);
                            v = pre[v][0];
                        } while (v != (1<<n)-1);
                        while (!stk.empty()) {
                            printf(" %d", stk.top());
                            stk.pop();
                        }
                        puts("");
                        return;
                    }
                    Q.push(v);
                }
            }
        }
    }
    puts("Impossible");
}

void solve() {
	for(int i = 0; i < n; ++i) g[i] = 0, par[i] = i, d[i] = 1;
	bool st = false;
	while(m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a] |= 1<<b, g[b] |= 1<<a;
		if(uni(a, b)) st = true;
	}
	if(st) {
		puts("Impossible");
		return;
	}
	bfs();	
}

int main() {
	// freopen("r", "r", stdin);
	while(scanf("%d%d", &n, &m), n) solve();
}