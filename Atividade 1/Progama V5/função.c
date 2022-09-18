#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    /* Declarando variaveis */
    float y, c, b, a, x, x1, x2, delt, maior,menor;

    /* Manipulação de Arquivos */
    FILE *file;
    file = fopen("Tabela.dat", "w");


    /* Encontrando as raizes */

    delt = -1;
    while (delt < 0)
    {
        /* Entrada de valores */
        printf("\nDigite o valor de a: ");
        scanf("%f", &a );
        printf("\nDigite o valor de b: ");
        scanf("%f", &b );
        printf("\nDigite o valor de c: ");
        scanf("%f", &c );
        delt = ((b*b)-4*a*c); /* Alguns compiladores não reconhecem o valor 0 em funções, por isso troquei pow(b,2) ==> (b*b) */
    if (delt < 0)
    {
        printf("delta não possui raiz em R");
    }else{
        break;
    }
    }
    x1 = ((-b + sqrt(delt))/2*a);
    x2 = ((-b - sqrt(delt))/2*a);
    printf("x1 = %f \nx2 = %f", x1,x2);


    if (x1>x2)
    {
        maior = x1;
        menor = x2;
    }else if (x1=x2)
    {
        maior = x1;
        menor = x2;
    }else{
        maior = x2;
        menor = x1;
    }
    
    
    /* Criação da Tabela */
    
    for (x = menor - 1; x<= maior + 1; x+=0.1)
    {
        y = a*(x*x) + b*x + c;
        fprintf(file,"%10f %10f \n", x,y);
    }
    
    return 0;
}