#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define RAN()  ((double)rand()/(double)(RAND_MAX))

int main(int argc, char const *argv[])
{
    int N, NP=2005,i,j,k,c10,c20;
    double r1,r2,r3,r20,alf,A[NP][NP];
    double x[NP],y[NP],z[NP],erro1;


    alf=1.55;
    N=2000;
    for ( i = 1; i < N; i++){
    for ( j = (i+1); j < N; j++){
        r1 = abs((float)i-(float)j);
        r1=exp(-alf*log(r1));
        A[i][j]=r1;
        A[j][i]=r1;
    }  
    }
    
    for (i = 1; i <= N; i++)
    {
        A[i][i]=(3*RAN()-1.5);
    }
    
    for (i = 1; i <= N; i++)
    {
        x[i]=1./sqrt((float)N);
    }
    
    r20=1000.;
    i=-1;
    c10=0.;
    c20=10.;

    while (i<=0)
    {
        r1=0.;
        for (j = 1; j <= N; j++)
        {
            y[j]=0.;
            for (k = 1; k <= N; k++)
            {
                r1=r1+y[j]*y[j];
            }
            
        }
        r1=sqrt(r1);

        for (j = 1; j <= N; j++)
        {
            x[j]=y[j]/r1;
        }
        

        r2=0.;
        r3=0.;
        for (j = 1; j <= N; j++)
        {
            z[j]=0.;
            for ( k = 1; k <= N; k++)
            {
                z[j]=z[j]+A[j][k]*x[k];
            }
            r2=r2+x[j]*z[j];
        }
        

        erro1=abs(r2-r20);
        c10++;
        if (c10>=c20)
        {
            printf("%10.8g  %10.8g",r2,erro1);
            c20++;
        }
        if (erro1<=0.0001)
        {
            i=1;
            r20=r2;
        }
        
    }
    

    return 0;
}
