#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int sum = 0;
    int x1,x2;
    scanf("%d%d",&x1,&x2);
    int o;
    scanf("%d",&o);
    sum+=x1*x2*o;
    for(int i = 0;i<a*b;i++){
        int k;
        scanf("%d",&k);
        sum+=k;
    }
    float an = sum;
    an/=o;
    int ans = ceil(an);
    printf("%d",ans);
}

