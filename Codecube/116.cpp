#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    int oT = T;
    while(T--){
        long long n;
        scanf("%lld",&n);
        printf("Case #%d:\n",oT-T);
        long long b = n-1;
        bool chk = false;
        for(long long a = 1;a<=n;++a){
            while(true){
                if(a>b)break;
                if(a*a+b*b == (n-a-b)*(n-a-b)){
                    printf("%lld %lld %lld\n",a,b,n-a-b);
                    chk = true;
                    break;
                }else if(a*a+b*b > (n-a-b)*(n-a-b)){
                    b--;
                }else{
                    break;
                }
            }
        }
        if(!chk)printf("-1\n");
    }
}
