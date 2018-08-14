#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

int n, cnt;
vector<pii> A, B; 

int main() {
    scanf("%d", &n);
    for(int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        A.emplace_back(a, b);
    }
    for(int i = 0, a, b; i < n; ++i) {
        scanf("%d %d", &a, &b);
        B.emplace_back(a, b);
    }
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) if(A[i].x < B[j].x && A[i].y < B[j].y) cnt++;
    printf("%d\n", cnt);
}