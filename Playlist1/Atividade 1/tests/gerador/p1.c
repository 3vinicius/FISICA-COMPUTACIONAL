#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define RAN() ((double)rand()/(double)(RAND_MAX))
int main(){
    FILE *fil;

    double y,t,dt,C,a,z;

    char filename[100]="xesp2.dat";


    fil= fopen(filename, "w");

    C = 1.;
    a= 0.1;
    dt = 0.1;
    z=1;

    for (t=0 ; t<=20 ; t=t+dt){
        z++;
        y = log(t);

        fprintf(fil, "%13.8f %13.8f\n", t, y);

    }
    return 0;


}