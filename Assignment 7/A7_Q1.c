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

int main() {
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    printf("\nEnter the array elements\n");

    for (int i = 0;i < n;i++) {
        scanf("%d", arr + i);
    }

    sort(arr, 0, n-1);

    printf("Array after sorting\n");

    for (int i = 0;i < n;i++) {
        printf("%d ", *(arr + i));
    }

    return 0;
}