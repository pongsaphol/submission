#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
char s[N];
bool ans[N];

int main() {
    int n, k;
    scanf("%d%d %s", &n, &k, s);

    stack<int> pos;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') pos.push(i);
        else {
            cnt += 2;
            ans[i] = true;
            ans[pos.top()] = true;
            pos.pop();
            if (cnt == k) break;
        }
    }
    for (int i = 0; i < n; ++i) if (ans[i])
        printf("%c", s[i]);

    return 0;
}