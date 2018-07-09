#include <bits/stdc++.h>

int main(){
    int x,y,z,a,b,c,d;
    scanf("%d%d%d",&x,&y,&z);
    for(a = -1*abs(x);a<=abs(x);a++){
        for(b = -1*abs(z);b<=abs(z);b++){
            for(c=-1*abs(x);c<=abs(x);c++){
                for(d=-1*abs(z);d<=abs(z);d++){
                    if(a*c==x&&((a*d)+(b*c))==y&&b*d==z){
                        printf("%d %d %d %d",c*-1,d*-1,a*-1,b*-1);
                        return 0;
                    }
                }
            }
        }
    }
    printf("No Solution");
}

