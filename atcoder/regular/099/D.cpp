#include <bits/stdc++.h>
#define long long long 
#define pll pair<long, long>
#define x first
#define y second
using namespace std;

long n;
vector<long> ret;

long s(long v) {
    int sum = 0;
    while(v) sum += v % 10, v /= 10; 
    return sum;
}

int main() {
    long a = 1e16, b = 1;
    pll z(a, b);
    for(int len = 12; ~len; --len) {
        for(int i = 999; i >= 100; --i) {
            char ret[20];
            sprintf(ret, "%d", i);
            for(int j = 3; j < len + 3; ++j) ret[j] = '9';
            ret[len+3] = 0;
            long num; sscanf(ret, "%lld", &num);
            pll now(num, s(num));
            if(z.x * now.y >= now.x * z.y)
                swap(z, now), ::ret.emplace_back(num);
        }
    }
    for(long i = 99; i; --i) {
        pll now(i, s(i)); 
        if(z.x * now.y >= now.x * z.y)
            swap(z, now), ret.emplace_back(i); 
    }
    reverse(ret.begin(), ret.end());
    int n; scanf("%d", &n);
    for(int i = 0; i < n; ++i) printf("%lld\n", ret[i]); 
}