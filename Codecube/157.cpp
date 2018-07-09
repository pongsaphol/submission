#include <cstdio>
#include <algorithm>
#include <queue>
#define long long long 
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	long sum = 0;
	queue<long> Q1,Q2;
	bool st = false;
	while(n--){
		char a;long b;
		scanf(" %c %lld", &a, &b);
		if(a == '+') sum += b;
		if(a == 'x' && b == 0ll){
			st = true;
			continue;
		}
		if(a == 'x') Q1.push(b);
		if(a == '-') Q2.push(b);
	}
	while(!Q1.empty()){
		sum *= Q1.front();
		Q1.pop();
	}
	long sum1 = 0;
	while(!Q2.empty()){
		sum1 += Q2.front();
		Q2.pop();
	}
	if(!st)sum -= sum1;
	printf("%lld\n", sum);
}