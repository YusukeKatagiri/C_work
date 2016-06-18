#include <stdio.h>
#include <math.h>

double f(double x)
{
    return ( x*x*x-7*x*x+14*x-8);
}

double fd(double x)
{
    return ( 3*x*x-14*x+14);
}



double main(void)

{   int i ;
    double x,xi,dif ;
    printf("初期値を入力してください。\n");
    printf("初期値:"); scanf("%lf", &x);
    
    for(i=1;dif>0.0001&&i<51;x=xi,i++){
        xi=x-f(x)/fd(x);
        dif=fabs(xi-x);
        printf("i=%d x=%.5f xi=%.5f dif=%.5f\n",i,x,xi,dif);
    }
    putchar("\n");
    printf("収束値=%.5f",xi);
    
    return(0);
    
}

