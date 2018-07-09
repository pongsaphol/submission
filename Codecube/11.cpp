#include <cstdio>
#include <algorithm>
using namespace std;
bool arr[1005][1005];
int sum[1005];
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            scanf("%d",arr[i]+j);
            if(!arr[i][j])sum[i]++;
        }
    }
    int cache = 0;
    for(int i = n;i>=1;--i){
        int H = 0;
        bool st = false;
        for(int j = 1;j<=k;++j){
            H+=arr[i][j];
        }
        if(H<=cache)st = true;
        for(int j = k+1;j<=m;++j){
            H = H-arr[i][j-k]+arr[i][j];
            if(H<=cache)st = true;
        }
        if(st){
            printf("%d\n",i);
            return 0;
        }
        cache+=sum[i];
    }
}
