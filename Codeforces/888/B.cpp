#include <bits/stdc++.h>
using namespace std;

int cnt[256];

int main() {
    int mx = 0;
    int n; char S[1005];
    cin >> n;
    scanf("%s", S+1);
    for(int i = 1; i <= n; ++i) {
        cnt[S[i]]++;
    }
    cout << min(cnt['U'], cnt['D']) * 2 + min(cnt['L'], cnt['R']) * 2;
}