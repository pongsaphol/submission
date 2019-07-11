/*
We ask a series of number until two bips are detected, during which we can immediately know what the number 
we are looking for is, then we spend the remaining ask quotas to repeatedly press that number until N bips are heard.
The series of questions are as follows.
Ask [1..n/2], then [n/2..1], then [n/2+1..n], then [n..n/2+1]. We observe that there is a 1-to-1 mapping between the
interval of the two bips and the number pressed, and the interval of the two bips is less than N.
*/

#include <bits/stdc++.h>
using namespace std;

char str[20];
int n, m, q;
vector<int> ret;
map<vector<int>, int> Mp;
int step;

void out(int i) {
    printf("%d\n", i);
    fflush(stdout);
    scanf("%s", str);
    if(str[0] == 'B') ret.emplace_back(step);
    ++step;
}

void check() {
    if(Mp[ret]) {
        int v = Mp[ret];
        for(int i = 0; i < 2*n; ++i) out(v);
        exit(0);
    }
}

int main() {
    scanf("%s", str);
    scanf("%d %d %d", &n, &m, &q);
    vector<int> vec;
    for(int i = 1; i <= n/2; ++i) vec.emplace_back(i);
    for(int i = n/2; i >= 1; --i) vec.emplace_back(i);
    int cnt = 0;
    for(int i = (n+2)/2; i <= (n - (n&1)); ++i) vec.emplace_back(i), cnt++;
    for(int i = n; i >= (n+2)/2; --i) vec.emplace_back(i);
    if(cnt & 1) vec.emplace_back(1);
    vec.emplace_back(n);
    for(int delay = 0; delay < n; ++delay) {
        for(int i = 1; i <= n; ++i) {
            vector<int> now;
            for(int j = 0; j < vec.size(); ++j) if(vec[j] == i) {
                int idx = delay + j;
                now.emplace_back(idx);
                if(now.size() == 2) break;
            }
            assert(Mp[now] == 0);
            Mp[now] = i;
        }
    }
    for(auto v : vec) {
        out(v);
        check();
    }
    while(true) {
        out(1);
        check();
    }
}
