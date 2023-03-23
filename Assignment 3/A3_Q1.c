#include<stdio.h>
#include<string.h>

int main(){
	int n;
	scanf("%d",&n);
	char a[n];
	scanf("%s",&a);
	int maxcount0 = 0,start, end, maxlength = 0;
	for(int i=0;i<n;i++){
		int count0 = 0;
		int count1 = 0;
		int length = 0;
		for(int j=i;j<n;j++){
			if(a[j] == '0'){
				count0++;
			}
			else{
				count1++;
			}
			start = i, end = j;
			length = end - start + 1;
			if(count0 > count1 && maxcount0 <= count0 && maxlength < length){
				maxcount0 = count0;
				maxlength = length;
			}
		}
	}

	printf("%d\n", maxlength);
	return 0;
}