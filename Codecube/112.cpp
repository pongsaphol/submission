#include <cstdio>
#include <algorithm>
using namespace std;

char arr[2005][2005];

int main(){
    int n;
    scanf("%d",&n);
    int a = 1000,b = 1000,c = 1000,d = 1000;
    arr[1000][1000] = 'A';
    for(int t = 2;t<=n;++t){
        if(t%4==2){
            int len = c-a+1;
            //printf("%d %d\n",i,len);
            for(int i = a;i<a+len;++i){
                for(int j = d+1;j<=d+len;++j){
                    arr[i][j] = t+'A'-1;
                    //printf("%d-%d\n",i,j);
                }
            }
            d = d+len;
        }
        if(t%4==3){
            int len = d-b+1;
            //printf("%d\n",len);
            for(int i = c+1;i<=c+len;++i){
                for(int j = b;j<b+len;++j){
                    arr[i][j] = t+'A'-1;
                }
            }
            c = c+len;
        }
        if(t%4==0){
            int len = c-a+1;
            for(int i = a;i<a+len;++i){
                for(int j = b-1;j>=b-len;--j){
                    arr[i][j] = t+'A'-1;
                }
            }
            b = b-len;
        }
        if(t%4==1){
            int len = d-b+1;
            for(int i = a-1;i>=a-len;--i){
                for(int j = b;j<b+len;++j){
                    arr[i][j] = t+'A'-1;
                }
            }
            a = a-len;
        }
    }
    for(int i = a;i<=c;++i){
        for(int j = b;j<=d;++j){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}
