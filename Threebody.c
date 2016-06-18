#include <stdio.h>
#include <math.h>

#define m1 0.8          //m1+m2=1.0は厳守
#define m2 0.2

double f1(double t,double x,double y,double vx,double vy);
double f2(double t,double x,double y,double vx,double vy);
double f3(double t,double x,double y,double vx,double vy);
double f4(double t,double x,double y,double vx,double vy);
                
int main(void)
{
        double t,x,y,vx,vy,dt,tmax;
        double k0[4],k1[4],k2[4],k3[4];

        dt=0.01;                        //刻み幅
        tmax=100.0;                     //最大時間

        x=0.5;                          //ここから初期条件
        y=0.0;
        vx=0.0;
        vy=1.0;
        
	FILE *data, *gp;
	char *datafile;
	
/*--ファイルの指定--*/
	datafile="plotdata.csv";
	data=fopen(datafile,"w");

//ルンゲクッタの公式を用いて解く
        for(t=0.0;t<tmax;t+=dt) {
                k0[0]=dt*f1(t,x,y,vx,vy);
                k0[1]=dt*f2(t,x,y,vx,vy);
                k0[2]=dt*f3(t,x,y,vx,vy);
                k0[3]=dt*f4(t,x,y,vx,vy);

                k1[0]=dt*f1(t+dt/2.0,x+k0[0]/2.0,y+k0[1]/2.0,vx+k0[2]/2.0,vy+k0[3]/2.0);
                k1[1]=dt*f2(t+dt/2.0,x+k0[0]/2.0,y+k0[1]/2.0,vx+k0[2]/2.0,vy+k0[3]/2.0);
                k1[2]=dt*f3(t+dt/2.0,x+k0[0]/2.0,y+k0[1]/2.0,vx+k0[2]/2.0,vy+k0[3]/2.0);
                k1[3]=dt*f4(t+dt/2.0,x+k0[0]/2.0,y+k0[1]/2.0,vx+k0[2]/2.0,vy+k0[3]/2.0);

                k2[0]=dt*f1(t+dt/2.0,x+k1[0]/2.0,y+k1[1]/2.0,vx+k1[2]/2.0,vy+k1[3]/2.0);
                k2[1]=dt*f2(t+dt/2.0,x+k1[0]/2.0,y+k1[1]/2.0,vx+k1[2]/2.0,vy+k1[3]/2.0);
                k2[2]=dt*f3(t+dt/2.0,x+k1[0]/2.0,y+k1[1]/2.0,vx+k1[2]/2.0,vy+k1[3]/2.0);
                k2[3]=dt*f4(t+dt/2.0,x+k1[0]/2.0,y+k1[1]/2.0,vx+k1[2]/2.0,vy+k1[3]/2.0);

                k3[0]=dt*f1(t+dt,x+k2[0],y+k2[1],vx+k2[2],vy+k2[3]);
                k3[1]=dt*f2(t+dt,x+k2[0],y+k2[1],vx+k2[2],vy+k2[3]);
                k3[2]=dt*f3(t+dt,x+k2[0],y+k2[1],vx+k2[2],vy+k2[3]);
                k3[3]=dt*f4(t+dt,x+k2[0],y+k2[1],vx+k2[2],vy+k2[3]);

                x=x+(k0[0]+2.0*k1[0]+2.0*k2[0]+k3[0])/6.0;
                y=y+(k0[1]+2.0*k1[1]+2.0*k2[1]+k3[1])/6.0;
                vx=vx+(k0[2]+2.0*k1[2]+2.0*k2[2]+k3[2])/6.0;
                vy=vy+(k0[3]+2.0*k1[3]+2.0*k2[3]+k3[3])/6.0;

                fprintf(data,"%f %f %f %f\n",x,y,vx,vy);

        }

        fclose(data);

//--gnuplotによるグラフ作成--//
	gp=popen("gnuplot -persist","w");
	//fprintf(gp, "set size ratio 1.0\n");
	fprintf(gp, "set border lw 2.5\n");
	fprintf(gp, "set mxtics 5\n");
	fprintf(gp, "set mytics 5\n");
	//fprintf(gp, "set mztics 5\n");
	//fprintf(gp, "splot '%s' u 2:3:4 w l lw 1.5 lt 1 lc rgb 'navy'\n",datafile);
	fprintf(gp, "plot '%s' u 1:2 w l lw 1.5 lt 1 lc rgb 'navy',#'%s' u 2:4 w l lw 1.5 lt 1 lc rgb 'red'\n",datafile,datafile);
	
	pclose(gp);

        return 0;
}

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
        double r;

        r=2*vy+x+(-m1*(x-m2)/((pow((x-m2)*(x-m2)+y*y,1.5)))-m2*(x+m1)/(pow((x+m1)*(x+m1)+y*y,1.5)));

        return r;
}

double f4(double t,double x,double y,double vx,double vy)
{
        double r;

        r=-2*vx+y+(-m1*y/(pow((x-m2)*(x-m2)+y*y,1.5))-m2*y/(pow((x+m1)*(x+m1)+y*y,1.5)));

        return r;
}