#include<stdio.h>
int main()
{
	int h1,h2,m1,m2;
	printf("请分别输入两个时间（x小时x分），例如输入 5,30 即为5小时30分，请先输入较大的时间");
	scanf("%d,%d %d,%d",&h1,&m1,&h2,&m2);
	int num1,num2;
	num1=h1*60+m1;
	num2=h2*60+m2;
	int num3=num1-num2;
	printf("时间差为%d小时%d分",num3/60,num3%60);
	return 0;
 } 
