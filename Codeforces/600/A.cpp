#include <bits/stdc++.h>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

void red() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
}

const int MAXN = 1e5+5;

char A[MAXN], ans1[MAXN], ans2[MAXN];

int main() {
	red();
	scanf("%s", A);
	int idx = 0;
	ans1[0] = ans2[0] = '\"';
	int ptr1 = 0, ptr2 = 0;
	for(int i = 0; A[i] != -1; ++i) {
		if(A[i] == 0) A[i] = ';', A[i+1] = -1;
		if(A[i] == ';' || A[i] == ',') {
			bool isnum = true;
			if(A[idx] <'1' || A[idx] > '9') isnum = false;
			if(A[idx] == '0' && i-1 == idx) isnum = true;
			for(int j = idx+1; j < i; ++j) if(A[j] < '0' || A[j] > '9') isnum = false;
			if(isnum) {
				ptr1++;
				for(int j = idx; j < i; ++j) ans1[ptr1++] = A[j];
				ans1[ptr1] = ',';
			} else {
				ptr2++;
				for(int j = idx; j < i; ++j) ans2[ptr2++] = A[j];
				ans2[ptr2] = ',';
			}
			idx = i+1;
		} 
	}
	ans1[ptr1] = '\"', ans2[ptr2] = '\"';
	if(ptr1 == 0) ans1[0] = '-';
	if(ptr2 == 0) ans2[0] = '-';
	printf("%s\n%s\n", ans1, ans2);
}