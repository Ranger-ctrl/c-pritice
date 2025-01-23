#include<stdio.h>
int main()
{
	int h1,m1,h2,m2,h3,m3;
	printf("请输入两个时间，较大的时间在前，如10 40表示10时40分\n");
	scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
	h3=h1-h2;
	m3=m1-m2;
	if(m3<0){
		m3=m3+60;
		h3--;
	}
	printf("时间差为%d时%d分",h3,m3);
	return 0;
}