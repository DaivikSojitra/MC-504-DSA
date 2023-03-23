#include<stdio.h>

void merge(int a[],int start,int mid,int end){
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int left[n1], right[n2];

	for(int i=0;i<n1;i++){
		left[i] = a[start + i];
	}

	for(int i=0;i<n2;i++){
		right[i] = a[mid + 1 + i];
	}

	int i=0,j=0,k=start;

	while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
          a[k++] = left[i++];
        } else {
          a[k++] = right[j++];
        }
      }
    while (i < n1) {
        a[k++] = left[i++];
      }
    while (j < n2) {
        a[k++] = right[j++];
      }
}

void mergesort(int a[], int start, int end){
	if(start < end){
		int mid = start + (end - start)/2;
		mergesort(a,start,mid);
		mergesort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}

int main(){
	int n;
	printf("Enter the size of the Array");
	scanf("%d",&n);
	int a[n] = {0};
	printf("Enter the array elements in integer");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	int length = sizeof(a)/sizeof(a[0]);

	printf("%d",length);

	if(length == n){
		//Time Complexity O(nlogn)
		//Space Complexity O(n)
	    mergesort(a,0,n);
	    	printf("\nElements After Merge Sort\n");
			for(int i=0;i<n;i++){
				printf("%d ",a[i]);
			}
	}
	else{
		printf("Enter the elements as given in the size");
	}
	return 0;
}