#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int toprint[1000005];
int arr[10];
int n;
void do1(){
	// have zero in answer
	int idx = 9;
	for(int i = 9;i>=1;--i){
		if(arr[i]<arr[idx]) idx = i;
	}
	if(n-arr[idx]<0)return;
	toprint[0] = idx;
	n -= arr[idx];
	for(int i = 1;n>0;i++,n-=arr[0]){
		toprint[i] = 0;
	}
	for(int i = 0;toprint[i]!=-1;++i){
		printf("%d",toprint[i]);
	}
}

void do2(){

}

int main(){
	freopen("r","r",stdin);
	fill(toprint,toprint+1000005,-1);
	scanf("%d",&n);
	for(int i = 0;i<10;++i)scanf("%d",arr+i);
	int idx = 9;
	//find minimum number from 0 to 9
	for(int i = 9;i>=0;--i){
		if(arr[idx]>arr[i])idx = i;
	}
	if(idx == 0) do1();
	else do2();
}