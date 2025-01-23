#include<stdio.h>
int main()
{
	int number,count,guess;
	number=6652;
	count=1;
	scanf("%d",&guess);
		do
		{	
			if(number>guess)
			{
				count++;
				printf("比这个数大\n");
				printf("请继续猜\n");
				scanf("%d",&guess);
			}
			if(number<guess)
			{	
				count++;
				printf("比这个数小\n");
				printf("请继续猜\n");
				scanf("%d",&guess);
			}
		}while(number!=guess);
	printf("你猜对了，一共猜了%d次",count);
	return 0;
}