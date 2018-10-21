#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n;
int A[N], B[N];
int ans[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) scanf("%d", A+i);
    for(int i = 1; i < n; ++i) scanf("%d", B+i);
    for(int j = 0; j < 4; ++j) {
        ans[1] = j;
        bool ast = true;
        for(int i = 1; i < n; ++i) {
            bool st = true;
            for(int k = 0; k < 4; ++k) {
                if(A[i] == (ans[i] | k) and B[i] == (ans[i] & k)) ans[i+1] = k, st = false;
            }
            if(st) {
                ast = false;
                break;
            }
        }
        if(ast) {
            puts("YES");
            for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
            puts("");
            return 0;
        }
    }
    puts("NO");
}
