#include <bits/stdc++.h>
#define long long long
#define pii pair<long, long>
#define x first
#define y second
using namespace std;

const int N = 1<<19;

int n, z, t[N], t2[N]; 
long ans[N];
vector<long> coor;
vector<pii> q;

int pos(long x) { return upper_bound(coor.begin(), coor.end(), x) - coor.begin(); }

void update(int t[], int l, int r) {
    r++;
    for(; l <= z; l += l & -l) t[l]++;
    for(; r <= z; r += r & -r) t[r]--;
}

int query(int t[], int p) {
    int sum = 0;
    for(; p; p -= p & -p) sum += t[p];
    return sum;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        long a, b;
        scanf("%lld %lld", &a, &b);
        q.emplace_back(a, b);
        coor.emplace_back(a), coor.emplace_back(b);
    }
    sort(coor.begin(), coor.end());
    coor.resize(unique(coor.begin(), coor.end()) - coor.begin());
    z = coor.size();
    for(auto x : q) {
        update(t, pos(x.x), pos(x.y));
        update(t2, pos(x.x), pos(x.y)-1);
    }
    for(int i = 1; i <= z; ++i) ans[query(t, i)]++;
    for(int i = 1; i < z; ++i) ans[query(t2, i)] += coor[i] - coor[i-1] - 1;
    for(int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
}