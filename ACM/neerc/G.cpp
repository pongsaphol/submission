#include <bits/stdc++.h>
using namespace std;

#define long long long
#define all(x) x.begin(), x.end()

const int N = 1e5+5;

int n, d, k, t[N];
long s[3][N];
vector<long> V1, V2;

void update(int x, int v) {
    for(; x <= n; x += x&-x) t[x] += v;
}

int query(int x) {
    int v = 0;
    for(; x > 0; x -= x&-x) v += t[x];
    return v;
}

long f1(int r) { return s[0][n] - s[0][r+d-1] + s[0][r-1] + s[1][r+d-1] - s[1][r-1]; }
long f2(int r) { return s[0][n] - s[0][r+d-1] + s[2][n] - s[2][r-1] - (s[1][n] - s[1][r-1]) - (s[1][n] - s[1][r+d-1]); }
long g1(long r) { return lower_bound(all(V1), r) - V1.begin(); }
long g2(long r) { return lower_bound(all(V2), r) - V2.begin(); }
long p1(int l) { return s[1][l+d-1] - s[1][l-1] - (s[0][l+d-1] - s[0][l-1]); }
long p2(int l) { return s[1][n] - s[1][l-1] + s[0][l-1] + s[1][n] - s[1][l+d-1] - (s[2][n] - s[2][l+d-1]); }

int f(long m) {
    int cnt = 0;
    memset(t, 0, sizeof t);
    for(int i = n-2*d+1; i > 0; --i) {
        update(g1(f1(i+d)), 1);
        cnt += query(g1(m-p1(i)+1)-1);
    }
    memset(t, 0, sizeof t);
    for(int i = n-d; i > 0; --i) {
        update(g2(f2(i+1)), 1);
        if(i <= n-2*d+1) update(g2(f2(i+d)), -1);
        cnt += query(g2(m-p2(i)+1)-1);
    }
    return cnt;
}

int main() {
    scanf("%d %d %d", &n, &d, &k);
    for(int i = 0; i < 3; ++i) for(int j = 1; j <= n; ++j) scanf("%lld", s[i]+j), s[i][j] += s[i][j-1];
    V1.emplace_back((long)-1e18), V2.emplace_back((long)-1e18);
    for(int i = n-d+1; i; --i) V1.emplace_back(f1(i)), V2.emplace_back(f2(i));
    sort(all(V1)), sort(all(V2));
    V1.resize(unique(all(V1)) - V1.begin());
    V2.resize(unique(all(V2)) - V2.begin());
    long l = 1, r = 3e10;
    while(l < r) {
        long m = l + r >> 1;
        if(f(m) >= k) r = m;
        else l = m+1;
    } 
    printf("%lld\n", r);
} 