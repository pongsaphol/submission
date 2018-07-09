#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int len;
int arr[1000005];
int arc[1000005];
long long coun = 0;

void mer(int L,int R){
    if(L>=R){
        return;
    }
    int mid = (L+R)/2;
    mer(L,mid);
    mer(mid+1,R);
    int i = L,j = mid+1,k = L;
    while(i<=mid&&j<=R){
        if(arr[i]<arr[j]){
            arc[k] = arr[i];
            i++;
        }else{
            arc[k] = arr[j];
            j++;
            coun+=mid-i+1;
        }
        k++;
    }
    while(i<=mid){
        arc[k] = arr[i];
        i++;
        k++;
    }
    while(j<=R){
        arc[k] = arr[j];
        j++;
        k++;
    }
    for(int p = L;p<=R;++p){
        arr[p]=arc[p];
    }
}

int main(){
    while(scanf("%d",&len)!=EOF){
        coun = 0;
        for(int i  = 1;i<=len;++i){
            scanf("%d",&arr[i]);
        }
        mer(1,len);
        printf("%lld\n",coun);
    }
}
