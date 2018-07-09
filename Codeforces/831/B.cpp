#include <cstdio>
#include <map>
using namespace std;
char arr[30];
int main(){
    map<int,int> M;
    scanf("%s",arr);
    for(int i = 0;i<26;++i){
        char now;
        scanf(" %c",&now);
        M[arr[i]] = now;
        M[arr[i]-'a'+'A'] = now-'a'+'A';
    }
    char A[1005];
    scanf("%s",A);
    int idx = 0;
    while(A[idx]!=0){
        if(M[A[idx]]==0)printf("%c",A[idx]);
        else printf("%c",M[A[idx]]);
        idx++;
    }
}
