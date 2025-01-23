#include<stdio.h>
int main()
{
	int x,y=1;
	printf("请输入一个整数:");
	scanf("%d",&x);
	for(int i=2;i<x;i++)
	{
		if(x%i==0)
		{
			y=0;
			break;
		}
	}
	if(y==0||x==1)
	{
		printf("%d不是素数",x);
	}
	else
	{
		printf("%d是素数",x);
	}
	return 0;
}