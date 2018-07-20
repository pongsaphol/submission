#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, A[N];

int main() {
    scanf("%d", &n);
    set<int> S;
    for(int i = 1; i <= n; ++i) scanf("%d", A+i), S.emplace(A[i]);
    int st;
    for(int i = 1; i <= 10000; ++i) if(S.find(i) == S.end()) st = i;
    int cnt = 0;
    for(int i = 2; i <= n; ++i) {
        if(A[i] == A[i-1]) A[i] = st, cnt++;
    }
    printf("%d\n", cnt);
}
