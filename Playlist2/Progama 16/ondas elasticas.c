#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <stdio.h>







int main(int argc, char const *argv[])
{
    FILE *fil1,*fil2;
    fil1 = fopen("eqonda.dat","w");


    int N,i,j;
    double r1,r2,r3,r4,t,dt,A,ww;
    double phi0[10000],phi1[10000],phi2[10000];
    N = 200;



    for (i = 0; i <= N; i++)
    {
        phi0[i]=phi1[i]=phi2[i]=0.;
    }
    




    dt = 0.001;
    A = 0.1;
    ww = 1.;

    phi1[0]=A;
    phi0[0]=A;

    for ( t = dt; t <= 150; t+=dt)
    {
        for ( i = 1; i <= N; i++)
        {
            phi2[i]=2.*phi1[i]-phi0[i]+(dt*dt)*(phi1[i+1]-2.*phi1[i]+phi1[i-1]);
        }
        

        for ( i = 1; i <= N; i++)
        {
            phi0[i]=phi1[i];
            phi1[i]=phi2[i];
        }
        


        phi0[0]=phi1[0];
        phi1[0]=A*cos(ww*t);



        j+=1;
        if (j>10)
        {
            fprintf(fil1,"%20.8g   %20.8g \n",t,phi2[50]);

            j = 0.;
        }
        



    }
    







    return 0;
}
