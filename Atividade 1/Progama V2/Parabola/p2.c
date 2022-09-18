#include <stdio.h>;
#include <math.h>;

int main(){
    FILE *fil;
    double a, x, b, c, y, dx;

    char filename[100] = "parabola.dat";

    fil = fopen(filename, "w");

    a = 1.;
    b=0.1;
    c = -1;
    dx = 0.2;

    for (x = -2; x<=2.0; x=x+dx){
        y = (a*(x*x))+(b*x)+c;

        fprintf(fil, "%13.8f %13.8f\n", x, y);
    }

    return 0;

}