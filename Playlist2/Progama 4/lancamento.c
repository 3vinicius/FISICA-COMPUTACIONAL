#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI M_PI

int main(int argc, char const *argv[])
{
    FILE *fil;
    fil = fopen("dados2.dat", "w");
    int i,n0;
    double r1,r2,r3,r4;
    double x,x0,y,y0,vx,vx0,vy,vy0,gg,gama;
    double v0,theta,t,tm,dt;

    tm = 20.;
    dt = 0.00005;
    theta = PI/4;
    gg = 10.;
    gama = 2.;
    v0 = 10.;
    vx0 = v0*cos(theta);
    vy0 = v0*cos(theta);
    x0 = 0.;
    y0 = 0.;

    x=y=0.;


    for (t = dt; t <= tm; t+=dt)
    {
        vx = vx0 + dt*(-gama*vx0);
        vy = vy0 + dt*(-gg-gama*vy0);
        x = x0 +dt*vx0;
        y = y0 + dt*vy0;


        x0 = x;
        y0 = y;
        vx0 = vx;
        vy0 = vy;

        if (y > 0.)
        {
            fprintf(fil, "%20.8g   %20.8g\n",x,y);
        }
        




    }
    



    return 0;
}

