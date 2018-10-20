#include <bits/stdc++.h>
using namespace std;

#define long long long
#define pii pair<long, long>
#define x first
#define y second

const int N = 1<<11;

long ans;
int n, m;
char inp[N][N];
int pref[N][N];

long c2(long v) {
    return (v * (v+1)) / 2;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%s", inp[i]+1);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        if(inp[i][j] == '.') pref[j][i] = pref[j-1][i] + 1;
    }
    for(int i = 1 ; i <= m; ++i) {
        stack<pii> S;
        long sum = 0;
        for(int j = 1; j <= n; ++j) {
            int cnt = 1;
            while(!S.empty() && S.top().x >= pref[i][j]) sum -= c2(S.top().x) * S.top().y, cnt += S.top().y, S.pop();
            sum += c2(pref[i][j]) * cnt;
            if(pref[i][j]) S.emplace(pref[i][j], cnt);
            ans += sum * (j+1);
        }
        sum = 0, S = stack<pii>();
        for(int j = n; j > 0; --j) {
            int cnt = 1;
            while(!S.empty() && S.top().x >= pref[i][j]) sum -= c2(S.top().x) * S.top().y, cnt += S.top().y, S.pop();
            sum += c2(pref[i][j]) * cnt;
            if(pref[i][j]) S.emplace(pref[i][j], cnt);
            ans -= sum * j;
        }
    }
    printf("%lld\n", ans);
}
