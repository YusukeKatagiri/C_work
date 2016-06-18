/*斜方投射の軌跡をgnuplotで描写*/
#include<stdio.h>
#include<math.h>
#define g 9.80665

int main(){
	
	double DetermineX(double v0, double rad, int i);
	double DetermineY(double v0, double rad, int i);
	
	double x,y,v0,deg,rad;
	int t,i;
	
	printf("初速度v0[m/s], 角度Θ[deg], 経過時間t[sec]を入力。\n");
	printf("v0=");
	scanf("%lf", &v0);
	
	printf("deg=");
	scanf("%lf", &deg);
	rad=deg*(M_PI/180.);
	
	printf("t=");
	scanf("%d", &t);
	
	FILE *data,*gp;
	char *datafile;
	
	datafile="trajec.txt"; /*ファイル名指定*/
	data = fopen(datafile,"w"); /*データファイルのopen*/
	
/*--関数による軌道計算--*/
	for (i=0;i<=t;i++){
		x=DetermineX(v0,rad,i);/*x-coordinate*/
		y=DetermineY(v0,rad,i);/*y-coordinate*/
		
		fprintf(data,"%f, %f\n",x,y);
	}
	
	fclose(data);
	
/*--gnuplotによる描写--*/
	gp=popen("gnuplot -persist","w");
	fprintf(gp, "set size ratio 1.0\n");
	fprintf(gp, "set border lw 2.5\n");
	fprintf(gp, "set mxtics 5\n");
	fprintf(gp, "set mytics 5\n");
	fprintf(gp, "f(x)=a*x*x+b*x+c\n"); /*多項式近似1*/
	fprintf(gp, "fit f(x) '%s' u 1:2 via a,b,c\n",datafile);
	fprintf(gp, "g(x)=d*x+e\n"); /*多項式近似2*/
	fprintf(gp, "fit g(x) '%s' u 1:2 via d,e\n",datafile);
	fprintf(gp, "plot '%s' w l lw 3 lt 1 lc rgb 'navy',f(x) w p ps 1 pt 1 lc rgb 'red',g(x) w p ps 1 pt 1 lc rgb 'green'\n",datafile); /*データプロット*/
	 
	pclose(gp);
	
	return 0;
}

/*--関数の中身--*/
double DetermineX(double v0,double rad,int i){
	double x;
	
	x=v0*cos(rad)*i;
	
	return x;
}

double DetermineY(double v0,double rad,int i){
	double y;
	
	y=v0*sin(rad)*i-(1./2.)*g*i*i;
	
	return y;
}






