#include<stdio.h>
int main()
{
	int x=0,num,y=2,z=0;
	printf("请输入你需要的素数个数:");
	scanf("%d",&num);
	while(x<num)
	{
		for(int i=2;i<y;i++)
		{
			if(y%i==0)
			{
				z=1;
				break;
			}
			else
			{
				z=0;
			}
		}
		if(z==0)
		{
			printf("%d\n",y);
			x++;
		}
		y++;
	}
	return 0;
}