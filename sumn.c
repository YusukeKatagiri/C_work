#include<stdio.h>
#include<math.h>

int main(void){
	double n,i,sum1,sum2,factorial;
	
	printf("n=");
	scanf("%lf",&n);
	
	factorial = 1;
	
	for (i=1; i<=n; i++){
		sum1 += i;
		sum2 += pow(i, 3./2.);
		factorial *= i;
	}
	
	printf("%f %f %f\n", sum1,sum2,factorial);
	
	return 0;
}
