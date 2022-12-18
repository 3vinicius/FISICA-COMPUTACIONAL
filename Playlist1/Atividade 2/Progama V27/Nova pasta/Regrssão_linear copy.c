#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    FILE*fil,*fil1;
    fil = fopen("xesp.dat", "r");
    fil1 = fopen("regressao.dat", "w");


    int c = 1000;
    double x[c],y[c];
    double r1,r2,r3,r4,r5;
    double xm,ym,NR,a,b;
    double a0,a1;
    double x1[c],y1[c]; 
    int i,N;

   N = 0;
    while (fscanf(fil,"%lf  %lf", &a, &b) != EOF)
    {
        N ++;
        x1[N-1] = a;
        y1[N-1] = b;
        x[N-1] = log(x1[N-1]);
        y[N-1] = log(y1[N-1]);
        


    }
    
    r1 = 0.;
    r2 = 0.;
    r3 = 0.;
    r4 = 0.;
    xm = 0.;
    ym = 0.;
    for (i = 1; i <= N; i++)
    {
        xm += x[i]/NR;
        ym += y[i]/NR;
        r1 += x[i];
        r2 += y[i];
        r3 += x[i]*y[i];
        r4 += x[i]*x[i];

    }

    a1 = (NR*r3-r1*r2)/(NR*r4-r1*r1);
    a0 = ym - a1*xm;


    r1 = x[1];
    r2 = x[N-1];
   

    for (r3 = r1; r3 <= r2; r3+=0.1)
    {
        fprintf(fil1,"%10.5f %10.5f\n",r3,(exp(a0)*pow(r3,a1)));
        printf("%f\n",exp(a0)*pow(r3,a1));
    }
    


    return 0;
}
