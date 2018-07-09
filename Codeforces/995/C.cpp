#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, A[N];
double X[N], Y[N];

void solve(int u, double x, double y) {
    if(sqrt(pow(x, 2) + pow(y, 2)) > 1.5e6) return;
    if(u == n) {
        for(int i = 0; i < n; ++i) printf("%d ", A[i]);
        exit(0);
    }
    double vx = X[u], vy = Y[u];
    double d1 = sqrt(pow(x + vx, 2) + pow(y + vy, 2));
    double d2 = sqrt(pow(x - vx, 2) + pow(y - vy, 2));
    if (d1 < d2 || (d1 == d2 && rand() == 0)) {
        A[u] = 1;
        solve(u + 1, x + vx, y + vy);
        A[u] = -1;
        solve(u + 1, x - vx, y - vy);
    } else {
        A[u] = -1;
        solve(u + 1, x - vx, y - vy);
        A[u] = 1;
        solve(u + 1, x + vx, y + vy);
    }

}

int main() {
    srand(time(NULL));
    scanf("%d", &n);
    double a = 0, b = 0;
    for(int i = 0; i < n; ++i) scanf("%lf %lf", X+i, Y+i);
    solve(0, 0, 0);
}