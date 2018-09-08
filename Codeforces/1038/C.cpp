#include <bits/stdc++.h>
using namespace std;

#define long long long

int n;
priority_queue<int> A, B;

int main() {
    scanf("%d", &n);
    for(int i = 1, ret; i <= n; ++i) {
        scanf("%d", &ret);
        A.emplace(ret);
    }
    for(int i = 1, ret; i <= n; ++i) {
        scanf("%d", &ret);
        B.emplace(ret);
    }
    long sum = 0;
    for(int i = 1; i <= 2*n; ++i) {
        if(i&1) {
            if(A.empty()) B.pop();
            else if(B.empty()) sum += A.top(), A.pop();
            else if(A.top() > B.top()) sum += A.top(), A.pop();
            else B.pop();
        } else {
            if(B.empty()) A.pop();
            else if(A.empty()) sum -= B.top(), B.pop();
            else if(B.top() > A.top()) sum -= B.top(), B.pop();
            else A.pop();
        }
    }
    printf("%lld\n", sum);
}
