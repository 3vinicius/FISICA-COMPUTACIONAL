#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define RAN()  ((double)rand()/(double)(RAND_MAX))
int main(int argc, char const *argv[])
{
    FILE *fil;
    fil = fopen("sistema.dat","w");


    int k,i,j,n0;
    double r1,r2,r3,r4;
    double AA[10][10],b[10],erro[10];
    double x1[10],x2[10],b1[10];


    AA[1][1]=2.;
    AA[1][2]=1.;
    AA[1][3]=0.;
    AA[2][1]=1.;
    AA[2][2]=4.;
    AA[2][3]=1.;
    AA[3][1]=0.;
    AA[3][2]=1.;
    AA[3][3]=3.;


    x1[1]=x2[2]=x1[3]=0.01;
    b1[1]=1.;
    b[2]=b[3]=0.;


    for ( k = 1; k <= 20; k++)
    {
        x2[1]=(1./AA[1][1])*(b[1]-AA[1][2]*x1[2]-AA[1][3]*x1[3]);

        x2[2]=(1./AA[2][2])*(b[2]-AA[2][1]*x1[1]-AA[2][3]*x1[3]);

        x2[3]=(1./AA[3][3])*(b[3]-AA[3][1]*x1[1]-AA[3][2]*x1[2]);


        fprintf(fil,"%20.8g  %20.8g  %20.8g\n",x2[1],x2[2],x2[3]);


        


        x1[1]=x2[1];
        x1[2]=x2[2];
        x1[3]=x2[3]; 

    }
    

    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            b1[i]=b1[i]+AA[i][j]*x1[j];
        }
        
    }
    
    erro[1]=fabs(b1[1]-b[1]);
    erro[2]=fabs(b1[2]-b[2]);
    erro[3]=fabs(b1[3]-b[3]);

    printf("%20.8g  %20.8g  %20.8g\n",erro[1],erro[2],erro[3]);





    return 0;
}
