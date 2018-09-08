#include <bits/stdc++.h>
using namespace std;

const int N = 105;

#define long long long
#define pii pair<int, int>
#define x first
#define y second

int n, val[N], l[N], r[N];
int P[4];
int find(int x) { return P[x] == x ? x : find(P[x]); }

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d %d", l+i, &val[i], r+i); 
        l[i]--, r[i]--;
    }
    long mx = 0;
    for(int i = 1; i < 16; ++i) {
        vector<pair<vector<pii>, long> > dp(16, make_pair(vector<pii>()(long)(-1e18)));
        dp[0] = make_pair(vector<pii>(), 0);
        for(int j = 1; j <= n; ++j) if((i & (1<<l[j])) && (i & (1<<r[j]))){
            vector<pair<vector<pii>, long> > ret(16);
            int v = (1<<l[j]) | (1<<r[j]);
            for(int k = 0; k < 16; ++k) ret[k] = dp[k^v], ret[k].x.emplace_back(l[j], r[j]), ret[k].y += val[j];
            for(int k = 0; k < 16; ++k) if(ret[k].y > dp[k].y) dp[k] = ret[k];
        }
        for(int j = 0; j < 16; ++j) {
            P[0] = 0, P[1] = 1, P[2] = 2, P[3] = 3;
            int cnt = 0;
            for(int k = 0; k < 4; ++k) if(j >> k & 1) cnt++;
            if(cnt == 0 || cnt == 2) {
                for(auto x : dp[j].x) {
                    int u = find(x.x), v = find(x.y);
                    if(u != v) P[u] = v;
                }
                set<int> S;
                for(int k = 0; k < 4; ++k) if(i >> k & 1) S.emplace(P[k]);
                if(S.size() == 1) mx = max(mx, dp[j].y);
            }

        }
    }
    
    printf("%lld\n", mx);
}
