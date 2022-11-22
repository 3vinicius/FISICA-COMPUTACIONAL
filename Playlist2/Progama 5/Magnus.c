#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI M_PI

int main(int argc, char const *argv[])
{
    double c100, c200,CA,CM,AA,BB,rho,Area,RR;
    double ww,vy0,vy,theta,g,v0,vt,x1,x0,y0,y1;
    double vx0,vx,m,k,dt,t,tm,t0;
    char filename[1000];


    FILE *fil1;
    printf("Digite Omena\n");
    scanf("%lf", &ww);

    sprintf(filename,"trajetorialW%1.2lf.dat",ww);
    fil1 = fopen(filename,"w");







    t0 = 0.;
    x0 = 0.;
    y0 = 1.5;
    dt = 0.00001;
    g = 9.8;
    tm = 1.656;
    v0 = 35.;
    theta = (10./180.)*M_PI;
    vx0 = v0*cos(theta);
    vy0 = v0*sin(theta);
    RR = 3.25/100;
    Area = M_PI*pow(RR,2);
    CA = 0.67;
    rho = 1.18;
    AA = 0.5*rho*Area*CA;
    m = 58./1000.;
    c200 = 0.01/dt;

    


    for (t = dt; t <= tm; t+=dt)
    {
        vt = sqrt(pow(vx0,2)+pow(vy0,2));
        CM = RR*ww/vt;
        
        BB = 0.5*rho*Area*CM;

        vx = vx0+dt*(-AA*vt*vx0+BB*vt*vy0) / m;
        vy = vy0+dt*(-m*g-AA*vt*vy0-BB*vt*vx0)/m;


        x1=x0+dt*vx0;
        y1=y0+dt*vy0;

        vx0 = vx;
        vy0 = vy;
        x0 = x1;
        y0 = y1;



        c100 +=1;
        if (c100>c200)
        {
            if (y0>0.) fprintf(fil1,"%13.8f  %13.8f\n",x0,y0); 
            c100=0.;
        }
        

    }
    


    return 0;
}
