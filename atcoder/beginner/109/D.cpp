#include <bits/stdc++.h>
using namespace std;

#define iiii tuple<int, int, int, int>
#define pii pair<int, int>
#define x first
#define y second

const int N = 505;

int n, m;
int A[N][N];

int main() {
    scanf("%d %d", &n, &m);
    vector<iiii> V;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        int ret; scanf("%d", &ret);
        A[i][j] += ret;
        if(j != m) if(A[i][j] & 1) A[i][j+1]++, V.emplace_back(i, j, i, j+1);
    }
    for(int i = 1; i < n; ++i) if(A[i][m] & 1) A[i+1][m]++, V.emplace_back(i, m, i+1, m);
    printf("%d\n", (int)V.size());
    for(auto x : V) {
        int a, b, c, d; tie(a, b, c, d) = x;
        printf("%d %d %d %d\n", a, b, c, d);
    }
}
