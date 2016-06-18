#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main()
{
	double x,y,vx,vy,t,dt,tmax,r,r3;
        double k0[4],k1[4],k2[4],k3[4];
        double x1,y1,vx1,vy1,x2,y2,vx2,vy2;
        double x3,y3,vx3,vy3,x4,y4,vx4,vy4;
        
	x=1;
	y=0;
	vx=0;
	vy=1;/*初期値*/
	dt=0.01; /*刻み値*/
	tmax=500.0; /*繰り返し最大数*/

	FILE *data, *gp;
	char *datafile;
	
/*--ファイルの指定--*/
	datafile="plotdata.csv";
	data=fopen(datafile,"w");

	for(t=0;t<tmax;t+=dt) {
	        r =sqrt(x*x+y*y);
                r3=r*r*r;
                k0[0]=dt*vx;
                k0[1]=dt*vy;
                k0[2]=dt*(-x/r3);
                k0[3]=dt*(-y/r3);
                x1 = x+k0[0]/2.0;
                y1 = y+k0[1]/2.0;
                vx1= vx+k0[2]/2.0;
                vy1= vy+k0[3]/2.0;
                r = sqrt(x1*x1+y1*y1);
                r3= r*r*r;
		k1[0]=dt*vx1;
		k1[1]=dt*vy1;
		k1[2]=dt*(-x1/r3);
		k1[3]=dt*(-y1/r3);
		x2 = x+k1[0]/2.0;
		y2 = y+k1[1]/2.0;
		vx2= vx+k1[2]/2.0;
		vy2= vy+k1[3]/2.0;
		r = sqrt(x2*x2+y2*y2);
                r3= r*r*r;
		k2[0]=dt*vx2;
		k2[1]=dt*vy2;
		k2[2]=dt*(-x2/r3);
		k2[3]=dt*(-y2/r3);
		x3 =x+k2[0];
		y3 =y+k2[1];
		vx3=vx+k2[2];
		vy3=vy+k2[3];
		r = sqrt(x3*x3+y3*y3);
                r3= r*r*r;
		k3[0]=dt*vx3;
		k3[1]=dt*vy3;
		k3[2]=dt*(-x3/r3);
		k3[3]=dt*(-y3/r3);
		x =x +(k0[0]+2.0*k1[0]+2.0*k2[0]+k3[0])/6.0;
                y =y +(k0[1]+2.0*k1[1]+2.0*k2[1]+k3[1])/6.0;
		vx=vx+(k0[2]+2.0*k1[2]+2.0*k2[2]+k3[2])/6.0;
		vy=vy+(k0[3]+2.0*k1[3]+2.0*k2[3]+k3[3])/6.0;
                fprintf(data,"%f, %f, %f, %f\n" ,x,y,vx,vy);
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
	fprintf(gp, "plot '%s' u 3:4 w l lw 1.5 lt 1 lc rgb 'navy'\n",datafile); //ターゲット物体の軌道描写
	fprintf(gp, "set label 1 point pt 7 ps 2 lc rgb 'red' at 0,0\n"); //原点の物体の描写
	fprintf(gp, "replot\n");
	pclose(gp);
	
	return 0;
}
