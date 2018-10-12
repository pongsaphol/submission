#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 1e6+5;

int n, m, k;
pii A[N];
int dp[N];
int ans[N];
int tme[N];
bool ist[N];
bool know[N];
int mat[N];

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1, a, b; i <= m; ++i) scanf("%d %d", &a, &b), A[i] = pii(a, b);
    for(int i = k+1; i <= n; ++i) dp[i] = i;
    for(int i = m; i; --i) {
        if(!ans[A[i].x]) dp[A[i].x] = dp[A[i].y], tme[A[i].x] = i, ans[A[i].x] = dp[A[i].y]; 
        if(!ans[A[i].y]) dp[A[i].y] = dp[A[i].x], tme[A[i].y] = i, ans[A[i].y] = dp[A[i].x]; 
        if(A[i].y > k and A[i].x <= k) dp[A[i].x] = A[i].y;
        if(A[i].x > k and A[i].y <= k) dp[A[i].y] = A[i].x;
    }
    for(int i = 1; i <= k; ++i) printf("%d ", dp[i] ? tme[i] : -1);
    puts("");
    for(int i = 1; i <= k; ++i) if(dp[i]) mat[tme[i]] = i;
    for(int i = 1; i <= m; ++i) {
        if(mat[i]) know[mat[i]] = true;
        know[A[i].x] |= know[A[i].y], know[A[i].y] |= know[A[i].x];
    }
    vector<int> ans;
    for(int i = k+1; i <= m; ++i) if(know[i]) ans.emplace_back(i);
    printf("%d ", (int)ans.size());
    for(auto x : ans) printf("%d ", x);
    puts("");
    for(int i = 1; i <= k; ++i) printf("%d ", ans[i] ? ans[i] : -1);
    puts("");
}
