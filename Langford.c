/*Runge-Kutta_method*/
/*ラングフォード方程式をルンゲクッタ法を用いて解く*/
/*
  dx/dt=(z-0.7)x-3.5y
  dy/dt=3.5x+(z-0.7)y
  dz/dt=a+z-z^3/3-(x^2+y^2)(1+0.25z)
*/


#include<stdio.h>
#include<math.h>

double f1(double t,double x,double y,double z);
double f2(double t,double x,double y,double z);
double f3(double t,double x,double y,double z);

int main()
{
	double t,x,y,z,dt,tmax;
	double k1[3],k2[3],k3[3],k4[3];
	
	x=y=z=1.0; /*初期値*/
	dt=0.01; /*刻み値*/
	tmax=10000.0; /*繰り返し最大数*/
	
	FILE *data, *gp;
	char *datafile;
	
/*--ファイルの指定--*/
	datafile="plotdata.csv";
	data=fopen(datafile,"w");
	
/*--Runge-Kutta法--*/
	for(t=0;t<tmax;t++){
		k1[0]=dt*f1(t,x,y,z);
		k1[1]=dt*f2(t,x,y,z);
		k1[2]=dt*f3(t,x,y,z);
		
		k2[0]=dt*f1(t+dt/2.0,x+k1[0]/2.0,y+k1[1]/2.0,z+k1[2]/2.0);
		k2[1]=dt*f2(t+dt/2.0,x+k1[0]/2.0,y+k1[1]/2.0,z+k1[2]/2.0);
		k2[2]=dt*f3(t+dt/2.0,x+k1[0]/2.0,y+k1[1]/2.0,z+k1[2]/2.0);
		
		k3[0]=dt*f1(t+dt/2.0,x+k2[0]/2.0,y+k2[1]/2.0,z+k2[2]/2.0);
		k3[1]=dt*f2(t+dt/2.0,x+k2[0]/2.0,y+k2[1]/2.0,z+k2[2]/2.0);
		k3[2]=dt*f3(t+dt/2.0,x+k2[0]/2.0,y+k2[1]/2.0,z+k2[2]/2.0);
		
		k4[0]=dt*f1(t+dt,x+k3[0],y+k3[1],z+k3[2]);
		k4[1]=dt*f2(t+dt,x+k3[0],y+k3[1],z+k3[2]);
		k4[2]=dt*f3(t+dt,x+k3[0],y+k3[1],z+k3[2]);
		
		x=x+(k1[0]+2.0*k2[0]+2.0*k3[0]+k4[0])/6.0;
		y=y+(k1[1]+2.0*k2[1]+2.0*k3[1]+k4[1])/6.0;
		z=z+(k1[2]+2.0*k2[2]+2.0*k3[2]+k4[2])/6.0;
		
		fprintf(data,"%f, %f, %f, %f\n",t,x,y,z);
	}
	
	fclose(data);
	
//--gnuplotによるグラフ作成--//
	gp=popen("gnuplot -persist","w");
	//fprintf(gp, "set size ratio 1.0\n");
	fprintf(gp, "set border lw 2.5\n");
	fprintf(gp, "set mxtics 5\n");
	fprintf(gp, "set mytics 5\n");
	fprintf(gp, "set mztics 5\n");
	fprintf(gp, "splot '%s' u 2:3:4 w l lw 1.5 lt 1 lc rgb 'navy'\n",datafile);
	
	pclose(gp);
	
	return 0;
}

/*--関数の定義--*/
double f1(double t,double x,double y, double z)
{
	double r;
	
	r=(z-0.7)*x-3.5*y;
	
	return r;
}

double f2(double t,double x,double y, double z)
{
	double r;
	
	r=3.5*x+(z-0.7)*y;
	
	return r;
}

double f3(double t,double x,double y,double z)
{
	double r,a;
	
	a=0.6; /*この値をいろいろ変える*/
	r=a+z-z*z*z/3.0-(x*x+y*y)*(1.0+0.25*z);

	return (r);
}

	
	