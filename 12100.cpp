#include <stdio.h>
#include <math.h>

int n;
int table[20][20];
int result;
int temp[5][20][20];

void goUp(int arr[20][20]) {
	int temp[20];
	int cnt;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j][i] != 0) {
				temp[cnt] = arr[j][i];
				cnt++;
			}
			arr[j][i] = 0;
		}
		int idx = 0;
		for (int j = 0; j < cnt; j++) {
			if (j+1 < cnt && temp[j] == temp[j+1]) {
				j++;
				arr[idx][i] = temp[j] * 2;
			} else {
				arr[idx][i] = temp[j];
			}
			idx++;
		}
	}
}

void goBottom(int arr[20][20]) {
	int temp[20];
	int cnt;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (arr[j][i] != 0) {
				temp[cnt] = arr[j][i];
				cnt++;
			}
			arr[j][i] = 0;
		}
		int idx = n - 1;
		for (int j = 0; j < cnt; j++) {
			if (j+1 < cnt && temp[j] == temp[j+1]) {
				j++;
				arr[idx][i] = temp[j] * 2;
			} else {
				arr[idx][i] = temp[j];
			}
			idx--;
		}
	}
}

void goLeft(int arr[20][20]) {
	int temp[20];
	int cnt;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != 0) {
				temp[cnt] = arr[i][j];
				cnt++;
			}
			arr[i][j] = 0;
		}
		int idx = 0;
		for (int j = 0; j < cnt; j++) {
			if (j+1 < cnt && temp[j] == temp[j+1]) {
				j++;
				arr[i][idx] = temp[j] * 2;
			} else {
				arr[i][idx] = temp[j];
			}
			idx++;
		}
	}
}

void goRight(int arr[20][20]) {
	int temp[20];
	int cnt;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = n - 1; j >= 0; j--) {
			if (arr[i][j] != 0) {
				temp[cnt] = arr[i][j];
				cnt++;
			}
			arr[i][j] = 0;
		}
		int idx = n - 1;
		for (int j = 0; j < cnt; j++) {
			if (j+1 < cnt && temp[j] == temp[j+1]) {
				j++;
				arr[i][idx] = temp[j] * 2;
			} else {
				arr[i][idx] = temp[j];
			}
			idx--;
		}
	}
}

void cloneArray(int arr1[20][20], int arr2[20][20]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr1[i][j] = arr2[i][j];
		}
	}
}

void process(int level) {
	
	if (level == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (table[i][j] > result) {
					result = table[i][j];
				}
			}
		}
		return;
	}

	cloneArray(temp[level], table);
	
	goUp(table);
	process(level+1);
	cloneArray(table, temp[level]);
	
	goBottom(table);
	process(level+1);
	cloneArray(table, temp[level]);

	goLeft(table);
	process(level+1);
	cloneArray(table, temp[level]);

	goRight(table);
	process(level+1);
	cloneArray(table, temp[level]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &table[i][j]);
		}
	}

	process(0);

	printf("%d\n", result);

	return 0;
}
