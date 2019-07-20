#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
 
int n, k;
vector<pii> vec;
 
double dist(pii p, double x) {
    return hypot((double)p.x - x, (double)p.y);
}
 
double f(double x) { return x * x; }
 
double getx(pii p1, pii p2) {
    double x1 = p1.x, x2 = p2.x, y1 = p1.y, y2 = p2.y;
    return (f(x2) + f(y2) - f(x1) - f(y1)) / (2 * (x2 - x1));
}
 
int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0, x, y; i < n; ++i) {
        scanf("%d %d", &x, &y);
        if(vec.empty()) vec.emplace_back(x, abs(y));
        else if(vec.back().x == x) vec.back().y = min(vec.back().y, abs(y));
        else vec.emplace_back(x, abs(y));
    }
    deque<pii> stk;
    stk.emplace_back(vec[0]), stk.emplace_back(vec[1]);
    for(int i = 2; i < vec.size(); ++i) {
        while(stk.size() >= 2 && getx(stk.back(), vec[i]) <= getx(stk[stk.size()-2], vec[i])) stk.pop_back();
        stk.emplace_back(vec[i]);
    }
    while(stk.size() >= 2 && getx(stk[0], stk[1]) < 0) stk.pop_front();
    while(stk.size() >= 2 && getx(stk[stk.size()-2], stk.back()) > k) stk.pop_back();
    double ans = 0;
    ans = max(ans, dist(stk[0], 0));
    ans = max(ans, dist(stk.back(), k));
    for(int i = 1; i < stk.size(); ++i) {
        double x = getx(stk[i], stk[i-1]);
        ans = max(ans, dist(stk[i], x));
    }
    printf("%.6f\n", ans);
}