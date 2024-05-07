#include <stdio.h>
#include <stdlib.h>

int main()
{
 int array[5][5];
 int valor = 1;
 int i, j, max, soma;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      array[i][j] = valor;
      valor++;
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }

  max = array[0][0];

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      if (max < array[i][j]) {
        max = array[i][j];
      }
    }
  }

  printf("\nO maior numero do array 2D eh: %d\n", max);

 for (i = 0; i < 5; i++) {
    soma = 0;
    for (j = 0; j < 5; j++) {
      soma += array[i][j];
    }
    printf("A soma dos elementos da linha %d eh: %d\n", i+1, soma);
  }




  return 0;
}
