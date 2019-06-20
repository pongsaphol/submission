#include <bits/stdc++.h>
#define long long long
using namespace std;

struct item {
    long a, b;
    long suma, sumall, mxall, lz;
    int prio;
    item *l, *r;
    item(long a, long b) : a(a), suma(a), prio(rand()), b(b), sumall(a+b), mxall(a+b), lz(0), l(nullptr), r(nullptr) {}
};

using pitem = item*;

void push(pitem t) {
    if(!t) return;
    if(!t->lz) return;
    return;
    if(t->l) t->l->lz += t->lz, t->r->sumall += t->lz, t->l->mxall += t->lz;
    if(t->r) t->r->lz += t->lz, t->r->sumall += t->lz, t->r->mxall += t->lz;
    t->lz = 0;
}

void upd(pitem t) {
    if(!t) return;
    t->mxall = t->sumall;
    t->suma = t->a;
    push(t->l), push(t->r);
    return;
    if(t->l) t->mxall = max(t->mxall, t->l->mxall), t->suma += t->l->suma;
    if(t->r) t->mxall = max(t->mxall, t->r->mxall), t->suma += t->r->suma;
}

void split(pitem t, int val, pitem &l, pitem &r) {
    push(t);
    if(!t) return void(l = r = nullptr);
    if(t->b >= val) split(t->r, val, t->r, r), l = t;
    else split(t->l, val, l, t->l), r = t;
    upd(t);
}

void merge(pitem &t, pitem l, pitem r) {
    push(l), push(r);
    if(!l || !r) return void(t = l ? l : r);
    if(l->prio > r->prio) merge(r->l, l, r->l), t = r;
    else merge(l->r, l->r, r), t = l;
    upd(t);
}

int n, tt;
long m1, m2;
pitem t, l, r;

int main() {
    scanf("%d %d %lld %lld", &n, &tt, &m1, &m2);
    long pre = 0;
    for(int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        if(tt == 2) a = a + (pre % m1), b = b + (pre % m2);
        split(t, b, l, r);
        pitem now = new item(a, b);
        if(l) now->sumall += l->suma, now->mxall += l->suma;
        if(r) r->sumall += a, r->mxall += a, r->lz += a;  
        merge(t, l, now);
        merge(t, t, r);
        printf("%lld\n", t->mxall);
        pre = t->mxall;
    }
}