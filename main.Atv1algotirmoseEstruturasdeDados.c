#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// caractere para pular uma linha \n quanto mais desse caractere mais linhas puladas, deve ser colocada entre as ""
int main()
{
    //criei uma variável para guardar um valor do tipo inteiro
    //printf é uma função de saida
int valor,valor2,valor3;
char letra;

letra = 'B';
valor = 22;

printf("Vota\nVota\nE\nConfirma\n%d\nE\n%c\n", valor, letra);

printf("\nDigite um valor inteiro: ");
scanf("%d",&valor);

printf("digitar outro numero inteiro: ");
scanf("%d", &valor2);
return 0;
}


