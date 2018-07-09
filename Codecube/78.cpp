#include <cstdio>
int arr[20];
int main(){
	//freopen("r","r",stdin);
	int n;
	scanf("%d",&n);
	int sum = 0;
	for(int i = 1;i<=5;++i){
		scanf("%d",arr+i);
		sum+=arr[i];
	}
	if(sum == n){
		for(int i = 1;i<=5;++i){
			printf("%d ",arr[i]);
		}
		printf("\n");
		return 0;
	}
	for(int i = 1;i<=5;++i){
		if(sum-arr[i] == n){
			for(int j = 1;j<=5;++j){
				if(i==j) printf("0 ");
				else printf("%d ",arr[j]);
			}
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
