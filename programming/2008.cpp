#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string> 
#include <queue>
#include <vector>
using namespace std;

string st;
bool cmp(string &a,string &b){
	int asz = a.size();
	int bsz = b.size();
	for(int i = 0;i<min(asz,bsz);++i){
		if(a[i]!=b[i]){
			char nowch = a[i];
			char bowch = b[i];
			if(nowch==st[i])nowch = 'z'+1;
			if(bowch==st[i])bowch = 'z'+1;
			return nowch<bowch;
		}
	}
	return asz<bsz;
}

int main(){
	//		freopen("r","r",stdin);
	int n;
	cin>>n;
	vector<string> V;
	for(int i = 0;i<n;++i){
		string now;
		cin>>now;
		V.push_back(now);
		if(st.size()<now.size()){
			st = now;
		}
	}
	sort(V.begin(),V.end(),cmp);
	queue<char> Q;
	for(int i = 0;i<V[0].size();++i){
		Q.push(V[0][i]);
	}
	Q.push('P');
	for(int i = 1;i<V.size();++i){
		int j;
		for(j = 0;j<V[i-1].size();++j){
			if(V[i-1][j]!=V[i][j]){
				for(int k = j;k<V[i-1].size();++k){
					Q.push('-');
				}
				break;
			}
		}
		for(;j<V[i].size();++j){
			Q.push(V[i][j]);
		}
		Q.push('P');
	}
	printf("%d\n",(int)Q.size());
	while(!Q.empty()){
		printf("%c\n",Q.front());
		Q.pop();
	}
}