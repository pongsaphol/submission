#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, MinOP[N];
vector<int> V;

int main() {
    fill(MinOP + 1, MinOP + N, (int)1e9);
    V.emplace_back(1);
    for(int i = 6; i < N; i *= 6) V.emplace_back(i);
    for(int i = 9; i < N; i *= 9) V.emplace_back(i);
    for(auto x : V) for(int i = x; i < N; ++i) MinOP[i] = min(MinOP[i], MinOP[i-x] + 1);
    scanf("%d", &n);
    printf("%d\n", MinOP[n]);
}