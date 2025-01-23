#include<stdio.h>
int main()
{
	long int x,n=0;
	scanf("%d",&x);
	if(x<0)
	{
		x=-x;
	}
	do
	{
		n++;
		x/=10;
	}while(x>0);
	printf("%d",n);
	return 0;
}