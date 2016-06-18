/*Two-body problem*/
/*2体問題をルンゲクッタ法を用いて解く*/
//物体1が原点に固定されている場合の2体問題

#include<stdio.h>
#include<math.h>
#define G 6.674*0.00000000001
#define M 2


double f1(double t,double x,double y,double vx,double vy);
double f2(double t,double x,double y,double vx,double vy);
double f3(double t,double x,double y,double vx,double vy);
double f4(double t,double x,double y,double vx,double vy);


int main()
{
	double t,x,y,vx,vy,dt,tmax;
	double k1[4],k2[4],k3[4],k4[4];
	
	x=1;
	y=0;
	vx=0;
	vy=0.7;/*初期値*/
	dt=0.01; /*刻み値*/
	tmax=100.0; /*繰り返し最大数*/
	
	FILE *data, *gp;
	char *datafile;
	
/*--ファイルの指定--*/
	datafile="plotdata.csv";
	data=fopen(datafile,"w");
	
/*--Runge-Kutta法--*/
	for(t=0;t<tmax;t+=dt){
		k1[0]=dt*f1(t,x,y,vx,vy);
		k1[1]=dt*f2(t,x,y,vx,vy);
		k1[2]=dt*f3(t,x,y,vx,vy);
		k1[3]=dt*f4(t,x,y,vx,vy);
		
		
		k2[0]=dt*f1(t+dt/2.0,x+k1[0]/2.0,y+k1[1]/2.0,vx+k1[2]/2.0,vy+k1[3]/2.0);
		k2[1]=dt*f2(t+dt/2.0,x+k1[0]/2.0,y+k1[1]/2.0,vx+k1[2]/2.0,vy+k1[3]/2.0);
		k2[2]=dt*f3(t+dt/2.0,x+k1[0]/2.0,y+k1[1]/2.0,vx+k1[2]/2.0,vy+k1[3]/2.0);
		k2[3]=dt*f4(t+dt/2.0,x+k1[0]/2.0,y+k1[1]/2.0,vx+k1[2]/2.0,vy+k1[3]/2.0);
		
		
		k3[0]=dt*f1(t+dt/2.0,x+k2[0]/2.0,y+k2[1]/2.0,vx+k2[2]/2.0,vy+k2[3]/2.0);
		k3[1]=dt*f2(t+dt/2.0,x+k2[0]/2.0,y+k2[1]/2.0,vx+k2[2]/2.0,vy+k2[3]/2.0);
		k3[2]=dt*f3(t+dt/2.0,x+k2[0]/2.0,y+k2[1]/2.0,vx+k2[2]/2.0,vy+k2[3]/2.0);
		k3[3]=dt*f4(t+dt/2.0,x+k2[0]/2.0,y+k2[1]/2.0,vx+k2[2]/2.0,vy+k2[3]/2.0);
		
		k4[0]=dt*f1(t+dt,x+k3[0],y+k3[1],vx+k3[2],vy+k3[3]);
		k4[1]=dt*f2(t+dt,x+k3[0],y+k3[1],vx+k3[2],vy+k3[3]);
		k4[2]=dt*f3(t+dt,x+k3[0],y+k3[1],vx+k3[2],vy+k3[3]);
		k4[3]=dt*f4(t+dt,x+k3[0],y+k3[1],vx+k3[2],vy+k3[3]);
		
		x=x+(k1[0]+2.0*k2[0]+2.0*k3[0]+k4[0])/6.0;
		y=y+(k1[1]+2.0*k2[1]+2.0*k3[1]+k4[1])/6.0;
		vx=vx+(k1[2]+2.0*k2[2]+2.0*k3[2]+k4[2])/6.0;
		vy=vy+(k1[3]+2.0*k2[3]+2.0*k3[3]+k4[3])/6.0;
		
		fprintf(data,"%f, %f, %f, %f\n",x,y,vx,vy);
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
	fprintf(gp, "plot '%s' u 1:2 w l lw 1.5 lt 1 lc rgb 'navy'\n",datafile); //ターゲット物体の軌道描写
	fprintf(gp, "set label 1 point pt 7 ps 2 lc rgb 'red' at 0,0\n"); //原点の物体の描写
	fprintf(gp, "replot\n");
	pclose(gp);
	
	return 0;
}

/*--関数の定義--*/
double f1(double t,double x,double y,double vx,double vy)
{
	double r;
	
	r=vx;
	
	return r;
}

double f2(double t,double x,double y,double vx,double vy)
{
	double r;
	
	r=vy;
	
	return r;
}

double f3(double t,double x,double y,double vx,double vy)
{
	double r,r3,s;
	
	s=sqrt(x*x+y*y);
	r3=s*s*s;
	r=(-M)*x/r3;
	
	return r;
}

double f4(double t,double x,double y,double vx,double vy)
{
	double r,r3,s;
	
	s=sqrt(x*x+y*y);
	r3=s*s*s;
	r=(-M)*y/r3;
	
	
	return r;
}	