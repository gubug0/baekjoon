#include <stdio.h>

int n;
int arr[1000000];
int b, c;
long long sum = 0;
int i;
int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &b, &c);


	for (i = 0; i < n; i++) {
		arr[i] -= b;
		sum++;
		if (arr[i] > 0) {
			sum += (arr[i] / c);
			if (arr[i] % c != 0) {
				sum++;
			}
		}
	}

	printf("%lld\n", sum);
	return 0;

}
