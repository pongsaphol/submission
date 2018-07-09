#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1<<18;
int FT[MAX+1];
void update(int idx,int val){
    while(idx<=MAX){
        FT[idx]+=val;
        idx+=idx&(-idx);
    }
}

int query(int idx){
    int val = 0;
    while(idx>=1){
        val+=FT[idx];
        idx-=idx&(-idx);
    }
    return val;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=MAX;++i){
        FT[i] = i&(-i);
    }
    for(int i = 1;i<=n;++i){
        //printf("%d--\n", m);
        int L = 1,R = MAX,mid;
        while(L<R){
            mid = (L+R)/2;
            int now = mid;
            if(now<m){
                L = mid+1;
                m-=now;
            }else{
                R = mid;
            }
        }
        //printf("->%d\n",L);
        if(i==n){
            printf("%d\n",L);
            return 0;
        }
        update(L,-1);
        m = L;
        m+=query(L);
        m%=(n-i);
        if (m == 0) m = n-i;
        //for (int i = 1; i <= n; i ++) printf("%d,%d ", i, query(i));
        //printf("\n");
    }
}
