#include <stdio.h>

int n;
int v[20];
int p[20];
int T[20];
int i,j;
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &v[i], &p[i]);
	}

	for (i = 1; i <= n + 1; i++) {
		for (j = 0; j <= i - 1; j++) {
			if (i - j >= v[j] && T[i] < T[j] + p[i]) {
				T[i] = T[j] + p[i];
			}
		}
	}

	printf("%d\n", T[n + 1]);
	return 0;
}
