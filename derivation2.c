//--二回微分を差分法で計算--//
#include<stdio.h>
#include<math.h>
#define f(x) sin(x)+cos(x) //integrant

int main(){
	double x,x1,x2,dx,f2;
	int i;
	FILE *data, *gp;
	char *data_file;
	
	printf("Δxを入力:Δx=");//刻み幅の指定
	scanf("%lf",&dx);
	
//--データファイル作成--//
	data_file="plotdata.txt";
	data = fopen(data_file,"w");//保存ファイルの指定
	
	for (i=0; i<360; i++){
		x=i*(M_PI/180);
		x1=x-dx;
		x2=x+dx;
		
		f2=(f(x2)-2*f(x)+f(x1))/(dx*dx);//差分法による二階微分
		printf("x=%f f2=%f\n",x,f2); 
		fprintf(data, "%f, %f\n", x,f2);//ファイルへの書き込み
	}
	
	fclose(data);
	
	printf("二階微分 f2=%f\n",f2);
	
//--gnuplotによるグラフ作成--//
	gp=popen("gnuplot -persist","w");
	fprintf(gp, "set size ratio 1.0\n");
	fprintf(gp, "set border lw 2.5\n");
	fprintf(gp, "set mxtics 5\n");
	fprintf(gp, "set mytics 5\n");
	fprintf(gp, "plot \"%s\" w l lt 1 lc rgb \"navy\"\n",data_file);
	 
	pclose(gp);
	
	return 0;
}//--二回微分を差分法で計算--//
#include<stdio.h>
#include<math.h>
#define f(x) sin(x)+cos(x) //integrant

int main(){
	double x,x1,x2,dx,f2;
	int i;
	FILE *data, *gp;
	char *data_file;
	
	printf("Δxを入力:Δx=");//刻み幅の指定
	scanf("%lf",&dx);
	
//--データファイル作成--//
	data_file="plotdata.txt";
	data = fopen(data_file,"w");//保存ファイルの指定
	
	for (i=0; i<360; i++){
		x=i*(M_PI/180);
		x1=x-dx;
		x2=x+dx;
		
		f2=(f(x2)-2*f(x)+f(x1))/(dx*dx);//差分法による二階微分
		printf("x=%f f2=%f\n",x,f2); 
		fprintf(data, "%f, %f\n", x,f2);//ファイルへの書き込み
	}
	
	fclose(data);
	
	printf("二階微分 f2=%f\n",f2);
	
//--gnuplotによるグラフ作成--//
	gp=popen("gnuplot -persist","w");
	fprintf(gp, "set size ratio 1.0\n");
	fprintf(gp, "set border lw 2.5\n");
	fprintf(gp, "set mxtics 5\n");
	fprintf(gp, "set mytics 5\n");
	fprintf(gp, "plot \"%s\" w l lt 1 lc rgb \"navy\"\n",data_file);
	 
	pclose(gp);
	
	return 0;
}