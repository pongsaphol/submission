#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
long long qs[1000005];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    long long mx = -1e18,mn = 1e18;
    for(int i = 1;i<=n;++i){
        scanf("%lld",qs+i);
        qs[i]+=qs[i-1];
        if(i>=m){
            mn = min(mn,qs[i-m]);
            mx = max(mx,qs[i]-mn);
        }
    }
    printf("%lld\n",mx);
}

