#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int arr[10][10];
int O[10][10];
int P[9][2] = {{1,1},{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7}};
int main(){
    int T;
    scanf("%d",&T);
    for(int i = 1;i<=9;++i){
        for(int j = 1;j<=9;++j){
            scanf("%d",O[i]+j);
        }
    }
    for(int  _ = 1;_ <= T;++_){
        bool st = true;
        for(int i = 1;i<=9;++i){
            for(int j = 1;j<=9;++j){
                scanf("%d",&arr[i][j]);
                if(O[i][j]!=0&&arr[i][j]!=O[i][j])st = false;
            }
        }
        for(int i = 1;i<=9;++i){
            set<int> S[2];
            for(int j = 1;j<=9;++j){
                S[0].insert(arr[i][j]);
                S[1].insert(arr[j][i]);
            }
            if(S[0].size()!=9||S[1].size()!=9)st = false;
        }
        for(int _i = 0;_i<9;++_i){
            set<int> S;
            int i_ = P[_i][0];
            int j_ = P[_i][1];
            for(int i = i_;i<i_+3;++i){
                for(int j = j_;j<j_+3;++j){
                    S.insert(arr[i][j]);
                }
            }
            if(S.size()!=9)st = false;
        }
        if(st)printf("%d\n",_);
    }
    printf("END");
}
