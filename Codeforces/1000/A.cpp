#include <bits/stdc++.h>
using namespace std;

char str[8];

int cmp(){
	if(strcmp(str,"M") == 0) return 0;
	else if(strcmp(str,"L") == 0) return 1;
	else if(strcmp(str,"XL") == 0) return 1;
	else if(strcmp(str,"XXL") == 0) return 1;
	else if(strcmp(str,"XXXL") == 0) return 1;
	else if(strcmp(str,"S") == 0) return 2;
	else if(strcmp(str,"XS") == 0) return 2;
	else if(strcmp(str,"XXS") == 0) return 2;
	else if(strcmp(str,"XXXS") == 0) return 2;
}

int n;
vector<int> bucket[8];
vector<int> bucket2[8];

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		scanf("%s", str);
		bucket[strlen(str)].emplace_back(cmp());
	}
	for(int i = 1; i <= n; ++i){
		scanf("%s", str);
		bucket2[strlen(str)].emplace_back(cmp());
	}
	int s = 0;
	int mc = 0;
	int sc = 0;
	int lc = 0;
	for(int j : bucket[1]){
		if(j == 0) mc++;
		else if(j == 1) lc++;
		else sc++;
	}
	int mc2 = 0;
	int sc2 = 0;
	int lc2 = 0;
	for(int j : bucket2[1]){
		if(j == 0) mc2++;
		else if(j == 1) lc2++;
		else sc2++;
	}
	int buf1 = min(mc,mc2);
	int buf2 = min(sc,sc2);
	int buf3 = min(lc,lc2);
	mc -= buf1;
	mc2 -= buf1;
	sc -= buf2;
	sc2 -= buf2;
	lc -= buf3;
	lc2 -= buf3;
	s += mc + mc2 + sc + sc2 + lc + lc2;
	s -= max({mc,mc2,sc,sc2,lc,lc2});
	for(int i = 2; i <= 4; i++){
		sc = 0;
		lc = 0;
		for(int j : bucket[i]){
			if(j == 1) lc++;
			else sc++;
		}
		sc2 = 0;
		lc2 = 0;
		for(int j : bucket2[i]){
			if(j == 1) lc2++;
			else sc2++;
		}
		buf2 = min(sc,sc2);
		buf3 = min(lc,lc2);
		sc -= buf2;
		sc2 -= buf2;
		lc -= buf3;
		lc2 -= buf3;
		s += sc + sc2 + lc + lc2;
		s -= max({sc,sc2,lc,lc2});
	}
	printf("%d\n", s);
	return 0;
}