#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int left, int right) {
    int mid = (left + right) / 2;
    swap(&arr[mid],&arr[right]);
    int x = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1;j++) {

        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void sort(int* arr, int left, int right) {
    if (left < right) {

        int pivot = partition(arr, left, right);
        sort(arr, left, pivot - 1);
        sort(arr, pivot + 1, right);
    }
}

int find(int* arr,int n, int j) {
    for (int i = 0;i < n;i++) {
        if (arr[i] == j) return 1;
    }
    return 0;
}

int main() {
    int n;
    printf("Enter the Entries of the employees\n");
    scanf("%d", &n);

    int* entry = (int*)malloc(n * sizeof(int));

    int* exit = (int*)malloc(n * sizeof(int));

    printf("\nEnter the entry elements\n");

    for (int i = 0;i < n;i++) {
        scanf("%d", entry + i);
    }

    printf("\nEnter the exit elements\n");

    for (int i = 0;i < n;i++) {
        scanf("%d", exit + i);
    }

    sort(entry, 0, n - 1);

    sort(exit, 0, n - 1);
    int max = 0;
    int second = -1;
    int count = 0;
    for (int i = 1;i < exit[n-1];i++) {
        if (find(entry,n,i) == 1) count++;

        if (max <= count) {
            max = count;
            second = i;
        }
        if (find(exit, n, i) == 1) count--;
    }

    printf("\nMax employees at %d second\n", second);
    return 0;
}