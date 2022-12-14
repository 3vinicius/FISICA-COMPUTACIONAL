#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define RAN()  ((double)rand()/(double)(RAND_MAX))



int main(int argc, char const *argv[])
{
    FILE *fil;
    fil = fopen("socaomatricial.dat","w");


    int k,i,j;
    double MM[10][10],b[10],erro[10];
    double x1[10],x2[10],b1[10];
    double AA[10][10],DD[10][10],IDD[10][10];

    AA[1][1]=2;
    AA[1][2]=1;
    AA[1][3]=0;
    AA[2][1]=1;
    AA[2][2]=4;
    AA[2][3]=1;
    AA[3][1]=0;
    AA[3][2]=1;
    AA[3][3]=3;




    for ( i = 1; i <= 3; i++)
    {
        for ( j = 1; j <= 3; j++)
        {
            DD[i][j]=0;
            MM[i][j]=0;
        }
        
    }
    
    DD[1][1]=AA[1][1];
    DD[2][2]=AA[2][2];
    DD[3][3]=AA[3][3];


    for ( i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 3; j++)
        {
            MM[i][j]=AA[i][j]-DD[i][j];
        }
        
    }
    

    x1[1]=x1[2]=x1[3]=0.01;
    b[1]=1;
    b[2]=b[3]=0;

    for (k = 1; k <= 20; k++)
    {
        for (i = 1; i <= 3; i++)
        {
            b1[i]=0;
            for (j = 1; j <= 3; j++)
            {
                b1[i]=b1[i]+MM[i][j]*x1[j];
            }
            
        }



        for (i = 1; i <= 3; i++)
        {
            x2[i]=b[i]-b1[i];
            IDD[i][i]=1./DD[i]
            [i];        }



        for (i = 1; i <= 3; i++)
        {
            b1[i]=0;
            for (j = 1; j <= 3; j++)
            {
                b1[i]=b1[i]+IDD[i][j]*x2[j];
            }
            x1[i]=b1[i];
        }
        
        fprintf(fil,"%20.8g  %20.8g  %20.8g\n",x1[1],x1[2],x1[3]);

        /* erro[1]=fabs(x1[1]-x0[1]);
        erro[2]=fabs(x1[2]-x0[2]);
        erro[3]=fabs(x1[3]-x0[3]);
         */
    }
    


    for (i = 1; i <= 3; i++)
    {
        b1[i]=0.;
        for (j = 1; j <= 3; j++)
        {
            b1[i]=b1[i]+AA[i][j]*x1[j];
        }
        
    }
    


        erro[1]=fabs(b1[1]-b[1]);
        erro[2]=fabs(b1[2]-b[2]);
        erro[3]=fabs(b1[3]-b[3]);


    printf("%20.8g   %20.8g   %20.8g\n",erro[1],erro[2],erro[3]);



    return 0;
}
