#include <bits/stdc++.h>
#define long long long
using namespace std;

const int N = 2e5+5;

int n;
long ans, sumabs;
int A[N];


int main() {
    scanf("%d", &n);
    vector<int> vec;
    for(int i = 1; i <= n; ++i) {
        char c;
        if(i != 1) scanf(" %c", &c); 
        scanf("%d", A+i);
        sumabs += A[i];
        if(c == '-') A[i] *= -1;
        ans += A[i];
        if(vec.empty()) vec.emplace_back(A[i]);
        if(vec.back() >= 0 && A[i] >= 0) vec.back() += A[i];
        else vec.emplace_back(A[i]);
    }
    long pre = 0;
    vec.emplace_back(0);
    for(int i = 0; i < vec.size()-1; ++i) if(vec[i] < 0) {
        pre += 2 * vec[i];
        ans = max(ans, sumabs + pre - 2 * (vec[i+1] >= 0 ? vec[i+1] : 0));
    }
    printf("%lld\n", ans);
}