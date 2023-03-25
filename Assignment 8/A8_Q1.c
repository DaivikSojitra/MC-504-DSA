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

void solve(Treenode* root, int *sum, int dis) {
	if (dis == 0 && !root->left && !root->right) {
		*sum += root->val;
		return;
	}
	if (root->left) solve(root->left, sum, 0);
	if (root->right) solve(root->right, sum, 1);
}

int sumOfLeftLeaves(Treenode* root) {
	int sum = 0;
	if (root == NULL) return 0;
	if (!root->left && !root->right) return sum;
	solve(root, &sum, -1);
	return sum;
}

Treenode* queue[1000];
struct Treenode* constructTree(int arr[], int n) {
	if (n == 0) return NULL;
	Treenode* root = createNode(arr[0]);
	int front = 0, rear = 0;
	queue[rear] = root;
	rear++;
	for (int i = 1; i < n; i = i + 2) {
		Treenode* node = queue[front];
		front++;
		Treenode* leftChild = NULL;
		Treenode* rightChild = NULL;
		if (arr[i] != -1) {
			leftChild = createNode(arr[i]);
			queue[rear] = leftChild;
			rear++;
		}
		if (i + 1 < n && arr[i + 1] != -1) {
			rightChild = createNode(arr[i + 1]);
			queue[rear] = rightChild;
			rear++;
		}
		node->left = leftChild;
		node->right = rightChild;
	}
	return root;
}

int main() {
	int n;
	printf("Enter the Number of Elements\n");
	scanf("%d", &n);

	int* arr = (int*)malloc(n * sizeof(int*));

	for (int i = 0;i < n;i++) {
		scanf("%d", arr + i);
	}

	Treenode* root = constructTree(arr,n);

	printf("Sum of Left Leaves are %d ",sumOfLeftLeaves(root));

	return 0;
}