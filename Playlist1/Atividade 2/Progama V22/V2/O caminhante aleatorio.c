#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
    FILE*fil;
    FILE*fil1;

    fil = fopen("sigmacaminhante.dat", "w");
    fil1 = fopen("histograma.dat", "w");

    double r1,r2,r3,r4,r5,ale;
    int i,j,m,k,c;
    float A[305][40005],pp;
    int n1, n2;
    
    srand(time(NULL));
    

    pp=0.5;
    n1 = 300;
    n2 = 40000;

    for (m = 1; m <= n2; m++)
    {
        A[1][m]=0;
       
    for (j = 2; j <= n1; j++)
    {
        ale = (double)rand() / (double)(RAND_MAX);
        r1 = (double)ale;
       
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
        r2 = r2/r3;
   
        
        fprintf(fil,"%10.d %10.f\n", j, sqrt(r2 - r1*r1));

    }
    
   



    





    
    j = n1;

    for (r1 = -200; r1 <= 200; i+= 4)
    {
        c ++;
        printf("c = %10d\n",c);
        r2 = 0;

        for (m = 1; m <= n2; i++)
        {
            if (fabs(A[j][m]-r1)<r1/2)
            {
                r2++;
            }
            
        }
        fprintf(fil1,"%10.8lf  %10.8lf", r1, r2/(double)n2);
    }
    




    return 0;
}
