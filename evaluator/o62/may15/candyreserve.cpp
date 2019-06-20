#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;

const int N = 2e5+5;

int n;
vector<int> coor;
int cost[N];
int dp[4][N];

int main() {
    scanf("%d", &n);
    vector<iii> vec;
    for(int i = 0, l, r, v; i < n; ++i) {
        scanf("%d %d %d", &l, &r, &v);
        coor.emplace_back(l), coor.emplace_back(r);
        vec.emplace_back(l, r, v);
    }
    coor.emplace_back(-1);
    sort(coor.begin(), coor.end());
    coor.resize(unique(coor.begin(), coor.end()) - coor.begin());
    for(int i = 0; i < n; ++i) {
        int l, r, v; tie(l, r, v) = vec[i];
        cost[lower_bound(coor.begin(), coor.end(), l) - coor.begin()] += v;
        cost[lower_bound(coor.begin(), coor.end(), r) - coor.begin()] += v;
    }
    for(int i = 1; i <= 3; ++i)
    for(int j = 1; j < coor.size(); ++j) {
        dp[i][j] = dp[i][j-1];
        if(j != 1) dp[i][j] = max(dp[i][j], dp[i-1][j-2] + cost[j-1]); 
    }
    printf("%d\n", dp[3][coor.size()-1]);
}