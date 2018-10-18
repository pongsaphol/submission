#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> M[5];

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    scanf("%d", &n);
    set<int> S;
    for(int i = 0; i < 5; ++i) for(int j = 0; j < n; ++j) {
        int val; scanf("%d", &val);
        M[i][val] = j;
        S.emplace(val);
    }
    vector<int> V(S.begin(), S.end());
    sort(V.begin(), V.end(), [&](const int &a, const int & b) {
        int cnt = 0;
        for(int i = 0; i < 5; ++i) if(M[i][a] < M[i][b]) cnt++;
        return cnt > 2;
    });
    for(auto x : V) printf("%d\n", x);
}
