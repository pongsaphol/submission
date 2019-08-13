#include <bits/stdc++.h>
#define long long long 
using namespace std;

const int N = 1e5+5;

int n;
int arr[N];
long op1, op2;
long sum1, sum2;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", arr+i);
    sum1 += arr[i], sum2 += arr[i];
    if(i & 1) {
      if(sum1 <= 0) op1 += abs(sum1)+1, sum1 = 1;
      if(sum2 >= 0) op2 += abs(sum2)+1, sum2 = -1;
    } else {
      if(sum1 >= 0) op1 += abs(sum1)+1, sum1 = -1;
      if(sum2 <= 0) op2 += abs(sum2)+1, sum2 = 1;
    }
  }
  printf("%lld\n", min(op1, op2));
}
