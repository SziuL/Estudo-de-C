#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct ONIBUS
{
	int linha, lugares_dsp;
	int matriz_mapa1[4][10];
	int matriz_mapa2[4][10];
};
typedef struct ONIBUS onb;

struct RESERVA
{
	int id1[40], id2[40];
	int linha_res1[40], linha_res2[40];
	int hora_res;
	int poltrona1[40], poltrona2[40];
};
typedef struct RESERVA res;

void programa(onb, res, int, int); // isso possibilita a chamada da função em qualquer lugar do código.

// função da matriz para ser inicializada com 0.
onb limpa(onb busao, int limpo)
{
	if (limpo == 0)
	{
		onb b;
		int z;
		int w;
		int f = 1;
		for (z = 0; z < 4; z++)
		{
			for (w = 0; w < 10; w++)
			{
				b.matriz_mapa1[z][w] = f;
				f++;
			}
		}
		f = 1;
		for (z = 0; z < 4; z++)
		{
			for (w = 0; w < 10; w++)
			{
				b.matriz_mapa2[z][w] = f;
				f++;
			}
		}
		return b;
	}
	return busao;
}

void criar_reserva(onb onibus, res reserva, int codigo)
{
	int poltrona, i, j, line;
	int x, y, f = 1, h = 0;

	printf("Digite a linha que deseja: ");
	scanf("%d", &line);
	while (line < 1 || line > 2)
	{
		printf("Linha inexistente!\n");
		printf("Digite a linha que deseja: ");
		scanf("%d", &line);
	}

	if (line == 1)
	{
		do
		{
			printf("Informe a poltrona que deseja, (ex.: 12): ");
			scanf("%d", &poltrona);

			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 10; j++)
				{
					if (onibus.matriz_mapa1[i][j] == 0)
					{
						f += 1;
					}
				}
			}
			if (f == 40)
			{
				printf("Nao ha lugares disponiveis!\n");
				getch();
				int limpo = 1;
				programa(onibus, reserva, limpo, codigo);
			}
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 10; j++)
				{
					if (poltrona == onibus.matriz_mapa1[i][j] && onibus.matriz_mapa1[i][j] == 0 || poltrona == 0)
					{
						h = 0;
					}
					else if (poltrona == onibus.matriz_mapa1[i][j] && onibus.matriz_mapa1[i][j] != 0 && poltrona != 0)
					{
						onibus.matriz_mapa1[i][j] = 0;
						h = 1;
					}
				}
			}
			if (h == 0)
			{
				printf("Lugar indisponivel. Escolha outro.\n");
				getch();
			}
		} while (h == 0);
		reserva.id1[codigo] = codigo + 1;
		codigo += 1;
	}

	if (line == 2)
	{
		do
		{
			printf("Informe a poltrona que deseja, (ex.: 12): ");
			scanf("%d", &poltrona);

			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 10; j++)
				{
					if (onibus.matriz_mapa2[i][j] == 0)
					{
						f += 1;
					}
				}
			}
			if (f == 40)
			{
				printf("Nao ha lugares disponiveis!\n");
				getch();
				int limpo = 1;
				programa(onibus, reserva, limpo, codigo);
			}
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 10; j++)
				{
					if (poltrona == onibus.matriz_mapa2[i][j] && onibus.matriz_mapa2[i][j] == 0 || poltrona == 0)
					{
						h = 0;
					}
					else if (poltrona == onibus.matriz_mapa2[i][j] && onibus.matriz_mapa2[i][j] != 0 && poltrona != 0)
					{
						onibus.matriz_mapa2[i][j] = 0;
						h = 1;
					}
				}
			}
			if (h == 0)
			{
				printf("Lugar indisponivel. Escolha outro.\n");
				getch();
			}
		} while (h == 0);
		reserva.id2[codigo] = codigo + 1;
		codigo += 1;
	}

	if (line == 1)
	{
		reserva.linha_res1[codigo - 1] = line;
		reserva.poltrona1[codigo - 1] = poltrona;
		system("cls");
		printf("Reserva: %d\nLinha: %d\nHorario: 5h\nPoltrona: %d\n", reserva.id1[codigo - 1], reserva.linha_res1[codigo - 1], reserva.poltrona1[codigo - 1]);
	}
	if (line == 2)
	{
		reserva.linha_res2[codigo - 1] = line;
		reserva.poltrona2[codigo - 1] = poltrona;
		system("cls");
		printf("Reserva: %d\nLinha: %d\nHorario: 17h\nPoltrona: %d\n", reserva.id2[codigo - 1], reserva.linha_res2[codigo - 1], reserva.poltrona2[codigo - 1]);
	}
	getch();
	int limpo = 1;
	programa(onibus, reserva, limpo, codigo);
}

void excluir_reserva(onb onibus, res reserva, int limpo, int codigo)
{
	int reser, poltrona;
	int i, j, f = 0, k = 0;

	printf("Digite o numero da reserva que deseja cancelar: ");
	scanf("%d", &reser);

	for (i = 0; i < 40; i++)
	{
		if (reserva.id1[i] == reser)
		{
			k = 1;
			poltrona = reserva.poltrona1[i];
			reserva.id1[i] = 0;
			for (i = 0; i < 40; i++)
			{
				for (j = 0; j < 40; j++)
				{
					f++;
					if (f == poltrona)
					{
						onibus.matriz_mapa1[i][j] = poltrona;
					}
				}
			}
		}
	}

	if (k == 0)
	{
		f = 0;
		for (i = 0; i < 40; i++)
		{
			if (reserva.id2[i] == reser)
			{
				k = 1;
				poltrona = reserva.poltrona2[i];
				reserva.id2[i] = 0;
				for (i = 0; i < 40; i++)
				{
					for (j = 0; j < 40; j++)
					{
						f++;
						if (f == poltrona)
						{
							onibus.matriz_mapa2[i][j] = poltrona;
						}
					}
				}
			}
		}
	}

	if (k != 1)
	{
		system("cls");
		printf("Reserva nao encontrada para ser excluida!\n");
	}
	else
	{
		system("cls");
		printf("Reserva excluida com sucesso!\n");
	}

	getch();
	programa(onibus, reserva, limpo, codigo);
}

void imprime(onb onibus, res reserva, int limpo, int codigo)
{
	int i, j, f = 0;
	int linha;
	printf("Qual dos onibus (linhas) deseja informacoes? (1 ou 2): ");
	scanf("%d", &linha);
	while (linha < 1 || linha > 2)
	{
		system("cls");
		printf("Linha inexistente!\n");
		printf("Digite a linha que deseja: ");
		scanf("%d", &linha);
	}

	if (linha == 1)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (onibus.matriz_mapa1[i][j] == 0)
				{
					f += 1;
				}
			}
		}
		system("cls");
		printf("MAPA LINHA 1:\n");
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 10; j++)
			{
				printf("%d ", onibus.matriz_mapa1[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("Lugares disponiveis: %d\n", 40 - f);
		printf("Horario: 5h\n");
		printf("Linha: 1\n");
	}
	if (linha == 2)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (onibus.matriz_mapa2[i][j] == 0)
				{
					f += 1;
				}
			}
		}
		system("cls");
		printf("MAPA LINHA 2:\n");
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 10; j++)
			{
				printf("%d ", onibus.matriz_mapa2[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("Lugares disponiveis: %d\n", 40 - f);
		printf("Horario: 17h\n");
		printf("Linha: 2\n");
	}
	getch();
	programa(onibus, reserva, limpo, codigo);
}

void programa(onb onibus, res reserva, int limpo, int codigo)
{
	system("cls");

	int choice;
	onb busao;

	printf("------------------------------------\n");
	printf("1 - Criar reserva\n");
	printf("2 - Excluir reserva\n");
	printf("3 - Imprimir dados do onibus\n");
	printf("4 - Sair\n");
	printf("------------------------------------\n");
	printf("O que deseja fazer?\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		onibus = limpa(onibus, limpo);
		limpo = 1;
		criar_reserva(onibus, reserva, codigo);
		programa(onibus, reserva, limpo, codigo);
		break;
	case 2:
		onibus = limpa(onibus, limpo);
		limpo = 1;
		excluir_reserva(onibus, reserva, limpo, codigo);
		programa(onibus, reserva, limpo, codigo);
		break;
	case 3:
		onibus = limpa(onibus, limpo);
		limpo = 1;
		imprime(onibus, reserva, limpo, codigo);
		programa(onibus, reserva, limpo, codigo);
		break;
	case 4:
		printf("Obrigado pela visita! Volte sempre!!\n");
		getch();
		system("cls");
		exit(1);
		break;
	default:
		printf("Valor invalido!\n");
		getch();
		programa(onibus, reserva, limpo, codigo);
		break;
	}
}

int main()
{
	int limpo = 0;
	onb onibus;
	res reserva;
	int codigo = 0;
	programa(onibus, reserva, limpo, codigo);
}