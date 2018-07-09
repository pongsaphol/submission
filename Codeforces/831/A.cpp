#include <cstdio>
#include <algorithm>
using namespace std;
int arr[105];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i){
        scanf("%d",&arr[i]);
    }
    bool isf = false;
    for(int i = 2;i<n;++i){
        for(int j = i+1;j<=n;++j){
            bool st = true;
            for(int k = 2;k<=i;++k){
                if(arr[k]<arr[k-1])st = false;
            }
            for(int k = i+1;k<j;++k){
                if(arr[k]!=arr[k-1])st = false;
            }
            for(int k = j;k<=n;++k){
                if(arr[k]>arr[k-1])st = false;
            }
            if(st)isf = true;
        }
    }
    if(isf)printf("YES\n");
    else printf("NO\n");
}
