#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+5;

int n, k;
char A[N];

int main() {
    scanf("%s", A+1);
    scanf("%d", &k);
    n = strlen(A+1);
    vector<string> ans;
    for(int i = 1; i <= n; ++i) for(int j = i-1; j >= 0; --j) {
        int len = i-j;
        printf("%d %d\n", i, j);
        bool st = true;
        for(int k = 1; k <= (len+1)/2; k += 2) st &= A[j+k] == A[i-k+1];
        string ret;
        if(st) for(int k = j+1; k <= i; ++k) ret.push_back(A[k]);
        if(st) ans.emplace_back(ret);
    }
    puts("->");
    sort(ans.begin(), ans.end());
    for(auto x : ans) cout << x << endl;
    cout << ans.size() << endl;
    cout << ans[k-1] << endl;
}
