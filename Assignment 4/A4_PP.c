#include<stdio.h>
#include<stdlib.h>

int sumOfDigits(int n) {
	int ans = 0;
	while (n) {
		ans += n % 10;
		n = n / 10;
	}
	return ans;
}

int main() {
	int n,q;
	scanf("%d %d", &n, &q);

	int* a;
	a = (int*)malloc(n * sizeof(int));
	int* sum = (int*)malloc(n * sizeof(int));

	for (int i = 0;i < n;i++) {
		scanf("%d", &a[i]);
		sum[i] = sumOfDigits(a[i]);
	}
	for (int i = 0;i < n;i++) {
		//scanf("%d", &a[i]);
		printf("%d ", sum[i]);
	}

	for (int i = 0;i < q;i++) {
		int tm;
		scanf("%d", &tm);
		//int element = a[tm];
		tm--;
		int count = 0;
		for (int j = tm+1;j < n;j++) {
			if (sum[tm] > sum[j] && a[tm] <= a[j]) {
				count++;
				printf("%d", j + 1);
				break;
			}
		}
		if(count == 0)
			printf("%d\n", -1);
	}
	return 0;
}