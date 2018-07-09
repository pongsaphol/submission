#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;
const int MAX = 1e7;
long long qs[1000005];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    unordered_map<long long,int> ar(10000000);
    for(int i = 1;i<=n;++i){
        char c;
        scanf(" %c",&c);
        if(c=='R')qs[i] = qs[i-1]-m;
        else qs[i] = qs[i-1]+1;
        //printf("%d\n",qs[i]);
    }
    int mx = 0;
    for(int i = 0;i<=n;++i){
        if(qs[i]==0){
            mx = max(mx,i);
            continue;
        }
        if(ar[qs[i]]==0) ar[qs[i]] = i;
        else mx = max(mx,i-ar[qs[i]]);
    }
    printf("%d\n",mx);
}
