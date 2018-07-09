#include <cstdio>
#include <algorithm>
using namespace std;
int arr[26];
int main(){
    char op;
    while(scanf(" %c",&op)&&op!='!'){
            //printf("-->%c\n",op);
        char idx;scanf(" %c",&idx);idx-='A';
        if(op=='#')printf("%d\n",arr[idx]);
        else if(op=='='){
            int now;
            scanf("%d",&now);
            arr[idx] = now;
        }else{
            char idx2;scanf(" %c",&idx2);idx2-='A';
        //printf("------\n");
            if(op=='+')arr[idx]+=arr[idx2];
            if(op=='-')arr[idx]-=arr[idx2];
            if(op=='*')arr[idx]*=arr[idx2];
            if(op=='/')arr[idx]/=arr[idx2];
        }
    }
    printf("!\n");
}
