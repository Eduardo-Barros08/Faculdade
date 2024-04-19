#include <stdio.h>
#include <locale.h>

int n1=20,n2=10, soma, sub;
main(void){
    setlocale(LC_ALL,"Portuguese");
    soma=n1+n2;
    sub=n1-n2;
    printf("O resultado da soma=\n%i\n",soma);
    printf("O resultado da subtração=\n%i\n",sub);
    return 0;
}
