#include <bits/stdc++.h>
using namespace std;

char A[15];

int main() {
    scanf("%s", A+1);
    int n = strlen(A+1);
    bool st = true;
    if(A[1] != 'A') st = false;
    vector<int> posC;
    for(int i = 1; i <= n; ++i) {
        if(A[i] == 'C') posC.emplace_back(i);
    }
    if(posC.size() != 1) st = false;
    if(!st) return !printf("WA");
    if(!(posC[0] >= 3 && posC[0] < n)) st = false;
    A[1] = 'a', A[posC[0]] = 'c';
    for(int i = 1; i <= n; ++i) if(A[i] <= 'Z') st = false;
    puts(st ? "AC" : "WA");
}