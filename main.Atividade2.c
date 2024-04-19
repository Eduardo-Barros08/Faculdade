#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int area, volume, lado, res, base, altura, raio;

    printf("Escolha uma forma geométrica\n1-CUbo\n2-Triangulo\n3-Circulo\n>");
    scanf("%d",&res);
switch(res){
       case (1):
                           printf("Digite o valor do lado:\n>");
                           scanf("%d",&lado);
                             //Àrea total
                                area = 6 * (pow(lado,2));

                             //Volume total
                                volume = pow(lado,3);
                           printf("A area total eh:%d \nO volume eh:%d\n", area, volume);


       case(2):
                           printf("Digite o valor da base:\n|>");
                           scanf("%d",&base);
                           printf("Digite o valor da altura:\n>");
                           scanf("%d",&altura);

                           //area total
                           area = ((base * altura)/ 2);

                           printf("A area total eh:>%d \n", area);

      case(3):
                           printf("Digite o valor do raio:\n>");
                           scanf("%d",&raio);

                           //Àrea do círculo
                           area = 3.14 * (raio * raio);

                           printf("A area total eh:>%d \n", area);





    return 0;}}
