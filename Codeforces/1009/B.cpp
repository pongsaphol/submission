#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;

char A[100005], ans[100005];
queue<int> pos[3];

int main() {
    scanf("%s", A+1);
    vector<pii> V;
    int n = strlen(A+1);
    int cnt1 = 0;
    for(int i = 1; i <= n; ++i) {
        if(A[i] == '1') cnt1++;
    } 
    bool st = false;
    for(int i = 1; i <= n; ++i) {
        if(st) {
            if(A[i] != '1') printf("%c", A[i]);
        } else if(A[i] == '2') {
            st = true;
            while(cnt1--) printf("1");
            printf("2");
        } else if(A[i] == '0') {
            printf("0");
        }
    }
    if(cnt1> 0) while(cnt1--) printf("1");
}
