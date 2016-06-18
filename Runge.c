/*Runge-Kutta_method*/
/*単振動の問題をルンゲクッタ法を用いて解く*/
#include<stdio.h>

double f1(double t,double x,double v);
double f2(double t,double x,double v);

int main()
{
	double t,x,v,dt,tmax;
	double k1[2],k2[2],k3[2],k4[2];
	
	x=1.0; /*位置の初期値_x0*/
	v=0.0; /*速度の初期値_v0*/
	dt=0.01; /*刻み値*/
	tmax=5000.0; /*繰り返し最大数*/
	
	FILE *data, *gp;
	char *datafile;
	
/*--ファイルの指定--*/
	datafile="plotdata.csv";
	data=fopen(datafile,"w");
	
/*--Runge-Kutta法--*/
	for(t=0;t<tmax;t++){
		k1[0]=dt*f1(t,x,v);
		k1[1]=dt*f2(t,x,v);
		
		k2[0]=dt*f1(t+dt/2.0,x+k1[0]/2.0,v+k1[1]/2.0);
		k2[1]=dt*f2(t+dt/2.0,x+k1[0]/2.0,v+k1[1]/2.0);
		
		k3[0]=dt*f1(t+dt/2.0,x+k2[0]/2.0,v+k2[1]/2.0);
		k3[1]=dt*f2(t+dt/2.0,x+k2[0]/2.0,v+k2[1]/2.0);
		
		k4[0]=dt*f1(t+dt,x+k3[0],v+k3[1]);
		k4[1]=dt*f2(t+dt,x+k3[0],v+k3[1]);
		
		x=x+(k1[0]+2.0*k2[0]+2.0*k3[0]+k4[0])/6.0;
		v=v+(k1[1]+2.0*k2[1]+2.0*k3[1]+k4[1])/6.0;
		
		fprintf(data,"%f, %f, %f\n",t,x,v);
	}
	
	fclose(data);
	
//--gnuplotによるグラフ作成--//
	gp=popen("gnuplot -persist","w");
	fprintf(gp, "set size ratio 1.0\n");
	fprintf(gp, "set border lw 2.5\n");
	fprintf(gp, "set mxtics 5\n");
	fprintf(gp, "set mytics 5\n");
	fprintf(gp, "plot '%s' u 1:2 w l lt 1 lc rgb 'navy',#'%s' u 2:3 w l lt 1 lc rgb 'red'\n",datafile,datafile);
	
	pclose(gp);
	
	return 0;
}

/*--関数の定義--*/
double f1(double t,double x,double v)
{
	return v;
}

double f2(double t,double x,double v)
{
	return (-x);
}

	
	