#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define strMax 20

typedef struct node {
	char data[strMax];
	struct node* next;
} queueNode;

typedef struct {
	queueNode* head;
	queueNode* tail;
}stringQueue;

queueNode* newNode(char *d) {
	queueNode* temp = (queueNode*)malloc(sizeof(queueNode));
	strcpy(temp->data,d);
	temp->next = NULL;
	return temp;
}
stringQueue* initializeQueue() {
	stringQueue* queue = (stringQueue*)malloc(sizeof(stringQueue*));
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}

int empty(stringQueue *queue) {
	if (queue->tail == NULL) {
		return 1;
	}
	return 0;
}

int enqueue(stringQueue* queue, char* item) {
	queueNode* temp = newNode(item);
	int length = sizeof(item) / sizeof(char*);
	if (queue->tail == NULL) {
		queue->head = queue->tail = temp;
		return length;
	}
	queue->tail->next = temp;
	queue->tail = temp;
	return length;
}
char* dequeue(stringQueue* queue) {
	char* ans = "";
	if (queue->head == NULL) {
		//queue->head = queue->tail = temp;
		printf("Can Not delete anything");
	}
	else {
		queueNode* temp = queue->head;
		queue->head = queue->head->next;
		strcpy(ans,temp->data);
		if (queue->head == NULL)
			queue->tail = NULL;
		free(temp);
	}
	return ans;
}
int main() {
	
	stringQueue* queue = initializeQueue();
	enqueue(queue, "Daivik");
	enqueue(queue, "Sojitra");
	enqueue(queue, "1911");
	dequeue(queue);
	queueNode* temp = queue->head;
	while (temp) {
		printf("%s", temp->data);
		temp = temp->next;
	}
	return 0;
}