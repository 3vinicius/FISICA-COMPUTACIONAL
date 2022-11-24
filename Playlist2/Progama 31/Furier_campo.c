#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>





int main(int argc, char const *argv[])
{


    FILE *fil,*fil1;
    fil = fopen("saida.dat","w");
  

    int i,j,cont;
    double x,y,xt[15000],yt[15000];
    double pont;
    char filname[100];

    printf("nome do arquivo: ");
    scanf("%c",&filname);
    filname[100] = "eqonda.dat"; 
    fil1 = fopen(filname,"r");

    cont =0.;
    if(fil1 != NULL){
    while (fscanf(fil1, "%f" "%f", &x, &y) != EOF)
    {

        cont ++;
        xt[cont-1] = x;
        yt[cont-1] = y;

    }}


    pont = log((float)cont)/log(2);
    pont = (int)pont;
    


    return 0;
}
