#include <cstdio>
#include <algorithm>
using namespace std;
int dp[2][5005],mod = 2553;
int f(int x){if(x>=0)return x;return 5001;}

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int sum = 0;
    for(int i = 0;i<=n;++i)dp[0][i] = 1;
    for(int i = 1;i<=n;++i){
        dp[i&1][0] = 0;
        for(int j = 1;j<=n;++j){
            dp[i&1][j] = dp[i&1][j-1]+dp[(i-1)&1][j-1]-dp[(i-1)&1][f(j-k-1)];
            dp[i&1][j]%=mod;
            //dp[i][j]%=mod;
            //printf("%d ",dp[i-1][j-1]-dp[i-1][f(j-k-1)]);
        }
        int now = dp[i&1][n]-dp[i&1][n-1];
        now%=mod;now+=mod;now%=mod;
        now = ((now*now)%mod)*now;
        now%=mod;
        sum+=now;
        sum%=mod;
    }
    printf("%d\n",sum);
}
