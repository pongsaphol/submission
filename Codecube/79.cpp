#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;
int arr[1005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i){
        scanf("%d",arr+i);
    }
    int cnt = 0,idx,pos;
    for(int i = 1;i<=n;++i){
        if(i%2==1)idx = i/2 + 1;
        else idx = n-(i/2)+1;
        for(int j = 1;j<=n;++j){
            if(arr[j]==idx)pos = j;
        }
        if(pos==idx){cnt++;continue;}
        if(idx<pos){
            for(int j = pos;j>idx;--j){
                arr[j] = arr[j-1];
            }
            arr[idx] = idx;
        }else{
            for(int j = pos;j<idx;++j){
                arr[j] = arr[j+1];
            }
            arr[idx] = idx;
        }
    }
    printf("%d\n",cnt);
}
