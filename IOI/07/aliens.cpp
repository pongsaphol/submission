#include <bits/stdc++.h>
#define long long long 
using namespace std;

long n, m, x, y;
char inp[20];

int main() {
    scanf("%lld %lld %lld", &n, &x, &y);
    long x1 = x, x2 = x;
    for(int i = 30; ~i; --i) if(x1 - (1ll<<i) > 0) {
        printf("examine %lld %lld\n", x1 - (1ll<<i), y);
        fflush(stdout);
        scanf("%s", inp);
        if(!strcmp(inp, "true")) x1 -= (1ll<<i); 
    }
    for(int i = 30; ~i; --i) if(x2 + (1ll<<i) <= n) {
        printf("examine %lld %lld\n", x2 + (1ll<<i), y);
        fflush(stdout);
        scanf("%s", inp);
        if(!strcmp(inp, "true")) x2 += (1ll<<i); 
    }
    long div = x2 - x1 + 1;
    if(div % 5 == 0) {
        long z = div / 5;
        if(z & 1) {
            long mm = (z + 1) >> 1;
            bool st = true;
            printf("examine %lld %lld\n", x1 + z + mm, y);
            fflush(stdout);
            scanf("%s", inp);
            if(!strcmp(inp, "true")) st = false; 
            printf("examine %lld %lld\n", x1 + z + z + z + mm, y);
            fflush(stdout);
            scanf("%s", inp);
            if(!strcmp(inp, "true")) st = false;
            if(st) m = z;
        }
    } 
    if(!m && div % 3 == 0) {

        long z = div / 3;
        if(z & 1) {
            long mm = (z + 1) >> 1;
            printf("examine %lld %lld\n", x1 + z + mm, y);
            fflush(stdout);
            scanf("%s", inp);
            if(!strcmp(inp, "false")) m = z;
        }
    }
    if(!m) m = div;

    while(1) {
        if(x - m <= 0 || y - m <= 0) break;
        printf("examine %lld %lld\n", x - m, y - m);
        fflush(stdout);
        scanf("%s", inp);
        if(!strcmp(inp, "true")) x -= m, y -= m;
        else break;
    }
    while(1) {
        if(x - m - m <= 0) break;
        printf("examine %lld %lld\n", x - m - m, y);
        fflush(stdout);
        scanf("%s", inp);
        if(!strcmp(inp, "true")) x -= m + m;
        else break;
    }
    while(1) {
        if(y - m - m <= 0) break;
        printf("examine %lld %lld\n", x, y - m - m);
        fflush(stdout);
        scanf("%s", inp);
        if(!strcmp(inp, "true")) y -= m + m;
        else break;
    }
    for(int i = 30; ~i; --i) if(x - (1<<i) > 0) {
        printf("examine %lld %lld\n", x - (1<<i), y);
        fflush(stdout);
        scanf("%s", inp);
        if(!strcmp(inp, "true")) x -= (1<<i);
    }
    for(int i = 30; ~i; --i) if(y - (1<<i) > 0) {
        printf("examine %lld %lld\n", x, y - (1<<i));
        fflush(stdout);
        scanf("%s", inp);
        if(!strcmp(inp, "true")) y -= (1<<i);
    }
    long z = m >> 1;
    
    printf("solution %lld %lld\n", x + m + m + z, y + m + m + z);
}
