#include <bits/stdc++.h>
using namespace std;

#define iii tuple<int, int, int>

int n; 
vector<iii> E;

int main() {
    scanf("%d", &n);
    for(int i = 0, a, b, c; i < n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        E.emplace_back(a, b, c);
    }
    for(int cx = 0; cx <= 100; ++cx) for(int cy = 0; cy <= 100; ++cy) {
        int hei = -1;
        bool st = true;
        vector<int> ret;
        for(auto x : E) {
            int u, v, w; tie(u, v, w) = x;
            int val = abs(cx - u) + abs(cy - v);
            if(w) {
                if(hei == -1) hei = w + val; 
                if(hei != w + val) st = false;
            } else ret.emplace_back(val);
        }
        for(auto x : ret) if(hei > x) st = false;
        if(st) return !printf("%d %d %d\n", cx, cy, hei);
    }
}
