#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1005][1005];
bool chk[1005][1005];
class node{
public:
    int a,b,c;
    node(int a,int b,int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    queue<node> Q;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            scanf("%d",&arr[i][j]);
            if(!arr[i][j]){
                chk[i][j] = true;
                Q.push(node(i,j,0));
            }
        }
    }
    while(!Q.empty()){
        int x = Q.front().a;
        int y = Q.front().b;
        int a = Q.front().c;
        Q.pop();
        int _x[] = {x,x,x+1,x-1};
        int _y[] = {y+1,y-1,y,y};
        for(int i = 0;i<4;++i){
            int x_ = _x[i];
            int y_ = _y[i];
            if(x_<1||x_>n||y_<1||y_>m)continue;
            if(chk[x_][y_])continue;
            if(arr[x_][y_]<=a+1)continue;
            chk[x_][y_] = true;
            Q.push(node(x_,y_,a+1));
        }
    }
    int cnt = n*m;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            if(chk[i][j])cnt--;
        }
    }
    printf("%d\n",cnt);
}
