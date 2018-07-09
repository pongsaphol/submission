#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    stack<char> S;
    while(T--){
        char now;
        scanf(" %c",&now);
        if(S.empty()){
            S.push(now);
        }else if(S.top()==now) S.pop();
        else S.push(now);
    }
    printf("%d\n",S.size());
    if(S.empty())printf("empty");
    while(!S.empty()){
        printf("%c",S.top());
        S.pop();
    }
}
