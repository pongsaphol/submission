#include <cstdio>
#include <algorithm>
using namespace std;

int dp[105][105];
int qs[105][105];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            scanf("%d",&dp[i][j]);
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }

    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            scanf("%d",&qs[i][j]);
            qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    long long mx = 0;
    mx = max(mx,(long long)dp[n][m]-dp[1][m]+qs[2][m]-qs[1][m]);
    mx = max(mx,(long long)dp[n-1][m]+qs[n-1][m]-qs[n-2][m]);
    for(int i = 2;i<=n-1;++i){
        mx = max(mx,(long long)dp[n][m]-dp[i][m]+dp[i-1][m]+qs[i+1][m]-qs[i][m]+qs[i-1][m]-qs[i-2][m]);
    }
    mx = max(mx,(long long)dp[n][m]-dp[n][1]+qs[n][2]-qs[n][1]);
    mx = max(mx,(long long)dp[n][m-1]+qs[n][m-1]-qs[n][m-2]);
    for(int j = 2;j<=m-1;++j){
        mx = max(mx,(long long)dp[n][m]-dp[n][j]+dp[n][j-1]+qs[n][j+1]-qs[n][j]+qs[n][j-1]-qs[n][j-2]);
    }
    printf("%lld",mx);
}
