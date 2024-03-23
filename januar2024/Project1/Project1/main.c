#include <stdio.h>
#include <stdlib.h>

int fja(int* niz, int i) {
	__asm {
		mov esi, niz;
		mov ecx, i;
		shl ecx, 2;
		add esi, ecx;
		mov eax, [esi];
	}
}

int main() {

	int n;
	int** mat;
	scanf("%d", &n);
	mat = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		mat[i] = (int*)malloc(n * sizeof(int*));
		for (int j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	for(int i = 0;i<n-1;i++)
		mat[n-1][i] = fja(mat[i], i);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}