#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char arr[205];
int main(){
    scanf("%s",arr+1);
    int len = strlen(arr+1);
    for(int i = 1;i<=len;++i){
        if(arr[i]>='A'&&arr[i]<='Z')arr[i] = arr[i]-'A'+'a';
    }
    int L = (len+1)/2;
    int R = len/2+1;
    bool ispa = true;
    while(L>=1){
        if(arr[L]!=arr[R])ispa = false;
        L--,R++;
    }L++,R = (len)/2;
    bool isdubpa = true;
    while(R>=1){
        if(arr[L]!=arr[R])isdubpa = false;
        L++,R--;
    }L = (len+1)/2+1,R = len;
    while(L<=len){
        if(arr[L]!=arr[R])isdubpa = false;
        L++,R--;
    }
    if(ispa){
        if(isdubpa)printf("Double Palindrome\n");
        else printf("Palindrome\n");
    }else printf("No\n");
}
