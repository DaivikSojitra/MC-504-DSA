#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top = -1;

int Full(char* st, int n) {
	if (top == n) {
		return 1;
	}
	return 0;
}

int Empty(char* st) {
	if (top == -1) {
		return 1;
	}
	return 0;
}

void push(char* st, char a, int size) {
	if (Full(st, size) == 1) {
		printf("Overflow");
		exit(0);
	}
	top++;
	*(st + top) = a;
}

char pop(char* st) {
	if (Empty(st) == 1) {
		printf("Underflow");
		exit(0);
	}
	char tp = st[top--];
	return tp;
}

int main() {
	//char *arr = "AbnA";
	int n;
	printf("Enter the size of the string you want to check for palindrome\n");
	scanf("%d", &n);
	char* str;
	str = malloc(sizeof(char)*n);
	printf("Enter the string you want to check for palindrome\n");
	scanf("%s",str);
	//printf("%s",ispalimdrome(str) ? "true" : "false");
	n = strlen(str);
	int	a;
	int temp;
	//printf("Enter the size of the stack you want to implement\n");
	//scanf("%d", &n);

	char* ptr = (char*)malloc(n * sizeof(char));
	int i = 0;
	while (i != n / 2) {
		push(ptr, str[i], n);
		i++;
	}
	if (n % 2 != 0)
		i++;
	while (Empty(ptr) != 1) {
		char c = pop(ptr);
		if (c != str[i]) {
			printf("Not Palindrome\n");
			exit(0);
		}
		i++;
	}
	printf("String is Palindrome\n");
	/*do {
		printf("Enter your choice:\n 1. Push \n 2. Pop \n 3. Full \n 4. Empty \n 6. Exit\n");
		scanf("%d", &a);
		switch (a) {
		case 1: printf("Enter the numner you want to insert\n");
			scanf("%d", &temp);
			push(ptr, temp, n);
			break;
		case 2: temp = pop(ptr);
			printf("Removed element is %d", temp);
			break;
		case 3: temp = Full(ptr, n);
			printf("%s", temp ? "Stack is Full" : "We can have More elements in stack");
			break;
		case 4: temp = Empty(ptr);
			printf("%s", temp ? "Stack is Empty" : "We can not POP elements From stack");
			break;
		case 6: exit(0);
		}
	} while (a != 6);*/

	return 0;
}