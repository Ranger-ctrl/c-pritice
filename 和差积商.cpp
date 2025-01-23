#include<stdio.h>
int main()
{
	printf("Please enter two positive integer:\n");
	int a,b,c,d,e;
	scanf("%d %d",&a,&b);
	c=a+b;
	d=a-b;
	e=a*b;
	double f=a/b;
	printf("Sum=%d\nDifference=%d\nProduct=%d\nQuotient=%lf",c,d,e,f);
	return 0;
}