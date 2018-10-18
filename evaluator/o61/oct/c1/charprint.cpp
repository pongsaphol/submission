#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 3e5;

int t[N+1];
vector<int> pos[128];
int n, m, met;
char A[N+5], B[N+5];

void update(int x) {
    for(; x <= N; x += x & -x) t[x]--;
}

int query(int x) {
    int v = 0;
    for(; x > 0; x -= x & -x) v += t[x];
    return v;
}

int main() {
    scanf("%d", &met);
    scanf("%s %s", A+1, B+1);
    n = strlen(A+1), m = strlen(B+1);
    for(int i = 1; i <= n; ++i) 
        pos[A[i]].emplace_back(i), t[i] = i & -i;
    for(int i = 'a'; i <= 'z'; ++i) reverse(pos[i].begin(), pos[i].end());
    long sum = 0;
    for(int i = 1; i <= m; ++i) {
        if(pos[B[i]].empty()) return puts("-1"), 0;
        sum += query(pos[B[i]].back());
        if(met) update(pos[B[i]].back());
        pos[B[i]].pop_back();
        
    }
    return !printf("%lld\n", sum); 
    
}