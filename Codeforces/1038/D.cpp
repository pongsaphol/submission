#include <bits/stdc++.h>
using namespace std;

#define long long long

int n;

int main() {
    scanf("%d", &n);
    if(n == 1) {
        scanf("%d", &n);
        return !printf("%d\n", n);
    }
    vector<int> A, B;
    for(int i = 1; i <= n; ++i) {
        int ret; scanf("%d", &ret);
        if(ret > 0) A.emplace_back(ret);
        else B.emplace_back(ret);
    }
    long sum = 0;
    if(A.size() == n) {
        for(int x : A) sum += x;
        int mn = *min_element(A.begin(), A.end());
        sum -= mn + mn;
    } else if(B.size() == n) {
        for(int x : B) sum -= x;
        int mx = *max_element(B.begin(), B.end());
        sum += mx + mx;
    } else {
        for(int x : A) sum += x;
        for(int x : B) sum -= x;
    }
    printf("%lld\n", sum);
}
