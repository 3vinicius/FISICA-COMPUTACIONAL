#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

double ran1(long int *idum);
#define RAN() ((double)rand()/(double)(RAND_MAX))
#define PI M_PI

int main(int argc, char const *argv[])
{
    FILE*fil;
    fil = fopen("dados20.dat","w");

    int i,j, N = 10000;
    double h,vv[N],hop[N],v[N];
    double aux1,aux2,r1,r2,AA,SS1;
    long int SEED;
    long int l1;

    AA = 20 ;
    

    for (i = 0; i <= N; i++)
    {
        vv[i] = RAN()*0.5;
        hop[i] = 0;
        v[i] = 0;

    }

    r1 = r2 = 0;


    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            aux1=fabs((double)(i-j));
            aux1 = aux1/AA ;
            aux2 = pow(1.+aux1,2);
            aux2 = 1./aux2;
            v[i] = v[i]+vv[j]*aux2;
        }
        r1 = r1 + v[i];
        r2 = r2 + v[i]*v[i];
    }
    
    r1 = r1/(double)N;
    r2 = r2/(double)N;

    for (i = 1; i <= N; i++)
    {
        v[i]=(v[i]-r1)/(sqrt(r2-r1*r1));
        fprintf(fil,"%20.7f\n",v[i]);

    }
    


    




    return 0;
}
