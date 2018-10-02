#include <bits/stdc++.h>
using namespace std;

const int N = 256;

int main() {
    string a, b; cin >> a >> b;
    int n = a.size();
    set<int> A[N], B[N];
    for(int i = 0; i < n; ++i) A[a[i]].emplace(b[i]), B[b[i]].emplace(a[i]);
    for(int i = 0; i < 256; ++i) if(A[i].size() > 1 || B[i].size() > 1) return !printf("No");
    puts("Yes");
}
