/*
	nome: Luiz Sabadini
	Lista 5. Exercício 4
*/

#include <stdio.h>

int main()
{

	int A[5][5] = {1, 2, 3, 4, 5,
				   6, 7, 8, 9, 10,
				   11, 12, 13, 14, 15,
				   16, 17, 18, 19, 20,
				   21, 22, 23, 24, 25};
	int B[5][5];

	printf("MATRIZ\n\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			B[i][j] = A[i][j] * A[i][j]; // adiciona o valor (i, j) da matriz A elevado ao quadrado na matriz B
			printf(" %d ", B[i][j]);	 // exibe na tela a matriz resultante
		}
		printf("\n");
	}

	return 0;
}