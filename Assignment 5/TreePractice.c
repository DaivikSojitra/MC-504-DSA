#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode {
	int val;
	struct Treenode* left;
	struct Treenode* right;
}Treenode;

Treenode* createNode(int key) {
	Treenode* newNode = (Treenode*)malloc(sizeof(Treenode*));
	newNode->val = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void inorder(Treenode* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

Treenode* insert(Treenode* root, int key) {
	if (root == NULL) {
		return createNode(key);
	}
	if (key < root->val) {
		root->left = insert(root->left, key);
	}
	else {
		root->right = insert(root->right, key);
	}
	return root;
}
Treenode* minvalue(Treenode* root) {
	Treenode* current = root;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}
Treenode* deleteNode(Treenode* root, int key) {
	if (root == NULL) return root;

	if (key < root->val) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->val) {
		root->right = deleteNode(root->right, key);
	}
	else {
		if (root->left == NULL) {
			Treenode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			Treenode* temp = root->left;
			free(root);
			return temp;
		}
		Treenode* temp = minvalue(root->right);

		root->val = temp->val;

		root->right = deleteNode(root->right, temp->val);
	}
	return root;
}
int main() {
	int n;
	printf("Enter the Number of Elements\n");
	scanf("%d", &n);

	Treenode* root = NULL;

	for (int i = 0;i < n;i++) {
		int temp;
		scanf("%d", &temp);
		root = insert(root, temp);
	}

	inorder(root);

	while (1) {
		printf("Enter Your Choice\n");
		printf("1. Add Node \n 2. Delete the Node \n 3. Print the BST \n");
		int a;
		scanf("%d", &a);

		switch (a) {
			int t;
		case 1: printf("Enter the number you want to insert");
				scanf("%d", &t);
				root = insert(root, t);
				break;
		case 2: printf("Enter the number you want to delete");
				scanf("%d", &t);
				root = deleteNode(root, t);
				break;
		case 3: inorder(root);
				break;
		default: printf("Wrong Choice \n");
				break;
		}
	}
	return 0;
}