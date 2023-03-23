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

int search(int in[], int start, int end, int ele) {
	for (int i = start;i <= end;i++) {
		if (in[i] == ele) {
			return i;
		}
	}
}

int preIndex = 0;
struct TreeNode* createTree(int in[], int pre[], int start, int end) {
	
	if (start > end) {
		return NULL;
	}

	struct TreeNode* Node = createNode(pre[preIndex++]);
	if (start == end)
		return Node;

	int inIndex = search(in, start, end, Node->val);
	Node->left = createTree(in, pre, start, inIndex - 1);
	Node->right = createTree(in, pre, inIndex + 1, end);
	return Node;
}

int front = -1, rear = -1;
struct TreeNode* queue[100];

void push(struct TreeNode* node) {
	if (rear == 99) {
		printf("Overflow");
	}
	rear = rear + 1;
	queue[rear] = node;
}

struct TreeNode* pop() {
	if (rear == -1) {
		printf("UnderFlow");
	}
	front = front + 1;
	struct TreeNode* tmp = queue[front];
	return (tmp);
}

void printLevelwise(struct TreeNode* root) {
	if (root == NULL) {
		return;
	}
	push(root);
	while (front != rear) {
		int size = rear+1;
		for (int i = 0;i < size;i++) {
			struct TreeNode* node = queue[front+1];
			pop();
			if (node != NULL) {
				push(node->left);
				push(node->right);
			}
			if (node == NULL)
				printf("NULL ");
			else
				printf("%d ", node->val);
			
		}
	}
}

int main() {

	int pre[] = { 3,9,20,15,7 };
	int in[] = { 9,3,15,20,7 };

	int n;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	int* in = (int*)malloc(n * sizeof(int));
	int* pre = (int*)malloc(n * sizeof(int));
	printf("In Order please \n");
	for (int i = 0;i < n;i++) {
		scanf("%d", in + i);
	}
	printf("Now Pre Order please \n");
	for (int i = 0;i < n;i++) {
		scanf("%d", pre + i);
	}
	int length = sizeof(in) / sizeof(in[0]);

	struct TreeNode* root = createTree(in, pre, 0, n - 1);

	printLevelwise(root);

	return 0;
}