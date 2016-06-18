#include <stdio.h>

double f(double x, double y)
{
    return(y-12*x+3);
}


int main(void)
{
    double x0,y0,xn,h,k1,k2,k3,k4;
    double y[100];
	int i,n;

    

    printf("初期条件のx0の値を入力してください:"); scanf("%lf",&x0);

    printf("そのときのy(x0)の値を入力してください:"); scanf("%lf",&y0);

    printf("求めたい値y(xn)におけるxnの値を入力してください:"); scanf("%lf",&xn);

    printf("ステップ数を入力してください:"); scanf("%d",&n);

    

    h=(xn-x0)/n;

       printf("i       x            y\n");

    

    for (i=0,y[0]=y0; i<=n; i++) {
        k1=h*f(x0+i*h, y[i]);
        k2=h*f(x0+i*h+h/2, y[i]+k1/2);
        k3=h*f(x0+i*h+h/2, y[i]+k2/2);
        k4=h*f(x0+i*h+h, y[i]+k3);

        y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;

        

        printf("%d    %.6f    %.6f \n", i,x0+i*h,y[i]);

    }    

    

    return(0);

}
    