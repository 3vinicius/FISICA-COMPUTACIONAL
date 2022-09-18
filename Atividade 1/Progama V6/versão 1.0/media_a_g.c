#include <stdio.h>
#include <math.h>

int main()
{

    float x, y,xx,r1,r2,cx;
    int cont,i;
    double r3;
    float xt[10000], yt[10000];

    FILE*saida;
    saida = fopen("saida.dat", "w");

    cont = 0;
    FILE*file;
    file = fopen("tabela.dat", "r");
    if(file != NULL){
    while (fscanf(file, "%f" "%f", &x,&y) != EOF)
    {

        cont ++;
        xt[cont-1] = x;
        yt[cont-1] = y;

    }
    }
    /* for (i = 0; i <= cont; i++ ) {
      printf("Nota %d = %4.2f\n", i+1, xt[i] );
   } */
    cx=0.1;
    for (xx = - 3; xx <= 3; xx += cx)
    {
        r1=0;
        r2=0;
        r3=0;

        for (i = 1; i <= cont; i++)
        {
            if (abs(xx-xt[i])<cx)
            {
                r1 = r1+1;
                r2 = r2 + yt[i];
                r3 = r3+log(yt[i]);
            }
            
        }
        
        if (r1 > 0)
        {
            fprintf(saida, "%15.10f %15.10f %15.10f\n", xx , r2/r1, exp(r3/r1) );
        }
        
    }
     
}