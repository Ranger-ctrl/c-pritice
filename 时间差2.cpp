#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("请输入两个时间，如10 40 为10时40分,较大时间在后\n");
	scanf("%d %d\n%d %d",&a,&b,&c,&d);
	int hour=c-a,min=d-b;
	if(min<0){
		min=min+60;
		--hour;
	}
	printf("时间差为%d时%d分",hour,min);
	return 0;
}