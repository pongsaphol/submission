#include <bits/stdc++.h>
#define long long long
#define iii tuple<long, long, long>
#define all(x) x.begin(), x.end()
using namespace std;

const int N = 1e5+5;

long n;
long l;
long ans[N];

int main() {
    scanf("%lld %lld", &n, &l);
    vector<iii> V;
    for(int i = 0; i < n; ++i) {
        long x, y; scanf("%lld %lld", &x, &y);
        V.emplace_back(x, y+i, i);
    }
    sort(all(V));
    list<iii> L;
    for(auto &x : V) L.emplace_back(x);
    for(auto it = L.begin(); it != L.end();) {
        while(1) {
            int status = -1; // 1:del now, 2: del nxt;
            iii now = *it;
            auto it2 = it; it2++;
            if(it2 == L.end()) {
                it++;
                break;
            }
            iii rhs = *it2;
            long x1, y1, t1, x2, y2, t2;
            tie(x1, y1, t1) = now;
            tie(x2, y2, t2) = rhs;
            if(x1 == x2) {
                if(y1 > y2) status = 1;
                else if(y1 == y2) {
                    if(t1 < t2) status = 2;
                    else status = 1;
                } else status = 2;
            } else {
                if(y1 > y2) {
                    x2 -= y1 - y2;
                    if(x2 < x1) status = 1;
                    else if(x2 == x1) {
                        if(t1 < t2) status = 0;
                        else status = 1; 
                    } else status = 0;
                } else if(y1 < y2) {
                    x1 += y2 - y1;
                    if(x1 > x2) status = 2;
                    else if(x1 == x2) {
                        if(t1 < t2) status = 2;
                        else status = 0;
                    } else status = 0;
                } else status = 0;
            }
            if(status == 0) {
                it++;
                break;
            }else if(status == 1) {
                auto it3 = it; 
                if(it3 != L.begin()) it3--;
                else it3++;
                L.erase(it), it = it3;
                break;
            } else L.erase(it2);
        }
    }
    for(auto it = L.begin(); it != L.end(); ++it) {
        iii now = *it;
        auto it2 = it; it2++;
        if(it == L.begin()) ans[get<2>(now)] += get<0>(now);
        if(it2 == L.end()) {
            ans[get<2>(now)] += l - get<0>(now) + 1;
            break;
        }
        iii rhs = *it2;
        long x1, y1, t1, x2, y2, t2;
        tie(x1, y1, t1) = now;
        tie(x2, y2, t2) = rhs;
        long p1 = x1, p2 = x2;
        if(y1 > y2) p2 -= y1 - y2;
        if(y1 < y2) p1 += y2 - y1;
        long d = (p2 - p1 - 1) / 2ll;
        if(d < 0) d = 0;
        p1 += d, p2 -= d;
        if(p1 == p2) if(t1 < t2) p2++; else p1--;
        if(p1 + 2 == p2) if(t1 < t2) p1++; else p2--;
        ans[t1] += p1 - x1 + 1, ans[t2] += x2 - p2;
    }    
    long sum = 0;
    for(int i = 0; i < n; ++i) printf("%lld\n", ans[i]), sum += ans[i];
    //assert(sum == l+1);
}
