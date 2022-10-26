#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define PI M_PI
#define NMAX 13000005
#define RAN() ((double)rand()/(double)(RAND_MAX))
double ww[NMAX];

int main(int argc, char const *argv[])
{
    FILE *fil1;
    fil1 = fopen("precorandom.dat","w");


    int i,NN,c100;
    double r1,r2,r3,r4,r5,r6;
    double nm,n2m,m2,x0,x1;
    double t,dt,r7,r8,tr,AA,BB;
    NN = 3000000;


    nm=n2m=r6=0.;
    for ( i = 1; i <= NN; i++)
    {
        r1 = RAN();
        r2 = RAN();
        r3=sqrt(-2.*log(r1));
        r4=cos(2.*PI*r2);
        r5 = r3*r4;
        ww[i]=r5;
        r6++;
        nm+=ww[i];
        n2m=n2m+ww[i]*ww[i];
    }
    
    nm = nm/r6;
    n2m=n2m/r6;
    m2=n2m-nm*nm;
    m2=sqrt(m2);




    for ( i = 1; i <= NN; i++)
    {
        ww[i]=(ww[i]-nm)/m2;
    }
    
    dt = 1./200.;
    x0 = 10000.;
    i=0;
    AA=0.001;
    BB=0.001;
    tr=sqrt(dt);
    for ( t = dt; t <= 100; t+=dt)
    {
        i++;
        x1=x0+AA*x0*dt+BB*x0*ww[i]*tr;
        x0=x1;
        c100 ++;


        if (c100>199)
        {
            fprintf(fil1,"%20.8f   %20.8f\n",t,x0);
            c100 = 0.;
        }
        
    }
    






    return 0;
}
