#include<stdio.h>
int main()
{
	int x,sum=0,cnt=0,number[100];
	double average;
	scanf("%d",&x);
	while(x!=-1){
		number[cnt]=x;
		cnt++;
		sum+=x;
		scanf("%d",&x);
	}
	if(cnt>0){
		average=sum*1.0/cnt;
		printf("%.2lf\n",average);
		for(int i=0;i<cnt;i++){
			if(number[i]>average){
				printf("%d\t",number[i]);
			}
		}
	}	
	return 0;	
}