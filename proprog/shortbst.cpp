#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%d%d",&a,&b);
        int sum = 0;
        while(a!=1){
            if(a>b)swap(a,b);
            sum+=b/a;
            b%=a;
        }
        sum+=b-1;
        printf("%d\n",sum);
    }
}
