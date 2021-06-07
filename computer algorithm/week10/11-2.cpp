//avl트리 구현
//이진탐색트리 코드 수정해서 구현함여
//제대로복습하고 이해 ㄱㄱ 

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct TreeNode {
	int key, height;
	struct TreeNode* parent, * left, * right;
}TreeNode;

typedef struct { //이렇게하면 void반환으로 함수작성할 수 있음
	TreeNode* root;
}TreeType;

void initTree(TreeType* T) {
	T->root = (TreeNode*)malloc(sizeof(TreeNode));
	T->root->parent = T->root->left = T->root->right = NULL;
	T->root->height = 0;
}

int isExternal(TreeNode* w) {
	return (w->left == NULL && w->right == NULL);
}//이진탐색트리랑동일

TreeNode* treeSearch(TreeNode* v, int k) {  //treeType이아니라 treeNode를 받고 리턴함요 헷갈 금지금지또금지!
	if (isExternal(v)) return v;
	if (k == v->key) return v;
	else if (k < v->key) return treeSearch(v->left, k);
	else return treeSearch(v->right, k);
}//이진탐색트리랑 동일

void expandExternal(TreeNode* w) {
	TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
	l->left = l->right = NULL;
	l->parent = w;
	r->left = r->right = NULL;
	r->parent = w;
	w->left = l;
	w->right = r;
}

int heightUpdateAndBalanceCheck(TreeNode* w) { //갱신먼저하고 체크해야되네
	TreeNode* l, * r;
	int b;
	if (w == NULL) return 1;
	l = w->left;
	r = w->right;

	w->height = max(r->height, l->height) + 1;

	b = r->height - l->height;
	if (b * b < 2) return 1; //음수고려요
	else return 0;
}

TreeNode* restructure(TreeType* T, TreeNode* x) { //교재 수도코드 보면서 이해요
	TreeNode* y, * z, * a, * b, * c, * T0, * T1, * T2, *T3;
	
	y = x->parent;
	z = y->parent;

	if (z->key < y->key && y->key < x->key) { //RR
		a = z;
		b = y;
		c = x;
		T0 = a->left;
		T1 = b->left;
		T2 = c->left;
		T3 = c->right;
	}

	else if (x->key < y->key && y->key < z->key) { //LL
		a = x;
		b = y;
		c = z;
		T0 = a->left;
		T1 = a->right;
		T2 = b->right;
		T3 = c->right;
	}

	else if (z->key < x->key && x->key < y->key) { //RL
		a = z;
		b = x;
		c = y;
		T0 = a->left;
		T1 = b->left;
		T2 = b->right;
		T3 = c->right;
	}

	else {// LR
		a = y;
		b = x;
		c = z;
		T0 = a->left;
		T1 = b->left;
		T2 = b->right;
		T3 = c->right;
	}

	//3.
	if (z == T->root) {
		T->root = b;  //root 바꿔주기
		b->parent = NULL;
	}
	else if (z->parent->left == z) {
		z->parent->left = b;
		b->parent = z->parent;
	}
	else {
		z->parent->right = b;
		b->parent = z->parent;
	}

	//4.
	a->left = T0;
	T0->parent = a;
	a->right = T1;
	T1->parent = a;
	a->height = max(T0->height, T1->height) + 1;  //잊지마

	//5.
	c->left = T2;
	T2->parent = c;
	c->right = T3;
	T3->parent = c;
	c->height = max(T2->height, T3->height) + 1;

	//6.
	b->left = a;
	a->parent = b;
	b->right = c;
	c->parent = b;
	b->height = max(a->height, c->height) + 1;

	return b;
}

void searchAndFixAfterInsertion(TreeType* T, TreeNode* w) {
	TreeNode* z = w;
	TreeNode* y, * x;


	//1.
	while (heightUpdateAndBalanceCheck(z)) {
		if (z == NULL) return;
		z = z->parent;
	}//여기서 반환안되면 균형 깨졌다는말

	//2.
	if (z->left->height > z->right->height)
		y = z->left;
	else y = z->right;

	//3.
	if (y->left->height > y->right->height)
		x = y->left;
	else if (y->left->height < y->right->height)
		x = y->right;
	else {
		if (y == z->right) x = y->right;
		else x = y->left;
	}

	//4.
	restructure(T, x);
}

void insertItem(TreeType* T, int k) {
	TreeNode* w = treeSearch(T->root, k);
	if (!isExternal(w)) return;
	else {
		w->key = k;
		expandExternal(w);
	}
	searchAndFixAfterInsertion(T, w);
}

int findElement(TreeType* T, int k) {
	TreeNode* w = treeSearch(T->root, k);
	if (isExternal(w)) return 0;
	else return w->key;
}

TreeNode* sibling(TreeNode* z) {
	if (z->parent->left == z) return z->parent->right;
	else return z->parent->left;
}

TreeNode* reduceExternal(TreeType* T, TreeNode* z) {
	TreeNode* w = z->parent; //얘가 삭제할친구
	TreeNode* g = w->parent;
	TreeNode* zs = sibling(z);
	zs->parent = g;

	if (g == NULL) {
		T->root = zs;
	}
	else {
		if (w == g->left) g->left = zs;
		else g->right = zs;
	}
	free(z);
	free(w);
	return zs;
}

TreeNode* inOrederSucc(TreeNode* w) {
	w = w->right;
	while (w->left != NULL) w = w->left;
	return w;
}

void searchAndFixAfterRemoval(TreeType* T, TreeNode* w) {
	TreeNode* z = w;
	TreeNode* y;
	TreeNode* x;
	TreeNode* b;
	x = NULL;
	while (heightUpdateAndBalanceCheck(z)) {
		if (z == NULL) return;
		z = z->parent;
	}

	//2.
	if (z->left->height > z->right->height)
		y = z->left;
	else
		y = z->right;

	//3.
	if (y->left->height > y->right->height)
		x = y->left;
	else if (y->left->height < y->right->height)
		x = y->right;
	else if (z->left == y)
		x = y->left;
	else if (z->right == y)
		x = y->right;

	//4.
	b = restructure(T, x);

	//5.
	searchAndFixAfterRemoval(T, b);
}

int removeElement(TreeType* T, int k) { //수도코드보고 바뀐부분 제대로 이해요
	TreeNode* w = treeSearch(T->root, k);

	if (isExternal(w)) return 0;
	TreeNode* z, * y, *zs;
	z = w->left;
	if (!isExternal(z)) z = w->right;
	if (isExternal(z)) {
		zs = reduceExternal(T, z); //여기바뀜
	}
	else {	//둘다내부노드라면 중위계승자찾기 ㄱㄱ
		z = inOrederSucc(w);
		y = z->parent;	//삭제할노드
		//중위계승자 key값만 복사하고 중위계승자노드를 삭제할거임요
		w->key = y->key;
		zs = reduceExternal(T, z);	//여기바뀜
	}
	searchAndFixAfterRemoval(T, zs->parent);
	return k;
}

void inOrder(TreeNode* root) {
	if (isExternal(root)) return;
	inOrder(root->left);
	printf("[%d] ", root->key);
	inOrder(root->right);

}

int main() {
	TreeType* T = (TreeType*)malloc(sizeof(TreeType));
	initTree(T);

	insertItem(T, 44);
	insertItem(T, 17);
	insertItem(T, 32);
	inOrder(T->root);
	printf("\n");
	insertItem(T, 78);
	insertItem(T, 50);
	insertItem(T, 88);
	inOrder(T->root);
	printf("\n");
	insertItem(T, 48);
	insertItem(T, 62);
	insertItem(T, 54);
	inOrder(T->root);
	printf("\n");

	removeElement(T, 32);
	inOrder(T->root);
	printf("\n");

}