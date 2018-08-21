#include "laugh.h"
#include <bits/stdc++.h>
using namespace std;

int mx, cnt;

int longest_laugh(string s) {
    for(int i = 0; i < s.size(); ++i) {
        if(i != 0) if(s[i] == s[i-1]) cnt = 0;
        if(s[i] == 'h' || s[i] == 'a') cnt++;
        else cnt = 0;
        mx = max(mx, cnt);
    } 
    return mx;
}
