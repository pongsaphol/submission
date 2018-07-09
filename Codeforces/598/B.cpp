#include <bits/stdc++.h>
using namespace std;int l,r,k;string s;int main() {for(cin>>s>>l;cin>>l>>r>>k;)k%=r-l+1,rotate(&s[l-1],&s[r-k],&s[r]);cout<<s;}