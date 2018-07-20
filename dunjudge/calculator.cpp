#include <bits/stdc++.h>
using namespace std;

char A[100];

int main() {
    int n1, n2; char op;
    scanf("%d %c %d", &n1, &op, &n2);
    if(op == '+') n1 += n2;
    if(op == '-') n1 -= n2;
    if(op == '*') n1 *= n2;
    printf("%d\n", n1);
}