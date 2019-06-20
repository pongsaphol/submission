#include <bits/stdc++.h>
#define iii tuple<int, int, int>
using namespace std;

const int N = 1<<17;

int n, m, m1, m2;
int t[N<<1];
bool lz[N<<1];

void build(int p = 1, int l = 1, int r = n) {
    if(l == r) return void(t[p] = 10);
    int m = l + r >> 1;
    build(p<<1, l, m), build(p<<1|1, m+1, r);
    t[p] = t[p<<1] + t[p<<1|1];
}

void push(int p, int l, int r) {
    if(!lz[p]) return;
    t[p] = 0;
    if(l != r) lz[p<<1] = lz[p<<1|1] = true;
    lz[p] = false;    
}

int query(int x, int y, int p = 1, int l = 1, int r = n) {
    push(p, l, r);
    if(x <= l && r <= y) return t[p];
    if(x > r || l > y || x > y) return 0;
    int m = l + r >> 1;
    return query(x, y, p<<1, l, m) + query(x, y, p<<1|1, m+1, r);
}

template<typename T>
void travel(int x, int y, const T &f, int p = 1, int l = 1, int r = n) {
    push(p, l, r); 
    if(x > r || l > y || x > y) return;
    if(x <= l && r <= y) return f(p, l, r);
    int m = l + r >> 1;
    travel(x, y, f, p<<1, l, m), travel(x, y, f, p<<1|1, m+1, r);
    t[p] = t[p<<1] + t[p<<1|1];
}

vector<iii> vec;

void getptr(int x, int y, int p = 1, int l = 1, int r = n) {
    push(p, l, r);
    if(x > r || l > y || x > y) return;
    if(x <= l && r <= y) return void(vec.emplace_back(p, l, r));
    int m = l + r >> 1;
    getptr(x, y, p<<1, l, m);
    getptr(x, y, p<<1|1, m+1, r);
}

int getl(int x, int y, int p = 1, int l = 1, int r = n) {
    push(p, l, r);
    int m = l + r >> 1;
    if(x == l && r == y) {
        if(l == r) return y+1;
        push(p<<1|1, m+1, r);
        if(m1 - t[p<<1|1] > 0) {
            m1 -= t[p<<1|1];
            return getl(x, m, p<<1, l, m);
        } else return getl(m+1, y, p<<1|1, m+1, r); 
    } else {
        if(y <= m) return getl(x, y, p<<1, l, m);
        else return getl(x, y, p<<1|1, m+1, r);
    }
}

int getr(int x, int y, int p = 1, int l = 1, int r = n) {
    push(p, l, r);
    int m = l + r >> 1;
    if(x == l && r == y) {
        if(l == r) return y-1;
        push(p<<1, l, m);
        if(m2 - t[p<<1] > 0) {
            m2 -= t[p<<1];
            return getr(m+1, y, p<<1|1, m+1, r);
        } else return getr(x, m, p<<1, l, m);
    } else {
        if(y <= m) return getr(x, y, p<<1, l, m);
        return getr(x, y, p<<1|1, m+1, r);
    }
}

int main() {
    scanf("%d %d", &n, &m), n--;
    build();
    for(int i = 0, a, b, c; i < m; ++i) {
        scanf("%d %d", &a, &b);
        if(a == 2) {
            travel(b, b, [&](int p, int l, int r) { printf("%d\n", t[p]); });
        } else {
            scanf("%d", &c);
            int ans = c;
            travel(b, b, [&](int p, int l, int r) { ans += t[p], t[p] = 0; });
            m1 = c/2, m2 = c/2;
            int sum1 = query(1, b-1);
            int sum2 = query(b+1, n);
            if(sum1 <= m1) {
                m2 += m1 - sum1;
                m1 = 0;
                travel(1, b-1, [&](int p, int l, int r) { lz[p] = true, push(p, l, r); });
            } 
            if(sum2 <= m2) {
                m1 += m2 - sum2;
                m2 = 0;
                travel(b+1, n, [&](int p, int l, int r) { lz[p] = true, push(p, l, r); });
            }
            if(m1) {
                vec.clear();
                getptr(1, b);
                reverse(vec.begin(), vec.end());
                int x, y;
                for(int i = 0; i < vec.size(); ++i) {
                    int p, l, r; tie(p, l, r) = vec[i];
                    if(m1 - t[p] > 0) m1 -= t[p];
                    else {
                        x = l, y = r;
                        break;
                    } 
                }
                int r = getl(x, y);
                travel(r, b-1, [&](int p, int l, int r) { lz[p] = true, push(p, l, r); });
                travel(r-1, r-1, [&](int p, int l, int r) { t[p] -= m1; });
            }
            if(m2) {
                vec.clear();
                getptr(b, n);
                int x, y;
                for(int i = 0; i < vec.size(); ++i) {
                    int p, l, r; tie(p, l, r) = vec[i];
                    if(m2 - t[p] > 0) m2 -= t[p];
                    else {
                        x = l, y = r;
                        break;
                    } 
                }
                int l = getr(x, y);
                travel(b+1, l, [&](int p, int l, int r) { lz[p] = true, push(p, l, r); });
                travel(l+1, l+1, [&](int p, int l, int r) { t[p] -= m2; });
            }
            travel(b, b, [&](int p, int l, int r) { t[p] = ans; });
        }
    }
}