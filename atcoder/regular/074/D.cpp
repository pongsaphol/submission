#include <bits/stdc++.h>
#define long long long 
using namespace std;

const int N = 3e5+5;

int n, A[N];
long d[N], d2[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= 3*n; ++i) scanf("%d", A+i);
    priority_queue<int, vector<int>, greater<int> > Q;
    for(int i = 1; i <= n; ++i) d[n] += A[i], Q.emplace(A[i]);
    for(int i = n+1; i <= 2*n; ++i) Q.emplace(A[i]), d[i] = d[i-1] + A[i] - Q.top(), Q.pop();
    priority_queue<int> Q2;
    for(int i = 3*n; i > 2*n; --i) d2[n<<1|1] += A[i], Q2.emplace(A[i]);
    for(int i = 2*n; i > n; --i) Q2.emplace(A[i]), d2[i] = d2[i+1] + A[i] - Q2.top(), Q2.pop();
    long mx = -1e18;
    for(int i = n; i <= 2*n; ++i) mx = max(mx, d[i] - d2[i+1]);
    printf("%lld\n", mx);
}