#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char const *argv[])
{
    FILE*filec,*fileh;
    filec = fopen("sigmacaminhante.dat","w");
    fileh = fopen("histograma.dat", "w");

    double r1,r2,r3,r4,r5;
    int i,j,m,k;
    double A[35][40005],pp;
    int n1, n2;
    


    pp=0.5;
    n1 = 30;
    n2 = 40000;

    for (m = 1; m <= n2; m++)
    {
        A[1][m]=0;
    
    for (j = 2; j <= n1; i++)
    {
        r1 = rand();
        if (r1 > pp)
        {
            r2 = 1;
        }
        if (r1 < pp)
        {
            r2 = - 1;
        }
        
        A[j][m]=A[j-1][m]+r2;

    }
    }


    for (j = 2; j <= n1; j++)
    {
        r1 = 0;
        r2 = 0;
        r3 = 0;

        for ( m = 1; m <= n2; m++)
        {
            r1 = r1 + A[j][m];
            r2 = r2 + pow(A[j][m],2);
            r3 = r3 + 1;
        }
        r1 = r1/r3;
        r2=r2/r3;
       
        fprintf(filec,"%10.d %10.f", j, sqrt(r2 - pow(r1,2)));

    }
    




    return 0;
}
