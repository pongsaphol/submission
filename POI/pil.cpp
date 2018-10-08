#include <bits/stdc++.h>
using namespace std;

const int N = 3e6+5;

int n, t, A[N];

int main() {
    deque<int> Q1, Q2;
    scanf("%d %d", &t, &n);
    for(int i = 1; i <= n; ++i) scanf("%d", A+i);
    int p = 2;
    Q1.push_back(1), Q2.push_back(1);
    int mx = 0;
    for(int i = 1; i <= n; ++i) {
        while(p != n+1) {
            if(!Q2.empty() && abs(A[Q2.front()] - A[p]) > t || !Q1.empty() && abs(A[Q1.front()] - A[p]) > t) break;
            while(!Q1.empty() && A[Q1.back()] >= A[p]) Q1.pop_back();
            while(!Q2.empty() && A[Q2.back()] <= A[p]) Q2.pop_back();
            Q1.push_back(p), Q2.push_back(p);
            p++;
        }
        mx = max(mx, p - i);
        if(Q1.front() == i) Q1.pop_front();
        if(Q2.front() == i) Q2.pop_front();
    }
    printf("%d\n", mx);
}
