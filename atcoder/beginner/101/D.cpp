#include <bits/stdc++.h>
using namespace std;

char A[15];

int S(int x) {
    sprintf(A, "%d", x);
    int sum = 0;
    for(int i = 0; A[i]; ++i) sum += A[i] - '0';
    return sum;
}

int main() {
    freopen("out.txt", "w", stdout);
    double mx = 1e9;
    long long seat = 1e9, suan = 1;
    vector<int> V;
    for(int i = 10000000; i >= 1; --i) {
        if(seat * S(i) >= suan * i) seat = i, suan = S(i), V.emplace_back(i); 
        long long gcd = __gcd(seat, suan);
        seat /= gcd, suan /= gcd;
    }
    reverse(V.begin(), V.end());
    for(auto x : V) printf("%d\n", x);
}