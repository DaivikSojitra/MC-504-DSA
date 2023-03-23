#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int sum = 0, count = 0;
	for(int i=0;i<n;i++){
		sum = 0;
		for(int j=i;j<n;j++){
			sum += a[j];
			if(sum % 2 == 0){
				count++;
			}
		}
	}

	printf("%d\n", count);
	return 0;
}