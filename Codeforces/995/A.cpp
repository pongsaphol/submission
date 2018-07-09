#include <bits/stdc++.h>
using namespace std;

const int N = 55;

struct data {
    int a, b, c;
    data() {}
    data(int a, int b, int c) : a(a), b(b), c(c) { }
};

int n, m, A[5][N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= 4; ++i) for(int j = 1; j <= n; ++j) scanf("%d", A[i] + j);
    vector<data> V;
    bool first = true;
    while (true) {
        bool st = true, moved = false;
        V.emplace_back(-1, -1, -1);
        for(int i = 1; i <= n; ++i) {
            if (A[2][i] != 0 || A[3][i] != 0) st = false;
            if (A[1][i] == A[2][i]) {
                moved = true;
                V.emplace_back(A[2][i], 1, i);
                A[2][i] = 0;
            }
            if (A[3][i] == A[4][i]) {
                moved = true;
                V.emplace_back(A[3][i], 4, i);
                A[3][i] = 0;
            }
        }
        if (st) break;
        if (!moved && first && m == (n<<1)) return !printf("-1");
        first = false;
        V.emplace_back(-2, -2, -2);
        for(int i = 1; i < n; ++i) {
            if (!A[3][i] && A[3][i+1]) {
                V.emplace_back(A[3][i+1], 3, i);
                swap(A[3][i], A[3][i+1]);
            }
            if (A[3][i] == A[4][i]) {
                V.emplace_back(A[3][i], 4, i);
                A[3][i] = 0;
            }
        }
        V.emplace_back(-3, -3, -3);
        if (!A[2][1] && A[3][1]) {
            V.emplace_back(A[3][1], 2, 1);
            swap(A[2][1], A[3][1]);
        }
        if (A[1][1] == A[2][1]) {
            V.emplace_back(A[2][1], 1, 1);
            A[2][1] = 0;
        }
        V.emplace_back(-4, -4, -4);
        for(int i = n; i > 1; --i) {
            if (!A[2][i] && A[2][i-1]) {
                V.emplace_back(A[2][i-1], 2, i);
                swap(A[2][i], A[2][i-1]);
            }
            if (A[1][i] == A[2][i]) {
                V.emplace_back(A[2][i], 1, i);
                A[2][i] = 0;
            }
        }
        if (!A[3][n] && A[2][n]) {
            V.emplace_back(A[2][n], 3, n);
            swap(A[2][n], A[3][n]);
        }
        if (A[3][n] == A[4][n]) {
            V.emplace_back(A[3][n], 4, n);
            A[3][n] = 0;
        }
    }
    int cnt = 0;
    for(auto x : V) if (x.a > 0) ++cnt;
    printf("%d\n", cnt);    
    for(auto x : V) if (x.a > 0) printf("%d %d %d\n", x.a, x.b, x.c);
}