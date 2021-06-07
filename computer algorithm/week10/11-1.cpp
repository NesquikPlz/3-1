//이진탐색트리 구현하기
//고려해야될거 많아서 열바지

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* parent, * left, * right;
}TreeNode;

typedef struct { //이렇게하면 void반환으로 함수작성할 수 있음
	TreeNode* root;
}TreeType;

void initTree(TreeType* T) {
	T->root = (TreeNode*)malloc(sizeof(TreeNode));
	T->root->parent = T->root->left = T->root->right = NULL;
}

int isExternal(TreeNode* w) {
	return (w->left == NULL && w->right == NULL);
}

TreeNode* treeSearch(TreeNode* v, int k) {  //treeType이아니라 treeNode를 받고 리턴함요 헷갈 금지금지또금지!
	if (isExternal(v)) return v;
	if (k == v->key) return v;
	else if (k < v->key) return treeSearch(v->left, k);
	else return treeSearch(v->right, k);
}

void expandExternal(TreeNode* w) {
	TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
	l->left = l -> right = NULL;
	l->parent = w;
	r->left = r->right = NULL;
	r->parent = w;
	w->left = l;
	w->right = r;
}

void insertItem(TreeType* T, int k) {
	TreeNode* w = treeSearch(T->root, k);
	if (!isExternal(w)) return;
	else {
		w->key = k;
		expandExternal(w);
	}

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

int removeElement(TreeType* T, int k) {
	TreeNode* w = treeSearch(T->root, k);
	
	if (isExternal(w)) return 0;
	TreeNode* z, * y;
	z = w->left;
	if (!isExternal(z)) z = w->right;
	if (isExternal(z)) {
		reduceExternal(T, z);
	}
	else {	//둘다내부노드라면 중위계승자찾기 ㄱㄱ
		z = inOrederSucc(w);
		y = z->parent;	//삭제할노드
		//중위계승자 key값만 복사하고 중위계승자노드를 삭제할거임요
		w->key = y->key;
		reduceExternal(T, z);
	}
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

	insertItem(T, 9);
	insertItem(T, 2);
	insertItem(T, 1);
	insertItem(T, 7);
	insertItem(T, 15);
	insertItem(T, 11);

	inOrder(T->root);
	printf("\n");

	int key;

	printf("\n삭제할 key 입력:");
	scanf("%d", &key);
	removeElement(T, key);

	inOrder(T->root);
	printf("\n\n");
}