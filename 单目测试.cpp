#include<stdio.h>
int main() 
{
	int a=0,b=0,c=0;
	printf("请输入a与b的值",&a,&b);
	scanf("%d %d",&a,&b); 
	c=a*-b;
	printf("c=%d",c);
	return 0;
		}
