#include <bits/stdc++.h>
using namespace std;

#define iii tuple<int, int, int>
#define long long long

const int N = 2005;

int n, m;
long dp[N * 50];
vector<iii> A, B;

int main() {
    scanf("%d", &n);
    for(int i = 0, a, b, c; i < n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        A.emplace_back(a, b, c);
    }
    scanf("%d", &m);
    for(int i = 0, a, b, c; i < m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        B.emplace_back(a, b, c);
    } 
    fill_n(dp, N*50, (long)(-1e18));
    dp[0] = 0;
    sort(A.begin(), A.end(), [&](const iii &a, const iii &b) { return get<1>(a) > get<1>(b); });
    sort(B.begin(), B.end(), [&](const iii &a, const iii &b) { return get<1>(a) > get<1>(b); });
    int ptr = 0;
    for(int i = 0; i < m; ++i) {
        while(ptr != n && get<1>(A[ptr]) >= get<1>(B[i])) {
            int a, b, c; tie(a, b, c) = A[ptr++];
            for(int i = 100000 - a; ~i; --i) dp[i+a] = max(dp[i+a], dp[i] - c);
        }
        int a, b, c; tie(a, b, c) = B[i];
        for(int i = a; i <= 100000; ++i) dp[i-a] = max(dp[i-a], dp[i] + c);
    }
    printf("%lld\n", *max_element(dp, dp+N*50));
}
