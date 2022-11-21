#include <stdio.h>

void main()
{
  int i = 0, aprovados = 0, qtdMaiorQueMedia = 0;
  float medias = 0, maior = 0, menor = 999, media, mediaMedias, nota1, nota2, nota3;

  int qtdAlunos;
  scanf("%d", &qtdAlunos);
  float vetMedias[qtdAlunos];

  while (qtdAlunos > i)
  {

    scanf("%f%f%f", &nota1, &nota2, &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    medias += media;

    if (media > maior)
      maior = media;
    if (media < menor)
      menor = media;
    if (media >= 7)
      aprovados += 1;

    vetMedias[i] = media;

    printf("Nota 1: %.2f\nNota 2: %.2f\nNota 3: %.2f\n", nota1, nota2, nota3);
    printf("Media: %.2f\n", media);

    i++;
  }

  mediaMedias = medias / qtdAlunos;
  for (i = 0; i < qtdAlunos; i++)
  {
    if (vetMedias[i] >= mediaMedias)
      qtdMaiorQueMedia += 1;
  }

  printf("\n\nMedia das medias: %.2f\n", mediaMedias);
  printf("Maior: %.2f\nMenor: %.2f\n", maior, menor);
  printf("Aprovados: %d\n", aprovados);
  printf("Quantidade de notas superiores ou iguais a media geral: %d", qtdMaiorQueMedia);
}
