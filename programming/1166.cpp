#include <cstdio>
#include <algorithm>
#include <queue>
#define x first
#define y second
using namespace std;
typedef pair<int,int> P;
int x[] = {0,0,-1,1},y[] = {-1,1,0,0};
char arr[35][35];
bool chk[35][35];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;++i)scanf("%s",arr[i]+1);
    int idx = 0,mx=  0;
    for(int i = 1;i<=n;++i)for(int j = 1;j<=m;++j){
        //printf("%d %d\n",i,j);
        if(!chk[i][j]){
            chk[i][j] = true;
            bool st = arr[i][j]!='#';
            for(int k = 0;k<4;++k)st&=arr[i+x[k]][j+y[k]]!='#';
            if(st){
                int in = ++idx,cnt = 1;
                queue<P> Q;
                Q.push(P(i,j));
                while(!Q.empty()){
                    int _x = Q.front().x;
                    int _y = Q.front().y;
                    //printf("%d %d->\n",_x,_y);
                    Q.pop();
                    for(int k = 0;k<4;++k){
                        int x_ = _x+x[k];
                        int y_ = _y+y[k];
                        if(x_<1||x_>n||y_<1||y_>m)continue;
                        bool _st = arr[x_][y_]!='#';
                        _st&=!chk[x_][y_];
                        for(int l = 0;l<4;++l)_st&=arr[x_+x[l]][y_+y[l]]!='#';
                        if(_st){
                            cnt++;
                            chk[x_][y_] = true;
                            Q.push(P(x_,y_));
                        }
                    }
                }
                mx = max(mx,cnt);
            }
        }
    }
    printf("%d\n",mx);
}
