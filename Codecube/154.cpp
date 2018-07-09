#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;
const int MAX = 1e5;
int P[MAX+5];
vector<int> g[MAX+5];
int dp[MAX+5][2];
int DP[MAX+5][2];
char chk[MAX+5];

void dfs(int idx){
    if(chk[idx]==0)chk[idx] = 1;
    dp[idx][0] = 0,dp[idx][1] = 1;
    for(auto i:g[idx])if(chk[i]!=2){
        dfs(i);
        dp[idx][0] += max(dp[i][0],dp[i][1]);
        dp[idx][1] += dp[i][0];
    }
}

int solve(){
    int n,sum = 0;
    scanf("%d",&n);
    ///push all in graph
    for(int i = 0;i<=MAX;++i){
        g[i].clear();
        chk[i] = 0;
    }
    for(int i = 1;i<=n;++i){
        scanf("%d",P+i);
        g[P[i]].push_back(i);
    }
    for(int i = 1;i<=n;++i)if(!chk[i]){
        int mx = 0;
        deque<int> Q;///directing cycle;
        int now = i;
        while(1){
            if(chk[now]){
                while(Q.front()!=now){
                    chk[Q.front()] = 1;
                    Q.pop_front();
                }
                break;
            }
            chk[now] = 2;
            Q.push_back(now);
            now = P[now];
        }/// end direct cycle
        for(auto i:Q)dfs(i);
        ///end depth first search 
        int size = Q.size();
        DP[Q[0]][0] = -1e9,DP[Q[0]][1] = dp[Q[0]][1];
        for(int i = 1;i<size;++i){
            DP[Q[i]][0] = max(DP[Q[i-1]][0],DP[Q[i-1]][1]) + dp[Q[i]][0];
            DP[Q[i]][1] = DP[Q[i-1]][0] + dp[Q[i]][1];
        }
        mx = max(mx,DP[size-1][0]);
        DP[Q[0]][0] = dp[Q[0]][0],DP[Q[0]][1] = -1e9;
        for(int i = 1;i<size;++i){
            DP[Q[i]][0] = max(DP[Q[i-1]][0],DP[Q[i-1]][1]) + dp[Q[i]][0];
            DP[Q[i]][1] = DP[Q[i-1]][0] + dp[Q[i]][1];
        }
        mx = max(mx,max(DP[size-1][0],DP[size-1][1]));
        sum+=mx;
    }
        for(int i = 1;i<=n;++i){
            printf("%d::%d %d\n",i,dp[i][0],dp[i][1]);
        }
    return n-sum;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        printf("%d\n",solve());
    }
}
