#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 2e3+5;
const int M = 1e9+7;

int n, m, ret[26], c[N][N], ans[N][26][26];
char A[N];
vector<pii> alp[N][N];

int main() {
    scanf("%s", A), n = strlen(A);
    for_each(A, A+n, [&](char &c) { c -= 'a'; });
    c[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        c[i][0] = 1;
        for(int j = 1; j <= i; ++j) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % M;
    }
    for(int len = 2; len <= n; ++len) {
        memset(ret, 0, sizeof ret);
        for(int i = n-2; ~i; --i) {
            ret[A[i+1]]++;
            for(int j = 0; j < 26; ++j) 
                ans[len][A[i]][j] = (1ll * c[i][len-2] * ret[j] + ans[len][A[i]][j]) % M;
        }
    }
    scanf("%d", &m);
    while(m--) {
        int d; scanf("%d %s", &d, A);
        printf("%d\n", ans[d][A[0]-'a'][A[1]-'a']);
    }
}