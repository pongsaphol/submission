#include <iostream>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iterator>
#define long long long 
#define P pair<int, int>
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

int A[30];

bool f(int x) {
	int st = A[x*4 + 1];
	for(int i = 2; i <= 4; ++i) {
		if(st != A[x*4+i]) return false;
	}
	return true;
}

bool chk() {
	bool st = true;
	for(int i = 0; i < 6; ++i) {
		st &= f(i);
	}
	return st;
}


void l() {
	int c1 = A[5], c2 = A[6];
	swap(c1, A[17]), swap(c2, A[18]);
	swap(c1, A[21]), swap(c2, A[22]);
	swap(c1, A[13]), swap(c2, A[14]);
	swap(c1, A[5]), swap(c2, A[6]);
}

void r() {
	int c1 = A[5], c2 = A[6];
	swap(c1, A[13]), swap(c2, A[14]);
	swap(c1, A[21]), swap(c2, A[22]);
	swap(c1, A[17]), swap(c2, A[18]);	
	swap(c1, A[5]), swap(c2, A[6]);
}
void u() {
	int c1 = A[1], c2 = A[3];
	swap(c1, A[5]), swap(c2, A[7]);
	swap(c1, A[9]), swap(c2, A[11]);
	swap(c1, A[24]), swap(c2, A[22]);
	swap(c1, A[1]), swap(c2, A[3]);
}
void d() {
	int c1 = A[1], c2 = A[3];
	swap(c1, A[24]), swap(c2, A[22]);
	swap(c1, A[9]), swap(c2, A[11]);
	swap(c1, A[5]), swap(c2, A[7]);
	swap(c1, A[1]), swap(c2, A[3]);
}
void y() {
	int c1 = A[3], c2 = A[4];
	swap(c1, A[17]), swap(c2, A[19]);
	swap(c1, A[10]), swap(c2, A[9]);
	swap(c1, A[16]), swap(c2, A[14]);
	swap(c1, A[3]), swap(c2, A[4]);
}
void z() {
	int c1 = A[3], c2 = A[4];
	swap(c1, A[16]), swap(c2, A[14]);
	swap(c1, A[10]), swap(c2, A[9]);
	swap(c1, A[17]), swap(c2, A[19]);
	swap(c1, A[3]), swap(c2, A[4]);
}
int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	cin.sync_with_stdio(false);
	for(int i = 1; i <= 24; ++i) {
		A[i] = input();
	}
	l();
	bool st = false;
	if(chk()) st = true;
	r();
	r();
	if(chk()) st = true;
	l();
	u();
	if(chk()) st = true;
	d(), d();
	if(chk()) st = true;
	u();
	y();
	if(chk()) st = true;
	z();
	z();
	if(chk()) st = true;
	if(st) printf("YES");
	else printf("NO");
	printf("\n");
}