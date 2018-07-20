#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int A[1005];
    for(int i = 1; i <= n; ++i) cin >> A[i];
    queue<int> Q;
    for(int j = 1; j <= m; ++j) {
        int x; cin >> x;
        Q.emplace(x);
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(!Q.empty() && Q.front() >= A[i]) Q.pop(), cnt++;
    }
    cout << cnt;
}
