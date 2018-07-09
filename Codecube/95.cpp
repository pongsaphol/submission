#include <cstdio>
#include <algorithm>
using namespace std;
char arr[100005];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(m%3!=0){
        printf("-1");
        return 0;
    }
    if(n==1){
        if(m==3||m==9){
            printf("-1");
            return 0;
        }
    }
    swap(n,m);
    for(int i = 0;i<m;++i){
        if(n-9>=0){
            n-=9;
            arr[i] = '0'+9;
        }else if(n-6>=0){
            n-=6;
            arr[i] = '0'+6;
        }else if(n-3>=0){
            n-=3;
            arr[i] = '0'+3;
        }else{
            arr[i] = '0';
        }
    }
    if(arr[0]=='0'||n!=0){
        printf("-1");
        return 0;
    }
    if((arr[m-1]-'0')%2==1){
        arr[m-1]+=3;
        arr[m-2]-=3;
    }
    printf("%s",arr);
}
