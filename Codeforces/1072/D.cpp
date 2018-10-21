#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pss pair<short, short>
#define x first
#define y second

const int N = 2e3+5;

char A[N][N];
int n, k;
int dp[N][N];
vector<pii> ldep[N<<1];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%s", A[i] + 1);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
        ldep[i+j-1].emplace_back(i, j);
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + (A[i][j] == 'a');
    }
    for(int i = n+n-1; i; --i) {
        bool st = false;
        set<pii> S;
        for(auto x : ldep[i]) 
            if(i - dp[x.x][x.y] <= k) st = true, S.emplace(x);
        if(st) {
            for(int j = 1; j <= i; ++j) printf("a");
            for(int j = i+1; j <= n+n-1; ++j) {
                vector<pii> ret;
                char c = 'z'+1;
                for(auto x : ldep[j]) if(S.count(pii(x.x, x.y-1)) || S.count(pii(x.x-1, x.y))) {
                    if(A[x.x][x.y] < c) c = A[x.x][x.y], ret.clear();
                    if(A[x.x][x.y] == c) ret.emplace_back(x);
                }
                printf("%c", c);
                S = set<pii>(ret.begin(), ret.end());
            }
            return 0;
        }
        S.emplace(1, 1);
        if(i == 1) {
            printf("%c", A[1][1]);
            for(int j = i+1; j <= n+n-1; ++j) {
                vector<pii> ret;
                char c = 'z'+1;
                for(auto x : ldep[j]) if(S.count(pii(x.x, x.y-1)) || S.count(pii(x.x-1, x.y))) {
                    if(A[x.x][x.y] < c) c = A[x.x][x.y], ret.clear();
                    if(A[x.x][x.y] == c) ret.emplace_back(x);
                }
                printf("%c", c);
                S = set<pii>(ret.begin(), ret.end());
            }
            return 0;
        }
    }
}
