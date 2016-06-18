#include <stdio.h>

int main(void)
{
int i, j;
int num;
	
printf("ピラミッドは何段ですか？:");
	scanf("%d", &num);
	
			/*while文で作成*/
	i=0;
	j=0;
while(i<num){
	j=0;
		while(j<i){
		printf(" ");
		j++;
}
		j=0;
		while(j<(2*num)-(2*i+1)){
				printf("*");
				j++;
}
		while(j<i){
				printf(" ");
				j++;
}
	printf("\n");
	i++;
}
	
	
	
		/*for文で作成*/
	for(i=0;i<num;i++){

for(j=0;j<i;j++){
printf(" ");
}
for(j=0;j<(2*num)-(2*i+1);j++){
printf("*");
}
for(j=0;j<i;j++){
printf(" ");
}
printf("\n");
}


return(0);
}
