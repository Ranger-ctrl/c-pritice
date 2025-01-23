#include<stdio.h>
int getsum(int n);
int main()
{
	int n,sum;
	scanf("%d",&n);
	sum=getsum(n);
	printf("sum=%d",sum);
	return 0;
}
int getsum(int n)
{
	int sum;
	for(int i=1;i<=n;i++){
		sum+=i;
	}
	return sum;
}