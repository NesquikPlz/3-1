//����Ž��Ʈ�� �����ϱ�
//����ؾߵɰ� ���Ƽ� ������

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* parent, * left, * right;
}TreeNode;

typedef struct { //�̷����ϸ� void��ȯ���� �Լ��ۼ��� �� ����
	TreeNode* root;
}TreeType;

void initTree(TreeType* T) {
	T->root = (TreeNode*)malloc(sizeof(TreeNode));
	T->root->parent = T->root->left = T->root->right = NULL;
}

int isExternal(TreeNode* w) {
	return (w->left == NULL && w->right == NULL);
}

TreeNode* treeSearch(TreeNode* v, int k) {  //treeType�̾ƴ϶� treeNode�� �ް� �����Կ� �� ���������Ǳ���!
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
	TreeNode* w = z->parent; //�갡 ������ģ��
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
	else {	//�Ѵٳ��γ���� ���������ã�� ����
		z = inOrederSucc(w);
		y = z->parent;	//�����ҳ��
		//��������� key���� �����ϰ� ��������ڳ�带 �����Ұ��ӿ�
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

	printf("\n������ key �Է�:");
	scanf("%d", &key);
	removeElement(T, key);

	inOrder(T->root);
	printf("\n\n");
}