#include <bits/stdc++.h>
using namespace std;

#define long long long

const int N = 105;

int n, l, A[N], pos[N];
long k, t[N][N];

void update(long t[], int x, long v) {
    for(int i = x+1; i; i -= i & -i) t[i-1] += v;
}

long query(long t[], int x) {
    long sum = 0;
    for(int i= x+1; i <= n; i += i & -i) sum += t[i-1];
    return sum;
} 

long getv(long t[], int x) { return query(t, x) - query(t, x+1); }

int main() {
    scanf("%d %d %lld", &n, &l, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i), pos[A[i]] = i;
    for(int i = n; i; --i) 
        for(int j = 0; j <= l; ++j) update(t[j], A[i], (j == 0) + query(t[j], A[i]) + (j ? query(t[j-1], 0) - query(t[j-1], A[i]) : 0));
    long ret = -1;
    int ptr = 0, skip = 0;
    vector<int> ans;
    for(int it = 0; it < n; ++it) {
        bool have = true;
        for(int i = 0; i < n; ++i) {
            if(pos[i] <= ptr || ret == k) continue;
            long sumr = 0;
            for(int j = 0; j <= l - skip - (i < A[ptr]); ++j) sumr += getv(t[j], i);
            if(ret + sumr >= k) {
                ans.emplace_back(i), skip += (i < A[ptr]), ptr = pos[i], ret++; 
                have = false;
                break;
            }
            else ret += sumr;
        }
        if(have) break;
    }
    if(ans.empty()) printf("-1");
    else for(auto x : ans) printf("%d ", x);
    puts("");
}

