#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define RAN()  ((double)rand()/(double)(RAND_MAX))




int main(int argc, char const *argv[])
{
    int k,i,j,N;
    double r1,r2,r3,r4,r5,r6;
    double AA[10][10],BB[10][10],GG[10];
    double MM[10][10],DD[10],CC[10][10];


    N=2.;


    for (i=1; i<=N; i++)
    {
        for (j=1;j<=N; j++)
        {
            AA[i][j]=1.;
            BB[i][j]=1.;
        }
        
    }
    


    for (i=1; i <= N; i++)
    {
        for (j=1;j<=N; j++)
        {
            MM[i][j]=AA[i][j]-BB[i][j];
        }
        
    }
    

    for (i =1; i<=N; i++)
    {
        //printf("%20.8g    %20.8g\n",MM[i][1],MM[i][2]);
    }
    


    for (i = 1; i <=N; i++)
    {
    for ( j = 0;j <=N; j++)
    {
        AA[i][j]=1.;
        BB[i][j]=1.;
    }
    }
    
    for (i = 1; i <=N; i++){
    for (j = 1; j<=N; j++){
        CC[i][j]=0.;
    for (k = 1; k <=N; k++)
    {
        CC[i][j]=CC[i][j]+AA[i][k]*BB[k][j];
    }
    }
    }
    
    for (i = 1; i <=N; i++)
    {
        //printf("%20.8g   %20.8g\n",CC[i][1],CC[i][2]);
    }
    

    GG[1]=1.;
    GG[2]=0.;

    for (i = 1; i <=N; i++)
    {
        DD[i]=0.;
        for (k=1;k<=N; k++)
        {
            DD[i]=DD[i]+AA[i][k]*GG[k];
        }  
    }
    for (i = 1; i <=N; i++)
    {
        //printf("%20.8g\n",DD[i]);
    }
    


    r1=0.;
    for (i =1; i <=N; i++)
    {
        r1=r1+AA[i][i];
    }
    //printf("%20.8g\n",r1);



    for (i = 1; i <=N; i++){
    for (j = 1; j <= N; j++)
    {
        AA[i][j]=1.;
    }
    }
    
    for (j = 1; j <= N; j++)
    {
        r1=0.;
        for (i = 1; i <=N; i++)
        {
            r1+=pow(AA[i][j],2.);
        }
        r1 = sqrt(r1);
        for ( i = 1; i <=N; i++)
        {
            AA[i][j]=AA[i][j]/r1;
        }
        
    }
    

    for (i = 1; i <=N; i++)
    {
        printf("%20.8g   %20.8g\n",AA[i][1],AA[i][2]);
    }
    





    return 0;
}
