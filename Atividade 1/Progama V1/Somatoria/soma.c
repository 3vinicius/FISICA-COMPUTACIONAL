#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    double i, S;

    for (i = 1; i <=4; i+=1){
        S+=i;
    }
    printf("%.2f", S);
    return 0;
}

