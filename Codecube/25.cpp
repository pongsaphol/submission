#include <cstdio>
#include <algorithm>
using namespace std;

long long dp[605][605];
long long qs[605];
long long recur(int x,int y){
    if(dp[x][y]!=0)return dp[x][y];
    if(x==y)return 0;
    long long mx = 0;
    for(int i = x;i<y;++i){
        int a = qs[i]-qs[x-1];
        int b = qs[y]-qs[i];
        if(a>b)swap(a,b);
        mx = max(mx,recur(x,i)+recur(i+1,y)+2*(a)+b);
    }
    return dp[x][y] = mx;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i){
        scanf("%lld",&qs[i]);
        qs[i]+=qs[i-1];
    }
    printf("%lld\n",recur(1,n));
}
