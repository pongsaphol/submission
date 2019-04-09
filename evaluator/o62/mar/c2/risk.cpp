#include <bits/stdc++.h>
#define long long long
#define pii pair<long, long>
#define x first
#define y second
using namespace std;
const int INF = 1e9;

int n, m, ans;
vector<pii> p1, p2;

long cross(pii a, pii b, pii c) {
    return (c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y);
}

vector<pii> convex_hull(vector<pii> p) {
    pii mn(INF, INF);
    for(auto x : p) if(mn.y > x.y) mn = x;
    vector<pii> ret; ret.emplace_back(mn);
    p.erase(find(p.begin(), p.end(), mn));
    sort(p.begin(), p.end(), [&](const pii &a, const pii &b) {
        return (a.x - mn.x) * (b.y - mn.y) > (a.y - mn.y) * (b.x - mn.x);
    });
    for(auto x : p) {
        while(ret.size() >= 2 && cross(ret[ret.size()-2], ret.back(), x) <= 0) ret.pop_back();
        ret.emplace_back(x);
    }
    return ret;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0, x, y; i < n; ++i) {
        scanf("%d %d", &x, &y);
        p1.emplace_back(x, y);
    }
    for(int i = 0, x, y; i < m; ++i) {
        scanf("%d %d", &x, &y);
        p2.emplace_back(x, y);
    }
    bool st;
    vector<pii> h1 = convex_hull(p1);
    vector<pii> h2 = convex_hull(p2);
    int k = h1.size();
    auto check = [&](int l, int r, pii x) {
        if(l >= k || r >= k || l > r) return;
        st &= (cross(h1[l], h1[l+1], x) >= 0) && (cross(h1[r], h1[(r+1)%k], x) >= 0);
        while(l < r) {
            int m = l + r >> 1;
            if(cross(h1[m], h1[(m+1)%k], x) < cross(h1[(m+1)%k], h1[(m+2)%k], x)) r = m;
            else l = m+1;
        }
        st &= cross(h1[r], h1[(r+1)%k], x) >= 0;
    };
    for(auto x : p2) {
        st = true;
        int divide = min(k, 20);
        int z = k/divide;
        check(0, z, x);
        for(int i = 1; i < divide-1; ++i) check(i*z+1, (i+1)*z, x);
        check((divide-1)*z+1, k-1, x);
        ans += st;
    }
    k = h2.size();
    auto check2 = [&](int l, int r, pii x) {
        if(l >= k || r >= k || l > r) return;
        st &= (cross(h2[l], h2[l+1], x) >= 0) && (cross(h2[r], h2[(r+1)%k], x) >= 0);
        while(l < r) {
            int m = l + r >> 1;
            if(cross(h2[m], h2[(m+1)%k], x) < cross(h2[(m+1)%k], h2[(m+2)%k], x)) r = m;
            else l = m+1;
        }
        st &= cross(h2[r], h2[(r+1)%k], x) >= 0;
    };
    for(auto x : p1) {
        st = true;
        int divide = min(k, 20);
        int z = k/divide;
        check(0, z, x);
        for(int i = 1; i < divide-1; ++i) check(i*z+1, (i+1)*z, x);
        check((divide-1)*z+1, k-1, x);
        ans += st;
    }
    printf("%d\n", ans);
}
/*

4 4
0 0
0 2
2 2
2 0
-1 -1
-1 1
1 1
1 -1

9 4
0 0
2 0
3 0
2 1
3 1
1 3
2 2
2 3
1 5
-1 -1
-1 1
1 1
1 -1
*/
