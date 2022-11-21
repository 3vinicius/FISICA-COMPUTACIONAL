#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

int main(int argc, char const *argv[])
{
    printf("Digite o numero de arquivos\n");
    
    FILE *filearq, *fil;
    filearq = fopen("nomesdosarquivos.dat","r");


    int quantarq,i,cont;
    char filname[1000];
    double a,b;
    double A[10000],B[10000];


    fil = fopen("autocorrelacaoN15000zeta2.0.dat","r"); 
            cont =0.;
            while (fscanf(fil,"%f  %f",&a,&b) != EOF)
            {
                cont++;
                A[cont-1] += a;
                B[cont-1] += b;
            } 
    
        
    }
    

     for (i = 1; i <= cont; i++)
    {
        fprintf(fil,"%13.8g   %13.8g\n",A[cont-1]/3,B[cont-1]/3 );
    } 
    
    return 0;
}
