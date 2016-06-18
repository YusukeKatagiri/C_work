/*Two-body problem*/
/*2体問題をルンゲクッタ法を用いて解く*/

#include<stdio.h>
#include<math.h>
#define G 6.674*0.00000000001
#define m1 1
#define m2 0.8


double f1(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2);
double f2(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2);
double f3(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2);
double f4(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2);
double f5(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2);
double f6(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2);
double f7(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2);
double f8(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2);


int main()
{
	double t,x1,x2,y1,y2,vx1,vx2,vy1,vy2,dt,tmax;
	double k1[8],k2[8],k3[8],k4[8];
	
	x1=0.5;
	y1=0.5;
	vx1=0.3;
	vy1=0;
	
	x2=-0.5;
	y2=-0.5;
	vx2=-0.3;
	vy2=0;/*初期値*/
	dt=0.01; /*刻み値*/
	tmax=10.0; /*繰り返し最大数*/
	
	FILE *data, *gp;
	char *datafile;
	
/*--ファイルの指定--*/
	datafile="plotdata.csv";
	data=fopen(datafile,"w");
	
/*--Runge-Kutta法--*/
	for(t=0;t<tmax;t+=dt){
		k1[0]=dt*f1(t,x1,y1,vx1,vy1,x2,y2,vx2,vy2);
		k1[1]=dt*f2(t,x1,y1,vx1,vy1,x2,y2,vx2,vy2);
		k1[2]=dt*f3(t,x1,y1,vx1,vy1,x2,y2,vx2,vy2);
		k1[3]=dt*f4(t,x1,y1,vx1,vy1,x2,y2,vx2,vy2);
		k1[4]=dt*f5(t,x1,y1,vx1,vy1,x2,y2,vx2,vy2);
		k1[5]=dt*f6(t,x1,y1,vx1,vy1,x2,y2,vx2,vy2);
		k1[6]=dt*f7(t,x1,y1,vx1,vy1,x2,y2,vx2,vy2);
		k1[7]=dt*f8(t,x1,y1,vx1,vy1,x2,y2,vx2,vy2);
		
		k2[0]=dt*f1(t+dt/2.0,x1+k1[0]/2.0,y1+k1[1]/2.0,vx1+k1[2]/2.0,vy1+k1[3]/2.0,x2+k1[4]/2.0,y2+k1[5]/2.0,vx2+k1[6]/2.0,vy2+k1[7]/2.0);
		k2[1]=dt*f2(t+dt/2.0,x1+k1[0]/2.0,y1+k1[1]/2.0,vx1+k1[2]/2.0,vy1+k1[3]/2.0,x2+k1[4]/2.0,y2+k1[5]/2.0,vx2+k1[6]/2.0,vy2+k1[7]/2.0);
		k2[2]=dt*f3(t+dt/2.0,x1+k1[0]/2.0,y1+k1[1]/2.0,vx1+k1[2]/2.0,vy1+k1[3]/2.0,x2+k1[4]/2.0,y2+k1[5]/2.0,vx2+k1[6]/2.0,vy2+k1[7]/2.0);
		k2[3]=dt*f4(t+dt/2.0,x1+k1[0]/2.0,y1+k1[1]/2.0,vx1+k1[2]/2.0,vy1+k1[3]/2.0,x2+k1[4]/2.0,y2+k1[5]/2.0,vx2+k1[6]/2.0,vy2+k1[7]/2.0);
		k2[4]=dt*f5(t+dt/2.0,x1+k1[0]/2.0,y1+k1[1]/2.0,vx1+k1[2]/2.0,vy1+k1[3]/2.0,x2+k1[4]/2.0,y2+k1[5]/2.0,vx2+k1[6]/2.0,vy2+k1[7]/2.0);
		k2[5]=dt*f6(t+dt/2.0,x1+k1[0]/2.0,y1+k1[1]/2.0,vx1+k1[2]/2.0,vy1+k1[3]/2.0,x2+k1[4]/2.0,y2+k1[5]/2.0,vx2+k1[6]/2.0,vy2+k1[7]/2.0);
		k2[6]=dt*f7(t+dt/2.0,x1+k1[0]/2.0,y1+k1[1]/2.0,vx1+k1[2]/2.0,vy1+k1[3]/2.0,x2+k1[4]/2.0,y2+k1[5]/2.0,vx2+k1[6]/2.0,vy2+k1[7]/2.0);
		k2[7]=dt*f8(t+dt/2.0,x1+k1[0]/2.0,y1+k1[1]/2.0,vx1+k1[2]/2.0,vy1+k1[3]/2.0,x2+k1[4]/2.0,y2+k1[5]/2.0,vx2+k1[6]/2.0,vy2+k1[7]/2.0);
		
		k3[0]=dt*f1(t+dt/2.0,x1+k2[0]/2.0,y1+k2[1]/2.0,vx1+k2[2]/2.0,vy1+k2[3]/2.0,x2+k2[4]/2.0,y2+k2[5]/2.0,vx2+k2[6]/2.0,vy2+k2[7]/2.0);
		k3[1]=dt*f2(t+dt/2.0,x1+k2[0]/2.0,y1+k2[1]/2.0,vx1+k2[2]/2.0,vy1+k2[3]/2.0,x2+k2[4]/2.0,y2+k2[5]/2.0,vx2+k2[6]/2.0,vy2+k2[7]/2.0);
		k3[2]=dt*f3(t+dt/2.0,x1+k2[0]/2.0,y1+k2[1]/2.0,vx1+k2[2]/2.0,vy1+k2[3]/2.0,x2+k2[4]/2.0,y2+k2[5]/2.0,vx2+k2[6]/2.0,vy2+k2[7]/2.0);
		k3[3]=dt*f4(t+dt/2.0,x1+k2[0]/2.0,y1+k2[1]/2.0,vx1+k2[2]/2.0,vy1+k2[3]/2.0,x2+k2[4]/2.0,y2+k2[5]/2.0,vx2+k2[6]/2.0,vy2+k2[7]/2.0);
		k3[4]=dt*f5(t+dt/2.0,x1+k2[0]/2.0,y1+k2[1]/2.0,vx1+k2[2]/2.0,vy1+k2[3]/2.0,x2+k2[4]/2.0,y2+k2[5]/2.0,vx2+k2[6]/2.0,vy2+k2[7]/2.0);
		k3[5]=dt*f6(t+dt/2.0,x1+k2[0]/2.0,y1+k2[1]/2.0,vx1+k2[2]/2.0,vy1+k2[3]/2.0,x2+k2[4]/2.0,y2+k2[5]/2.0,vx2+k2[6]/2.0,vy2+k2[7]/2.0);
		k3[6]=dt*f7(t+dt/2.0,x1+k2[0]/2.0,y1+k2[1]/2.0,vx1+k2[2]/2.0,vy1+k2[3]/2.0,x2+k2[4]/2.0,y2+k2[5]/2.0,vx2+k2[6]/2.0,vy2+k2[7]/2.0);
		k3[7]=dt*f8(t+dt/2.0,x1+k2[0]/2.0,y1+k2[1]/2.0,vx1+k2[2]/2.0,vy1+k2[3]/2.0,x2+k2[4]/2.0,y2+k2[5]/2.0,vx2+k2[6]/2.0,vy2+k2[7]/2.0);
		
		k4[0]=dt*f1(t+dt,x1+k3[0],y1+k3[1],vx1+k3[2],vy1+k3[3],x2+k3[4],y2+k3[5],vx2+k3[6],vy2+k3[7]);
		k4[1]=dt*f2(t+dt,x1+k3[0],y1+k3[1],vx1+k3[2],vy1+k3[3],x2+k3[4],y2+k3[5],vx2+k3[6],vy2+k3[7]);
		k4[2]=dt*f3(t+dt,x1+k3[0],y1+k3[1],vx1+k3[2],vy1+k3[3],x2+k3[4],y2+k3[5],vx2+k3[6],vy2+k3[7]);
		k4[3]=dt*f4(t+dt,x1+k3[0],y1+k3[1],vx1+k3[2],vy1+k3[3],x2+k3[4],y2+k3[5],vx2+k3[6],vy2+k3[7]);
		k4[4]=dt*f5(t+dt,x1+k3[0],y1+k3[1],vx1+k3[2],vy1+k3[3],x2+k3[4],y2+k3[5],vx2+k3[6],vy2+k3[7]);
		k4[5]=dt*f6(t+dt,x1+k3[0],y1+k3[1],vx1+k3[2],vy1+k3[3],x2+k3[4],y2+k3[5],vx2+k3[6],vy2+k3[7]);
		k4[6]=dt*f7(t+dt,x1+k3[0],y1+k3[1],vx1+k3[2],vy1+k3[3],x2+k3[4],y2+k3[5],vx2+k3[6],vy2+k3[7]);
		k4[7]=dt*f8(t+dt,x1+k3[0],y1+k3[1],vx1+k3[2],vy1+k3[3],x2+k3[4],y2+k3[5],vx2+k3[6],vy2+k3[7]);
		
		x1=x1+(k1[0]+2.0*k2[0]+2.0*k3[0]+k4[0])/6.0;
		y1=y1+(k1[1]+2.0*k2[1]+2.0*k3[1]+k4[1])/6.0;
		vx1=vx1+(k1[2]+2.0*k2[2]+2.0*k3[2]+k4[2])/6.0;
		vy1=vy1+(k1[3]+2.0*k2[3]+2.0*k3[3]+k4[3])/6.0;
		x2=x2+(k1[4]+2.0*k2[4]+2.0*k3[4]+k4[4])/6.0;
		y2=y2+(k1[5]+2.0*k2[5]+2.0*k3[5]+k4[5])/6.0;
		vx2=vx2+(k1[6]+2.0*k2[6]+2.0*k3[6]+k4[6])/6.0;
		vy2=vy2+(k1[7]+2.0*k2[7]+2.0*k3[7]+k4[7])/6.0;
		
		fprintf(data,"%f, %f, %f, %f, %f, %f, %f, %f, %f\n",t,x1,y1,vx1,vy1,x2,y2,vx2,vy2);
	}
	
	fclose(data);
	
//--gnuplotによるグラフ作成--//
	gp=popen("gnuplot -persist","w");
	fprintf(gp, "set parametric \n");
	fprintf(gp, "set size ratio 1.0\n");
	fprintf(gp, "set border lw 2.5\n");
	fprintf(gp, "set mxtics 5\n");
	fprintf(gp, "set mytics 5\n");
	//fprintf(gp, "set mztics 5\n");
	//fprintf(gp, "splot '%s' u 2:3:4 w l lw 1.5 lt 1 lc rgb 'navy'\n",datafile);
	fprintf(gp, "plot '%s' u 2:3 w l lw 1.5 lt 1 lc rgb 'navy','%s' u 6:7 w l lw 1.5 lt 1 lc rgb 'red'\n",datafile,datafile); //ターゲット物体の軌道描写
	//fprintf(gp, "set label 1 point pt 7 ps 2 lc rgb 'red' at 0,0\n"); //原点の物体の描写
	//fprintf(gp, "replot\n");
	pclose(gp);
	
	return 0;
}

/*--関数の定義--*/
double f1(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2)
{
	double r;
	
	r=vx1;
	
	return r;
}

double f2(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2)
{
	double r;
	
	r=vy1;
	
	return r;
}

double f3(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2)
{
	double r,a;
	
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	r=(-m2)*(x1-x2)/(a*a*a);
	
	return r;
}

double f4(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2)
{
	double r,a;
	
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	r=(-m2)*(y1-y2)/(a*a*a);
	
	return r;
}	

double f5(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2)
{
	double r;
	
	r=vx2;
	
	return r;
}

double f6(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2)
{
	double r;
	
	r=vy2;
	
	return r;
}

double f7(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2)
{
	double r,a;
	
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	r=(-m1)*(x2-x1)/(a*a*a);
	
	return r;
}

double f8(double t,double x1,double y1,double vx1,double vy1,double x2,double y2,double vx2,double vy2)
{
	double r,a;
	
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	r=(-m1)*(y2-y1)/(a*a*a);
	
	return r;
}	