#include <bits/stdc++.h>
using namespace std;

const int N = 1<<18;

int n, k, ans, A[N];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < (1<<n); ++i) scanf("%d", A+i);
    int lastbit = n;
    while(~k & (1 << lastbit)) lastbit--;
    int m1 = 0, m2 = 0;
    for(int i = 0; i < (1<<lastbit); ++i) {
        int ret = A[i];
        if(ret > m1) swap(ret, m1);
        if(ret > m2) swap(ret, m2);
    }
    ans = m1 + m2;
    vector<int> V;
    for(int i = 0; i < (1<<n); ++i) if((k | i) == k) V.emplace_back(A[i]);
}