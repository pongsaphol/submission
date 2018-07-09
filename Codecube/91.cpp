#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
int dp[100005][4];
char pr[100005][4];
int main(){
    fill(dp[0],dp[0]+sizeof(dp)/sizeof(int),1e9);
    int len;
    scanf("%d",&len);
    for(int i = 1;i<=len;++i){
        char now;scanf(" %c",&now);
        if(now=='X') now = 0;
        if(now=='B') now = 1;
        if(now=='W') now = 2;
        dp[0][1] = 0,dp[0][2] = 0,dp[0][3] = 0;
        for(int j = 1;j<=3;++j){
            if(now!=0&&now!=j)continue;
            for(int k = 1;k<=3;++k){
                if(j==k)continue;
                if(dp[i-1][k]<dp[i][j]){
                    dp[i][j] = dp[i-1][k];
                    pr[i][j] = k;
                }
            }
            if(j==3)dp[i][j]++;
        }
    }
    int st = -1,mn = 1e9;
    for(int i = 1;i<=3;++i){
        if(dp[len][i]<mn){
            mn = dp[len][i];
            st = i;
        }
    }
    if(st == -1){
        printf("No Answer\n");
        return 0;
    }
    stack<char> S;
    for(int i = len;i>=1;--i){
        if(st == 1)S.push('B');
        if(st == 2)S.push('W');
        if(st == 3)S.push('G');
        st = pr[i][st];
    }
    while(!S.empty()){
        printf("%c",S.top());
        S.pop();
    }
}
