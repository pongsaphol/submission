#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, k, q, A[N];
vector<int> V;

int solve(int k) {
    auto it = lower_bound(V.begin(), V.end(), k);
    it++;
}

int main() {
    scanf("%d %d %d", &n, &k, &q);
    for(int i = 0; i < n; ++i) scanf("%d", A+i), V.emplace_back(A[i]);
    sort(V.begin(), V.end());
    deque<int> Q;
    for(int i = 0; i < k; ++i) {
        while(!Q.empty() && A[Q.back()] > A[i]) Q.pop_back();
        Q.push_back(i);
    }
    int ans = 2e9+1;
    for(int i = k; i < n; ++i) {
        ans = min(ans, solve(A[Q.front()]));
        if(Q.front() == i-k) Q.pop_front();
        while(!Q.empty() && A[Q.back()] > A[i]) Q.pop_back();
        Q.push_back(i);
    }
    ans = min(ans, solve(A[Q.front()]));
    printf("%d\n", ans);
}