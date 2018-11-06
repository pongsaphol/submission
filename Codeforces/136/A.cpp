#include <bits/stdc++.h>
using namespace std;

int A[10005];
int n;

int main() {
    cin >> n;
    int ret;
    for(int i = 1; i <= n; ++i) cin >> ret, A[ret] = i;
    for(int i = 1; i <= n; ++i) cout << A[i] << ' ';
}
