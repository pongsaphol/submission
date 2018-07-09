#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1e6;

int s[MAXN + 5];

int main(){
	//freopen("r", "r", stdin);
	for(int i = 1; i <= MAXN; ++i){
		for(int j = i; j <= MAXN; j += i){
			s[j]++;
		}
	}
	int a, b;
	scanf("%d%d", &a, &b);
	queue<int> Q;
	for(int i = a; i <= b; ++i){
		if(s[i] == 3) Q.push(i);
	}
	if(Q.empty())printf("-1\n");
	while(!Q.empty()){
		printf("%d ", Q.front());
		Q.pop();
	}
}