#include <cstdio>
#include <algorithm>
using namespace std;

bool arr[25];
bool cop[25];
int main(){
    int n,ans = 1e9;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i){
        scanf("%d",arr+i);
    }

    for(int i = 1;i<=n;++i){
        cop[i] = arr[i];
    }
    int cnt = 0;
    for(int i = 2;i<=n;++i){
        if(cop[i-1]){
            cop[i-1]^=1;
            cop[i]^=1;
            cop[i+1]^=1;
            cnt++;
        }
    }
    if(!cop[n])ans = min(ans,cnt);
    for(int i = 1;i<=n;++i){
        cop[i] = arr[i];
    }
    cnt = 0;
    cop[0] = 1;
    for(int i = 1;i<=n;++i){
        if(cop[i-1]){
            cop[i-1]^=1;
            cop[i]^=1;
            cop[i+1]^=1;
            cnt++;
        }
    }
    if(!cop[n])ans = min(ans,cnt);
    if(ans == 1e9) printf("-1\n");
    else printf("%d\n",ans);
}

