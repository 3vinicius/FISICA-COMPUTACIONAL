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
    fil1 = fopen("osciladorharmonico.dat","w");

    int c10,i,n0;
    double r1,r2,r3,r4;
    double x,x0,vx,vx0,kk,m1,mf;
    double t,tm,dt;
    double fx,ax0,ax;


    m1=1.;
    c10=0.;
    tm=20.;
    dt=0.001;
    r2=0.1/dt;
    x0=1.;
    vx0=0.;
    kk=1.;



    for (t = dt; t <= tm; t+=dt)
    {
        mf=-kk*x0;
        ax0=mf/m1;
        x=x0+vx0*dt+0.5*ax0*(dt*dt);
        mf=-kk*x;
        ax=mf/m1;
        vx=vx0+0.5*dt*(ax+ax0);
        x0=x;
        vx0=vx;
        r3++;
        if (r3>r2)
        {
            fprintf(fil1,"%20.8g  %20.8g %20.8g\n",t,x,vx);
            r3=0;
        }
        

    }
    













    return 0;
}
