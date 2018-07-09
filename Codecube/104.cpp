#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1005][3005];
int arr[1005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i)scanf("%d",arr+i);
    fill(dp[0],dp[1001]+3001,1e9);
    dp[0][0] = 0;
    for(int i = 1;i<=n;++i){
        int mn = dp[i-1][0];
        for(int j = 1;j<=3000;++j){
            dp[i][j] = mn;
            if(j!=arr[i]){
                dp[i][j]++;
            }
            mn = min(mn,dp[i-1][j]);
        }
    }
    int mn = dp[n][0];
    /*for(int i = 1;i<=6;++i){
        for(int j = 1;j<=10;++j){
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }*/
    for(int i = 1;i<=3000;++i)mn = min(mn,dp[n][i]);
    printf("%d\n",mn);
}
