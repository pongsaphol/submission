#include <iostream>
#include <algorithm>
#include <functional>
#include <map>
#include <iterator>
#define P pair<int, int>
#define x first
#define y second
#define long long long
#define all(x) (x).begin(), (x).end()
#define input() (*istream_iterator<int>(cin))
using namespace std;

int n, A[1005];
map<int, int> M;

class node {
public:
	int key;
	node* left;
	node* right;
	node(int _key) {key = _key;}
};

void inorder(node *x) {
	if(x->key == -1) return;
	inorder(x->left);
	printf("%d\n", x->key);
	inorder(x->right);
}

void recur(node *p, int x, int y, int l) {
	if(l <= 0) return;
	p->key = A[x];
	// printf("%d %d %d :: %d\n", x, y, l, p->key);
	p->left = new node(-1);
	p->right = new node(-1);
	if(l == 1) return;
	int nxt = M[A[x+1]];
	int lenr = y - nxt - 1;
	int lenl = l - lenr - 1;
	recur(p->left, x+1, nxt, lenl);
	recur(p->right, x+lenl+1, y-1, lenr);
}

int main() {
	// freopen("r", "r", stdin);
	cin.sync_with_stdio(false);
	n = input();	
	for(int i = 1; i <= n; ++i) A[i] = input();
	for(int i = 1; i <= n; ++i) {
		int now = input();
		M[now] = i;
	}
	node* root = new node(-1);
	recur(root, 1, n, n);
	inorder(root);
}