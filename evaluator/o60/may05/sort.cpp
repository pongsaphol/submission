#include "sort_weight.h"
#include <bits/stdc++.h>
using namespace std;

// int mx = 0;

// vector<int> V = {0, 1, 2, 4, 3};

// int get_case() { return 120; }
// // id i weight V[i];
// bool st = false;
// int cnt = 0;
// void sort_init() {
// 	mx = max(mx, cnt);
// 	cnt = 0;
// 	if(st) next_permutation(V.begin(), V.end());
// 	else st = true;
// }

// int sort_weight(int idl, int idr) {
// 	cnt++;
// 	return (V[idl] > V[idr] ? -1 : 1);
// }

// void sort_answer(int a1, int a2, int a3, int a4, int a5) {
// 	if(V[0] == a1 and V[1] == a2 and V[2] == a3 and V[3] == a4 and V[4] == a5) {
// 		printf("Correct : ");
// 	} else  printf("Incorrect : ");
// 	printf("%d\n", cnt);
// }

bool C(int a, int b) { return(sort_weight(a, b) == -1);}

void pre(int a, int b, int c, int d, int e) {
	int arr[5];
	arr[a] = 0;
	arr[b] = 1;
	arr[c] = 2;
	arr[d] = 3;
	arr[e] = 4;
	sort_answer(arr[0], arr[1], arr[2], arr[3], arr[4]);
}

void solve() {
	sort_init();
	vector<int> V = {0, 1, 2, 3, 4};
	if(C(V[0], V[1])) swap(V[0], V[1]);
	if(C(V[2], V[3])) swap(V[2], V[3]);
	if(C(V[1], V[3])) swap(V[1], V[3]), swap(V[0], V[2]);
	int a = V[0];
	int b = V[1];
	int c = V[2];
	int d = V[3];
	int e = V[4];

	//Find position of e in a,b,d
	if (C(e,b))
	{
	    if (!C(e,d))
	    {
	        //a,b,e,d

	        //Find position of c
	        //c is less than d for sure
	        if (C(c,b))
	        {
	            if (!C(c,e))
	            {
	                //a,b,c,e,d
	                pre( a, b, c, e, d );
	            }
	            else
	            {
	                //a,b,e,c,d
	                pre( a, b, e, c, d );
	            }
	        }
	        else
	        {
	            if (!C(c,a))
	            {
	                //c,a,b,e,d
	                pre( c, a, b, e, d );
	            }
	            else
	            {
	                //a,c,b,e,d
	                pre( a, c, b, e, d );
	            }
	        }
	    }
	    else
	    {
	        //a,b,d,e

	        //Find position of c
	        //c is less than d for sure
	        if (C(c,b))
	        {
	            //a,b,c,d,e
	            pre( a, b, c, d, e );
	        }
	        else
	        {
	            if (!C(c,a))
	            {
	                //c,a,b,d,e
	                pre( c, a, b, d, e );
	            }
	            else
	            {
	                //a,c,b,d,e
	                pre( a, c, b, d, e );
	            }
	        }
	    }
	}
	else //e < b
	{
	    if (!C(e,a))
	    {
	        //e,a,b,d

	        //Find position of c
	        //c is less than d for sure
	        if (C(c,a))
	        {
	            if (!C(c,b))
	            {
	                //e,a,c,b,d
	                pre( e, a, c, b, d );
	            }
	            else
	            {
	                //e,a,b,c,d
	                pre( e, a, b, c, d );
	            }
	        }
	        else
	        {
	            if (!C(c,e))
	            {
	                //c,e,a,b,d
	                pre( c, e, a, b, d );
	            }
	            else
	            {
	                //e,c,a,b,d
	                pre( e, c, a, b, d );
	            }
	        }
	    }
	    else
	    {
	        //a,e,b,d

	        //Find position of c
	        //c is less than d for sure
	        if (C(c,e))
	        {
	            if (!C(c,b))
	            {
	                //a,e,c,b,d
	                pre( a, e, c, b, d );
	            }
	            else
	            {
	                //a,e,b,c,d
	                pre( a, e, b, c, d );
	            }
	        }
	        else
	        {
	            if (!C(c,a))
	            {
	                //c,a,e,b,d
	                pre( c, a, e, b, d );
	            }
	            else
	            {
	                //a,c,e,b,d
	                pre( a, c, e, b, d );
	            }
	        }
	    }
	}
	// pre(V[0], V[1], V[2], V[3], V[4]);
}

int main() {
	int T = get_case();
	while(T--) solve();
	// printf("max : %d\n", mx);
}