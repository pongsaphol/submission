#include "dna.h"
#include <bits/stdc++.h>
using namespace std;
 
string analyse(int n, int t) {
    string str;
    srand(time(NULL));
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        str.push_back(rand() % 2 ? '1' : '0');
        if(make_test(str)) { cnt = 0; continue; }
        str.back() = str.back() == '1' ? '0' : '1'; 
        if(++cnt == 19 || i == n-1) {
            int l = 0, r = cnt;
            while(l < r) {
                int m = l + r>> 1;
                string ret;
                for(int j = 0; j <= i-m; ++j) ret.push_back(str[j]);
                if(make_test(ret)) r = m;
                else l = m+1;
            }
            string ret;
            for(int j = 0; j <= i-r; ++j) ret.push_back(str[j]);
            str = ret;
            break;
        }
    }
    while(str.size() != n) {
        str = (rand() % 2 ? "1" : "0") + str;
        if(make_test(str)) continue;
        str[0] = str[0] == '1' ? '0' : '1';
    }
    return str;
}                        