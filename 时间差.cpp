#include<stdio.h>
int main()
{
	int h1,h2,m1,m2;
	printf("��ֱ���������ʱ�䣨xСʱx�֣����������� 5,30 ��Ϊ5Сʱ30�֣���������ϴ��ʱ��");
	scanf("%d,%d %d,%d",&h1,&m1,&h2,&m2);
	int num1,num2;
	num1=h1*60+m1;
	num2=h2*60+m2;
	int num3=num1-num2;
	printf("ʱ���Ϊ%dСʱ%d��",num3/60,num3%60);
	return 0;
 } 
