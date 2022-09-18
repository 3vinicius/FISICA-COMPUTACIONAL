#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (2+(IM-1)/NTAB)
#define RNMX (1.0-EPS)
#define pi M_PI
#define N5 200000

double xx[N5];
double yy[N5];

int main()
{
    FILE*fil,*fil1;
    int i,j,NR,cr;
    double r1,r2,m1,m2,zeta;
    char filename[120],filename1[120];

    srand(time(NULL));

    NR = 15000;
    zeta = 8;

    sprintf(filename, "numerosaleatoriosN%izeta%1.1lf,dat",NR,zeta);
    fil = fopen(filename,"w");

    sprintf(filename1, "autocorrelacaoN%izeta%1.1lf,dat",NR,zeta);
    fil1 = fopen(filename1,"w");

    for (i = 1; i <= NR; i++)
    {
        yy[i]=(rand()-0.5);
    }
    
    m1 = m2 = 0;

    for (i = 1; i <= NR; i++)
    {
        xx[i] = 0;
    

    for ( j = 1; j <= NR; j++)
    {
        r1 = fabs((double)(i-j));
        r1 = r1/zeta;
        r1 = exp(-r1);
        xx[i]=xx[i]+yy[j]*r1;

    }
    m1 += xx[i];
    m2 += xx[i]*xx[i];
    
    }

    m1 = m1/(double)NR;
    m2 = m2/(double)NR;

    for (i = 1; i <= NR; i++)
    {
        xx[i] = (xx[i]-m1)/sqrt(m2-m1*m1);

        fprintf(fil,"%20.8g\n",xx[i]);
    }

    for (cr = 0; cr <= 50; cr++)
    {
        r1 = 0;
        r2 = 0;
        for ( i = 1; i <= (NR - cr); i++)
        {
            r1 = r1 + xx[i]*xx[i+cr];
        }
        for (i = 1; i <= (NR); i++)
        {
           r2 = r2 + xx[i];
        }
        r1 = r1/(double)(NR-cr);
        r2 = r2/(double)(NR);

        fprintf(fil1, "%20.8g  %20.8g\n",(double)cr, r1-r2*r2);


    }
    
    



    return 0;
}
