#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i){
         scanf("%d",dp+i);
         dp[i]+=dp[i-1];
    }
    int xd = 1e9;
    int x,y;
    for(int i = 2;i<n;++i){
        for(int j = i+1;j<=n;++j){
            int a = dp[i-1];
            int b = dp[j-1]-dp[i-1];
            int c = dp[n]-dp[j-1];
            int mx = max(a,max(b,c));
            int mn = min(a,min(b,c));
            int div = mx-mn;
            if(div<xd){
                xd = div;
                x = i,y = j;
            }
        }
    }
    printf("%d %d\n",x,y);
}
