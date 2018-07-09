#include <bits/stdc++.h>
using namespace std;

int n, m;

class TreeNode{
public:
    int num, key, childLeft, childRight;
    TreeNode *left, *right, *parent;
    TreeNode(int num, int key){
        this->num = num;
        this->key = key;
        this->left = this->right = this->parent = NULL;
        this->childLeft = this->childRight = 0;
    }
    bool isRightOf(TreeNode* P){
        if(P->right != NULL && P->right->num == num)
            return true;
        return false;
    }
    bool isLeftOf(TreeNode* P){
        if(P->left != NULL && P->left->num == num)
            return true;
        return false;
    }
};

class SplayTree{
public:
    TreeNode *root, *tmp;
    SplayTree(){root = tmp = NULL;}
    SplayTree(TreeNode* root){
        this->root = root;
        this->tmp = NULL;
    }
    TreeNode* INSERT(int num, int key);
    TreeNode* INSERT2(int num, int key, TreeNode* current, TreeNode* prev);
    TreeNode* rightRotate(TreeNode* x);
    TreeNode* leftRotate(TreeNode* x);
    TreeNode* findMax();
    TreeNode* Nth_ELEMENT(TreeNode* current, int n);
    SplayTree* SPLIT(int n);
    void JOIN(SplayTree* oth);
    void SPLAY(TreeNode* x);
    void inOrder(TreeNode* current);
};

TreeNode* SplayTree::rightRotate(TreeNode* x){
    TreeNode *y = x->left, *T2 = y->right;
    y->parent = x->parent;
    if(y->parent != NULL){
        TreeNode *P = y->parent;
        if(x->isRightOf(P))
            P->right = y;
        else
            P->left = y;
    }
    x->parent = y;
    y->right = x;
    x->left = T2;
    if(T2 != NULL){
        T2->parent = x;
        x->childLeft = T2->childLeft+T2->childRight+1;
    }
    else
        x->childLeft = 0;
    y->childRight = x->childLeft+x->childRight+1;
    return y;
}

TreeNode* SplayTree::leftRotate(TreeNode* x){
    TreeNode *y = x->right, *T2 = y->left;
    y->parent = x->parent;
    if(y->parent != NULL){
        TreeNode* P = y->parent;
        if(x->isRightOf(P))
            P->right = y;
        else
            P->left = y;
    }
    x->parent = y;
    y->left = x;
    x->right = T2;
    if(T2 != NULL){
        T2->parent = x;
        x->childRight = T2->childLeft+T2->childRight+1;
    }
    else
        x->childRight = 0;
    y->childLeft = x->childLeft+x->childRight+1;
    return y;
}

void SplayTree::SPLAY(TreeNode* x){
    if(x == NULL)
        return;
    while(x->parent != NULL){
        TreeNode *P = x->parent, *G = P->parent;
        if(G != NULL){
            if(x->isRightOf(P)){
                if(P->isRightOf(G)){leftRotate(G); leftRotate(P);}
                else{leftRotate(P); rightRotate(G);}
            }
            else{
                if(P->isLeftOf(G)){rightRotate(G); rightRotate(P);}
                else{rightRotate(P), leftRotate(G);}
            }
        }
        else{
            if(x->isRightOf(P)) leftRotate(P);
            else rightRotate(P);
        }
    }
    root = x;
    return;
}

TreeNode* SplayTree::INSERT2(int num, int key, TreeNode* current, TreeNode* prev){
    if(current == NULL){
        TreeNode* newNode = new TreeNode(num, key);
        newNode->parent = prev;
        if(root == NULL)
            root = newNode;
        tmp = newNode;
        return newNode;
    }
    if(num > current->num){
        current->right = INSERT2(num, key, current->right, current);
        current->childRight = current->right->childLeft + current->right->childRight+1;
    }
    else if(num < current->num){
        current->left = INSERT2(num, key, current->left, current);
        current->childLeft = current->left->childLeft + current->left->childRight+1;
    }
    else
        return NULL;
    return current;
}

TreeNode* SplayTree::INSERT(int num, int key){
    INSERT2(num, key, root, NULL);
    SPLAY(tmp);
    return tmp;
}

TreeNode* SplayTree::Nth_ELEMENT(TreeNode* current, int n){
    int now = current->childLeft+1;
    if(now == n)
        return current;
    else if(now < n)
        return Nth_ELEMENT(current->right, n-now);
    else if(now > n)
        return Nth_ELEMENT(current->left, n);
}

SplayTree* SplayTree::SPLIT(int ret){
    if(ret <= 0){
        SPLAY(Nth_ELEMENT(root, 1));
        SplayTree *newT = new SplayTree(root);
        root = NULL;
        return newT;
    }
    else if(ret > n){
        SPLAY(Nth_ELEMENT(root, n));
        SplayTree *newT = new SplayTree(NULL);
        return newT;
    }
    SPLAY(Nth_ELEMENT(root, ret));
    TreeNode *R = root->right;
    if(R != NULL){
        root->right = NULL;
        root->childRight = 0;
        R->parent = NULL;
    }
    SplayTree* newT = new SplayTree(R);
    return newT;
}

TreeNode* SplayTree::findMax(){
    TreeNode* current = root;
    while(current != NULL && current->right != NULL)
        current = current->right;
    return current;
}

void SplayTree::JOIN(SplayTree* oth){
    TreeNode *other = oth->root;
    if(root == NULL){
        root = other;
        return;
    }
    if(other == NULL)
        return;
    SPLAY(findMax());
    root->right = other;
    root->childRight = other->childLeft+other->childRight+1;
    other->parent = root;
    return;
}

void SplayTree::inOrder(TreeNode* current){
    if(current == NULL)
        return;
    else{
        inOrder(current->left);
        inOrder(current->right);
    }
}

SplayTree t;

int main() {
	#ifdef INPUT
	freopen("r", "r", stdin);
	#endif
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int now;
		scanf("%d", &now);
		t.INSERT(i, now);
	}
	while(m--) {
		int op, A, L, B;
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d %d %d", &A, &L, &B);
			SplayTree* a1;
			SplayTree* a2;
			SplayTree* a3;
			if(A < B) a1 = t.SPLIT(B-1), a2 = t.SPLIT(A+L-1), a3 = t.SPLIT(A-1);
			else a1 = t.SPLIT(A+L-1), a2 = t.SPLIT(A-1), a3 = t.SPLIT(B-1);
			t.JOIN(a2), t.JOIN(a3), t.JOIN(a1);
			delete a1, a2, a3;
		} else {
			scanf("%d", &A);
			printf("%d\n", t.Nth_ELEMENT(t.root, A)->key);
		}
	}
}