#include <bits/stdc++.h>
using namespace std;

const int N = 1e2+5;

int n, m, ans[N][N], A[N], B[N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%d", A+i);
    for(int j = 0; j < m; ++j) scanf("%d", B+j);
    for(int i = 30; ~i; --i) {
        vector<int> a, b;
        for(int j = 0; j < n; ++j) if(A[j] >> i & 1) a.emplace_back(j);
        for(int j = 0; j < m; ++j) if(B[j] >> i & 1) b.emplace_back(j);
        for(int j = 0; j < min(a.size(), b.size()); ++j) {
            ans[a[j]][b[j]] |= (1 << i);
        }
        if(a.size() > b.size()) {
            if((a.size() - b.size()) & 1) return !printf("NO");
            for(int j = b.size(); j < a.size(); ++j) ans[a[j]][1] |= (1 << i);
        } else if(a.size() < b.size()) {
            if((b.size() - a.size()) & 1) return !printf("NO");
            for(int j = a.size(); j < b.size(); ++j) ans[1][b[j]] |= (1 << i);
        }
    }
    puts("YES");
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) printf("%d ", ans[i][j]);
        puts("");
    }
}