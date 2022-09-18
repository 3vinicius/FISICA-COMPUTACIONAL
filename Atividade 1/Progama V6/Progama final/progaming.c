#include <stdio.h>
#include <math.h>

int main()
{

    FILE*file;
    FILE*saida;
    saida = fopen("saida.dat","w");
    file = fopen("tabela.dat", "r");

    


    float x, y,xx,r1,r2,cx;
    int cont,i;
    double r3;
    double xt[10000], yt[10000];





    cont = 0;
    if(file != NULL){
    while (fscanf(file, "%f" "%f", &x,&y) != EOF)
    {

        cont ++;
        xt[cont-1] = x;
        yt[cont-1] = y;

    }
    }
   



    cx= 0.1 ;
    for (xx = - 3; xx <= 3; xx += cx)
    {
        r1 = 0;
        r2 = 0;
        r3 = 0;

        for (i = 1; i <= cont; i++)
        {
            if (abs(xx-xt[i])<cx)
            {
                r1 = r1 + 1;
                r2 = r2 + yt[i];
                r3 = r3 + log(yt[i]);
            }
            
        }
        
        if (r1 > 0)
        {
            fprintf(saida, "%15.10f %15.10f %15.10f\n", xx , r2/r1, exp(r3/r1) );
        }
        
    }
     
}