#include<stdio.h>
int max(int x,int y)
{
	int a;
	if(x>y){
		a=x;
	}else{
		a=y;
	}
	return a;
}
int main()
{
	int x,y,z;
	scanf("%d %d",&x,&y);
	z=max(x,y);
	printf("%d",z);
	return 0;
	
}