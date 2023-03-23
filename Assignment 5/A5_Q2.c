#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
	struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode*));
	newNode->val = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void inorder(struct TreeNode* t) {
	if (t == NULL) {
		return;
	}
	inorder(t->left);
	printf("%d ", t->val);
	inorder(t->right);
}

struct TreeNode* insert(struct TreeNode* node, int key) {
	if (node == NULL)
		return createNode(key);
	if (key < node->val)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}

int main() {
	int n;
	printf("Enter the number of elements you want to insert \n");
	scanf("%d", &n);

	struct TreeNode* root = NULL;

	for (int i = 0;i < n;i++) {
		int temp;
		printf("Enter %d Element: ", i+1);
		scanf("%d", &temp);
		root = insert(root, temp);
	}
	inorder(root);
	return 0;
}