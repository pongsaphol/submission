#include <cstdio>
#include <algorithm>
using namespace std;
int x,y;
int t;
void walk(int step){
    t = (t+4)%4;
    if(t==0)x+=step;
    if(t==1)y+=step;
    if(t==2)x-=step;
    if(t==3)y-=step;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char ar[3];
        int k;
        scanf("%s%d",ar,&k);
        if(ar[0]=='L')t++;
        if(ar[0]=='R')t--;
        if(ar[0]=='B')t+=2;
        walk(k);
        if(x<=-50000||x>=50000||y<=-50000||y>=50000){
            printf("DEAD\n");
            return 0;
        }
    }
    printf("%d %d\n",x,y);
    if(t==0)printf("E");
    if(t==1)printf("N");
    if(t==2)printf("W");
    if(t==3)printf("S");
}
