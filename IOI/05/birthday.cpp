#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int n;
int arr[N], pos[N];
int ans = N;
int pref[N];

int solve() {
    for(int i = 0, val; i < n; ++i) {
        val = arr[i]; 
        if(i >= val) pos[val] = i - val;
        else pos[val] = i - val + n;
    }
    int l = 0, r = n/2;
    while(l < r) {
        int m = l + r >> 1;
        memset(pref, 0, sizeof pref);
        int sz = 2*m + 1;
        if((n % 2 == 0) && (m == (n/2))) sz--;
        int st = n-m;
        if(st == n) st = 0;
        for(int i = 0; i < n; ++i) {
            int s = (st - pos[i] + n) % n;
            int t = (st - pos[i] + sz + n) % n;
            pref[s]++, pref[t]--;
            if(s >= t) pref[n]--, pref[0]++;
        }
        bool state = (pref[0] == n);
        for(int i = 1; i < n; ++i) {
            pref[i] += pref[i-1];
            if(pref[i] == n) state = true;
        }
        if(state) r = m;
        else l = m+1;
    }
    return r;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", arr+i), arr[i]--;
    }
    int ans = solve();
    reverse(arr, arr+n);
    printf("%d\n", min(ans, solve()));
}