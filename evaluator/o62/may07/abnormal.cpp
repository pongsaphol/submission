#include <bits/stdc++.h>
using namespace std;

int n, g, k, l, r;

const int N = 1e4+5;

char inp[N], outp[N];

void enc1() {
    vector<int> md(l);
    for(int i = 0; i < n; ++i) md[i%l] ^= (inp[i] - '0');
    int ptr = n;
    while(ptr % l != 0) inp[ptr++] = '0';
    for(int i = ptr; i < ptr+l; ++i) inp[i] = (md[i-ptr] + '0');
    printf("%s\n", inp);
}

void dec1() {
    vector<int> md(l);
    for(int i = 0; i < n; ++i) if(inp[i] != 'x') md[i%l] ^= inp[i] - '0';
    int ptr = n;
    while(ptr % l != 0) ptr++;
    for(int i = ptr; i < ptr+l; ++i) if(inp[i] != 'x') md[i-ptr] ^= inp[i] - '0';
    for(int i = 0; i < n; ++i) if(inp[i] == 'x') inp[i] = md[i%l] + '0';
    inp[n] = 0;
    printf("%s\n", inp);
}

void enc3() {
    for(int i = 0; i < n; ++i) inp[i+n] = inp[i+2*n] = inp[i];
    printf("%s\n", inp);
}

void dec3() {
    map<char, int> Mp[N];
    for(int i = 0; i < 3*n; ++i) Mp[i%n][inp[i]]++;
    for(int i = 0; i < n; ++i) {
        int mx = 0;
        for(auto x : Mp[i]) mx = max(mx, x.second);
        for(auto x : Mp[i]) if(x.second == mx) outp[i] = x.first;
    }
    printf("%s\n", outp);
}

int main() {
    cin >> n >> g >> k >> l >> r;
    while(k--) {
        memset(inp, 0, sizeof inp);
        memset(outp, 0, sizeof outp);
        scanf("%s", inp);
        if(g == 1 && r == 1) enc1();
        else if(g == 1 && r == 2) dec1();
        else if(r == 1) enc3();
        else dec3();
    }
}