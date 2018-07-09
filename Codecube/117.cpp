#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool chk[2][100007];
int main(){
    int T;
    scanf("%d",&T);
    int ot = T;
    while(T--){
        memset(chk,0,sizeof chk);
        int n,m;
        scanf("%d%d",&n,&m);
        chk[0][0] = true;
        for(int i = 1;i<=n;++i){
            int now;scanf("%d",&now);
            for(int j = m-1;j>=0;--j){
                chk[i&1][(j+now)%m]|=chk[(i-1)&1][j];
            }
        }
        for(int j = m-1;j>=0;--j){
            if(chk[0][j]||chk[1][j]){
                printf("Case #%d: %d\n",ot-T,j);
                break;
            }
        }
    }
}
