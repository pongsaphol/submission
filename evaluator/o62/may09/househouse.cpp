#include <bits/stdc++.h>
#include "househouse.h"
using namespace std;

int c, m;

double f(int z) {
    double val = 0;
    for(int i = 1; i < z; ++i) val += 1;
    for(int i = z; i <= m; ++i) val += ((double)z + c - 1) / i;
    return val;
}

int main() {
    househouse_init(c, m);
    int l = 1, r = m+1;
    while(l < r) {
        int m = l + r >> 1;
        if(f(m+1) > f(m)) r = m;
        else l = m+1;
    }
    for(int i = 1; i <= m; ++i) {
        if(i == r) househouse_pay(c);
        else househouse_pay(1);
    }
}
