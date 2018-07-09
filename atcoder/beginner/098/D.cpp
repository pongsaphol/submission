#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 2e5+5;

int n, A[N];
int nxt[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    int track = n+1;
    for(int i = n; i; --i) {
        if(A[i]) track = i;
        else nxt[i] = track - 1;
    }
    long cnt = 0;
    for(int i = 1; i <= n; ++i) {
        int val = 0;
        for(int j = i; j <= n+1; ++j) {
            if((val & A[j]) == 0 && j <= n) {
                if(A[j] == 0) j = nxt[j];
                else val |= A[j];
            } else { cnt += j-i; break; }
        }
    }
    printf("%lld\n", cnt);
}