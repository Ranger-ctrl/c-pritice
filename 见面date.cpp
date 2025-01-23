#include<stdio.h>
int main()
{
	int date=0;
	printf("今天是几号啦？\n");
	scanf("%d",&date);
	const int num=32; 
	int i=num-date;
	printf("还有%d天就能见到宝宝啦！",i);
	return 0;
}
