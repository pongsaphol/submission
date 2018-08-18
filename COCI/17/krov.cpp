#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pii pair<long, long>
#define x first
#define y second

const int N = 1e5+5;

int n;
int A[N], pref[N], posf[N];
vector<int> coor1, coor2;
pii t1[N], t2[N];

int get(vector<int> &v, int x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin();
}

void add(pii &a, pii b) { a = pii(a.x + b.x, a.y + b.y); }

void update(pii t[], int x, pii v) {
    for(; x <= n; x += x&-x) add(t[x], v);
}

pii query(pii t[], int x) {
    pii ret;
    for(; x; x -= x&-x) add(ret, t[x]);
    return ret;
}

long getVal(int m, int i) {
    long sum = 0;
    pii rhs1 = query(t2, get(coor2, m+i));
    pii rhs2 = query(t2, n);
    sum += rhs1.y * (m+i) - rhs1.x + (rhs2.x - rhs1.x) - (rhs2.y - rhs1.y) * (m+i);
    i = n-i+1;
    pii lhs1 = query(t1, get(coor1, m+i));
    pii lhs2 = query(t1, n);
    sum += lhs1.y * (m+i) - lhs1.x + (lhs2.x - lhs1.x) - (lhs2.y - lhs1.y) * (m+i);
    return sum;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    for(int i = 1; i <= n; ++i) pref[i] = A[i]+n-i+1, posf[i] = A[i]+i;
    for(int i = 1; i <= n; ++i) coor1.emplace_back(pref[i]), coor2.emplace_back(posf[i]);
    sort(coor1.begin(), coor1.end()), sort(coor2.begin(), coor2.end());
    coor1.resize(unique(coor1.begin(), coor1.end()) - coor1.begin());
    coor2.resize(unique(coor2.begin(), coor2.end()) - coor2.begin());
    for(int i = 1; i <= n; ++i) update(t2, get(coor2, posf[i]), pii(posf[i], 1));
    long mn = 1e18;
    for(int i = 1; i <= n; ++i) {
        int l = max(i, n-i+1), r = 1e9;
        while(l < r) {
            int m = l + r >> 1;
            if(getVal(m+1, i) > getVal(m, i)) r = m;
            else l = m+1;
        } 
        mn = min(mn, getVal(r, i));
        if(getVal(r, i) == 2) printf("%d %d\n", r, i);
        update(t1, get(coor1, pref[i]), pii(pref[i], 1));
        update(t2, get(coor2, posf[i]), pii(-posf[i], -1));
    }
    printf("%lld\n", mn);
}