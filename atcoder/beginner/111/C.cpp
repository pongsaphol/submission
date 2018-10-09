#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define x first
#define y second

const int N = 1e5+5;

int n, s1, s2;
int A[N];
map<int, int> m1, m2;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    for(int i = 1; i <= n; ++i) {
        s1 += i & 1, s2 += ~i & 1;
        if(i & 1) m1[A[i]]++;
        else m2[A[i]]++;
    }
    vector<pii> v1, v2;
    v1.emplace_back(-1, 0), v2.emplace_back(-1, 0);
    for(auto x : m1) v1.emplace_back(x);
    for(auto x : m2) v2.emplace_back(x);
    sort(v1.begin(), v1.end(), [](const pii &a, const pii &b) { return a.y > b.y; });
    sort(v2.begin(), v2.end(), [](const pii &a, const pii &b) { return a.y > b.y; });
    if(v1[0].x == v2[0].x) printf("%d\n", min(s1 - v1[0].y + s2 - v2[1].y, s1 - v2[0].y + s2 - v1[1].y));
    else printf("%d\n", s1 + s2 - v1[0].y - v2[0].y);
}
