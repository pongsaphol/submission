#include <bits/stdc++.h>
using namespace std;

bool status;

bool input() {
    char A[15];
    scanf("%s", A);
    return A[0] == 'b';
}

vector<int> B, W;

void insert(int a, bool b) {
    if(b == status) if(status) B.emplace_back(a); else W.emplace_back(a);
    else if(status) W.emplace_back(a); else B.emplace_back(a);
}

int main() {
    int n; scanf("%d", &n);
    puts("0 100");
    fflush(stdout);
    int l = 1, r =  1e9;
    status = input();
    insert(0, status);
    for(int i = 1; i < n; ++i) {
        int m = (l+r) / 2;
        printf("%d %d\n", m, 100);
        fflush(stdout);
        bool now = input();
        if(now == status) insert(m, now), l = m+1; else insert(m, now), r = m-1;
    }
    #define all(x) x.begin(), x.end()
    sort(all(B)), sort(all(W));
    int x, y;
    if(status) {
        x = B.back();
        if(W.empty()) {
            printf("%d 200 %d 0\n", x, x+1);
            fflush(stdout);
        } else {
            y = W[0];
            printf("%d 200 %d 0\n", x, y);
            fflush(stdout);
        }
    } else {
        x = W.back();
        if(B.empty()) {
            printf("%d 200 %d 0\n", x, x+1);
            fflush(stdout);
        } else {
            y = B[0];
            printf("%d 200 %d 0\n", x, y);
            fflush(stdout);
        }
    }
}
