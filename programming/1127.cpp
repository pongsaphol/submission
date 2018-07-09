#include <cstdio>
#include <algorithm>
using namespace std;
int arr[10];
char toprint[105];
int main(){
    int n;
    scanf("%d",&n);
    int idx = 0;
    arr[0] = 1e9;
    for(int i = 1;i<=9;++i){
        scanf("%d",&arr[i]);
        if(arr[idx]>arr[i])idx = i;
    }
    int len = n/arr[idx];
    for(int i = 0;i<len;++i){
        toprint[i] = idx+'0';
        n-=arr[idx];
    }
    for(int i = 0;i<len;++i){
        for(int j = 9;j>=1;--j){
            if(j>toprint[i]-'0'&&n+arr[toprint[i]-'0']-arr[j]>=0){
                n = n+arr[toprint[i]-'0']-arr[j];
                toprint[i] = j+'0';
            }
        }
    }
    printf("%s",toprint);
}
