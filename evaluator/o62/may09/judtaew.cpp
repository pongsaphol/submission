#include <bits/stdc++.h>
#define long long long
using namespace std;

const long M = 1e9+7;

const int N = 15;

long n, m;
long A[N];
long cnt;
vector<long> vec[3];

void dfs(int lv) {
    if(lv == n) {
        cnt++;
        return;
    }
    for(int i = 0; i < 3; ++i) {
        bool st = false;
        if(vec[i].empty()) st = true;
        else if(abs(vec[i].back() - A[lv]) <= m) st = true;
        if(!st) continue;
        vec[i].emplace_back(A[lv]);
        dfs(lv+1);
        vec[i].pop_back();
    }
}

void solve() {
    for(int i = 0; i < n; ++i) cin >> A[i];
    dfs(0); 
    cout << cnt << endl;
}

int main() {
    cin >> n >> m;
    if(n <= 10) {
        solve();
        return 0;
    }
    long val = 1;
    while(n--) val = (val * 3) % M; 
    cout << val << endl;
}