#include <cstdio>
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int k = 0;
    while(1){
        k++;
        int mx = max(max(a,b),c);
        if(mx == a)
            a/=2;
        else if(mx == b)
            b/=2;
        else
            c/=2;
        if(a==1&&b==1&&c==1){
            break;
        }
    }
    printf("%d",k);
}
