#include<stdio.h>
#define Pi 3.14159265
int main()
{
	printf("请分别输入长、宽，半径和边长\n");
	double a,b,c,d,e,f,g;
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	e=a*b;
	f=Pi*c*c;
	g=d*d;
	printf("长方形的面积为 %lf\n",e);
	printf("圆形的面积为 %lf\n",f);
	printf("正方形的面积为 %lf\n",g);
	return 0;
}
